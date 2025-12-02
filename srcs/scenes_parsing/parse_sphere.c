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

static int	parse_sphere_value(char *file, t_world *world)
{
	t_tuple	pos;
	double	diameter;
	t_color	rgb;
	char	*endptr;
	t_shape	sp;

	if (parse_point(file, &endptr, &pos) == -1)
		return (-1);
	file = endptr;
	diameter = ft_strtod(file, &endptr);
	if (file == endptr)
		return (-1);
	file = endptr;
	if (parse_color(file, &endptr, &rgb) == -1)
		return (-1);
	sp = sphere(get_shape_id(world));
	shape_set_matrix(&sp, matrix_mult(matrix_translation(pos.x, pos.y, pos.z),
			matrix_scaling(diameter, diameter, diameter)));
	sp.material.color = rgb;
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
