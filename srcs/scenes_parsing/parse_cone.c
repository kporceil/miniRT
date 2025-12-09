/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:48:58 by kporceil          #+#    #+#             */
/*   Updated: 2025/12/09 15:36:36 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "scenes_parsing.h"
#include "libft.h"
#include <stdlib.h>

static int	parse_mandatory_value(char *file, char **endptr, t_shape *co)
{
	t_tuple	pos;
	t_tuple	dir;
	double	d_h[2];
	t_color	rgb;

	if (parse_point(file, endptr, &pos) == -1)
		return (-1);
	if (parse_normalized_vector(*endptr, endptr, &dir) == -1)
		return (-1);
	d_h[0] = ft_strtod(*endptr, endptr);
	file = *endptr;
	d_h[1] = ft_strtod(file, endptr);
	if (file == *endptr)
		return (-1);
	if (parse_color(*endptr, endptr, &rgb) == -1)
		return (-1);
	shape_set_matrix(co, matrix_mult(object_orientation(pos, dir,
				vector(0, 1, 0)), matrix_scaling(d_h[0], 1, d_h[0])));
	if (fabs(dir.y) > 0.9)
		shape_set_matrix(co, matrix_mult(object_orientation(pos, dir,
					vector(1, 0, 0)), matrix_scaling(d_h[0], 1, d_h[0])));
	co->material.color = rgb;
	co->cyl_max = d_h[1] / 2.0;
	co->cyl_min = -(d_h[1] / 2.0);
	return (0);
}

static int	parse_bonus_value(char *file, char **endptr, t_shape *co)
{
	if (*file == '\0')
		return (0);
	co->material.reflective = ft_strtod(file, endptr);
	co->material.transparency = ft_strtod(*endptr, endptr);
	co->material.refractive_index = ft_strtod(*endptr, endptr);
	file = skip_space(*endptr);
	if (parse_texture(file, endptr, co, conical_map) == -1)
		return (-1);
	file = *endptr;
	if (*skip_space(file) != '\0')
	{
		if (co->material.pat.type == UV && co->material.pat.uvpat.type == IMAGE)
			free(co->material.pat.uvpat.file.canva);
		if (co->material.normal_map.type == UV)
			free(co->material.normal_map.uvpat.file.canva);
		return (-1);
	}
	return (0);
}

static int	parse_cone_value(char *file, t_world *world)
{
	char	*endptr;
	t_shape	co;

	co = cone(get_shape_id(world));
	co.cyl_closed = true;
	if (parse_mandatory_value(file, &endptr, &co) == -1)
		return (-1);
	file = skip_space(endptr);
	if (parse_bonus_value(file, &endptr, &co) == -1)
		return (-1);
	if (new_shape_node(world, &co) == -1)
		return (-1);
	return (0);
}

int	parse_cone(char *file, t_world *world)
{
	if (parse_cone_value(file, world) == -1)
		return (-1);
	++world->objs_count;
	return (0);
}
