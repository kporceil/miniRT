/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:47:44 by kporceil          #+#    #+#             */
/*   Updated: 2025/12/09 16:16:38 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "scenes_parsing.h"
#include "uid.h"
#include "libft.h"
#include <stdlib.h>

static int	parse_mandatory_value(char *file, char **endptr, t_shape *sp)
{
	t_tuple	pos;
	double	diameter;
	t_color	rgb;

	if (parse_point(file, endptr, &pos) == -1)
		return (-1);
	file = *endptr;
	diameter = ft_strtod(file, endptr);
	if (file == *endptr)
		return (-1);
	file = *endptr;
	if (parse_color(file, endptr, &rgb) == -1)
		return (-1);
	*endptr = skip_space(*endptr);
	shape_set_matrix(sp, matrix_mult(matrix_translation(pos.x, pos.y, pos.z),
			matrix_scaling(diameter / 2.0, diameter / 2.0, diameter / 2.0)));
	sp->material.color = rgb;
	return (0);
}

#ifdef BONUS

static int	parse_bonus_value(char *file, char **endptr, t_shape *sp)
{
	if (*file == '\0')
		return (0);
	sp->material.reflective = ft_strtod(file, endptr);
	sp->material.transparency = ft_strtod(*endptr, endptr);
	sp->material.refractive_index = ft_strtod(*endptr, endptr);
	file = skip_space(*endptr);
	if (parse_texture(file, endptr, sp, spherical_map) == -1)
		return (-1);
	file = *endptr;
	if (*skip_space(file) != '\0')
	{
		if (sp->material.pat.type == UV && sp->material.pat.uvpat.type == IMAGE)
			free(sp->material.pat.uvpat.file.canva);
		if (sp->material.normal_map.type == UV)
			free(sp->material.normal_map.uvpat.file.canva);
		return (-1);
	}
	return (0);
}

#endif

#ifdef MANDATORY

static int	parse_bonus_value(char *file, char **endptr, t_shape *sp)
{
	(void)endptr;
	(void)sp;
	if (*skip_space(file) != '\0')
		return (-1);
	return (0);
}

#endif

static int	parse_sphere_value(char *file, t_world *world)
{
	t_shape	sp;
	char	*endptr;

	sp = sphere(generate_uid());
	if (parse_mandatory_value(file, &endptr, &sp) == -1)
		return (-1);
	file = endptr;
	if (parse_bonus_value(file, &endptr, &sp) == -1)
		return (-1);
	if (new_shape_node(world, &sp) == -1)
		return (-1);
	return (0);
}

int	parse_sphere(char *file, t_world *world)
{
	if (parse_sphere_value(file, world) == -1)
		return (-1);
	++world->objs_count;
	return (0);
}
