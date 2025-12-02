/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:48:06 by kporceil          #+#    #+#             */
/*   Updated: 2025/12/02 22:02:07 by kporceil         ###   ########lyon.fr   */
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

static int	parse_plane_value(char *file, t_world *world)
{
	t_tuple	pos;
	t_tuple	dir;
	t_color	rgb;
	char	*endptr;
	t_shape	pl;

	if (parse_point(file, &endptr, &pos) == -1)
		return (-1);
	file = endptr;
	if (parse_normalized_vector(file, &endptr, &dir) == -1)
		return (-1);
	file = endptr;
	if (parse_color(file, &endptr, &rgb) == -1)
		return (-1);
	file = skip_space(endptr);
	if (*file != '\0')
		return (-1);
	pl = plane(get_shape_id(world));
	shape_set_matrix(&pl, object_orientation(pos, dir, vector(0, 1, 0)));
	if (fabs(dir.y) > 0.9)
		shape_set_matrix(&pl, object_orientation(pos, dir, vector(1, 0, 0)));
	pl.material.color = rgb;
	if (new_shape_node(world, &pl) == -1)
		return (-1);
	return (0);
}

int	parse_plane(char *file, t_world *world)
{
	if (parse_plane_value(file, world) == -1)
		return (-1);
	++world->objs_count;
	return (0);
}
