/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:48:58 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/27 16:49:10 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "scenes_parsing.h"
#include "libft.h"

static char	*skip_space(char *str)
{
	while (ft_isspace(*str))
		++str;
	return (str);
}

static int	parse_cone_value(char *file, t_world *world)
{
	t_tuple	pos;
	t_tuple	dir;
	double	diam_height[2];
	t_color	rgb;
	char	*endptr;
	t_shape	co;

	if (parse_point(file, &endptr, &pos) == -1)
		return (-1);
	file = endptr;
	if (parse_normalized_vector(file, &endptr, &dir) == -1)
		return (-1);
	file = endptr;
	diam_height[0] = ft_strtod(file, &endptr);
	if (file == endptr)
		return (-1);
	file = endptr;
	diam_height[1] = ft_strtod(file, &endptr);
	if (file == endptr)
		return (-1);
	file = endptr;
	if (parse_color(file, &endptr, &rgb) == -1)
		return (-1);
	file = skip_space(endptr);
	if (*file != '\0')
		return (-1);
	co = cone(get_shape_id(world));
	shape_set_matrix(&co, matrix_mult(object_orientation(pos, dir, vector(0, 1, 0)),matrix_scaling(diam_height[0], 1, diam_height[0])));
	if (fabs(dir.y) > 0.9)
		shape_set_matrix(&co, matrix_mult(object_orientation(pos, dir, vector(1, 0, 0)),matrix_scaling(diam_height[0], 1, diam_height[0])));
	co.material.color = rgb;
	co.cyl_closed = true;
	co.cyl_max = diam_height[1] / 2;
	co.cyl_min = - (diam_height[1] / 2);
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
