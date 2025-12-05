/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:47:44 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/29 19:34:48 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "scenes_parsing.h"
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
			matrix_scaling(diameter, diameter, diameter)));
	sp->material.color = rgb;
	return (0);
}

static int	parse_image_pattern(char *file, t_shape *sp)
{
	size_t	i;
	char	backup;
	t_canva	texture;

	i = 0;
	while (!ft_isspace(file[i]))
		++i;
	backup = file[i];
	file[i] = '\0';
	texture = ppm_to_canva(file);
	if (texture.canva == NULL)
		return (-1);
	file[i] = backup;
	sp->material.pat = texture_map(uv_image(texture), spherical_map);
	return (0);
}

static int	parse_bonus_value(char *file, char **endptr, t_shape *sp)
{
	if (*file == '\0')
		return (0);
	sp->material.reflective = ft_strtod(file, endptr);
	sp->material.transparency = ft_strtod(*endptr, endptr);
	sp->material.refractive_index = ft_strtod(*endptr, endptr);
	file = skip_space(*endptr);
	if (ft_strncmp("checker", file, 7) == 0)
		sp->material.pat = texture_map(
				uv_checkers(16, 8, sp->material.color, color(1, 1, 1)),
				spherical_map);
	else if (*file == 'T')
	{
		if (parse_image_pattern(file + 1, sp) == -1)
			return (-1);
	}
	while (*file != '\0' && !ft_isspace(*file))
		++file;
	if (*skip_space(file) != '\0')
	{
		if (sp->material.pat.type == UV && sp->material.pat.uvpat.type == IMAGE)
			free(sp->material.pat.uvpat.file.canva);
		return (-1);
	}
	return (0);
}

static int	parse_sphere_value(char *file, t_world *world)
{
	t_shape	sp;
	char	*endptr;

	sp = sphere(get_shape_id(world));
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
