/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:48:06 by kporceil          #+#    #+#             */
/*   Updated: 2025/12/09 15:18:55 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "scenes_parsing.h"
#include "libft.h"
#include <stdlib.h>

static int	parse_mandatory_value(char *file, char **endptr, t_shape *pl)
{
	t_tuple	pos;
	t_tuple	dir;
	t_color	rgb;

	if (parse_point(file, endptr, &pos) == -1)
		return (-1);
	file = *endptr;
	if (parse_normalized_vector(file, endptr, &dir) == -1)
		return (-1);
	file = *endptr;
	if (parse_color(file, endptr, &rgb) == -1)
		return (-1);
	*endptr = skip_space(*endptr);
	shape_set_matrix(pl, object_orientation(pos, dir, vector(0, 1, 0)));
	if (fabs(dir.y) > 0.9)
		shape_set_matrix(pl, object_orientation(pos, dir, vector(1, 0, 0)));
	pl->material.color = rgb;
	return (0);
}

#ifdef MANDATORY

static int	parse_bonus_value(char *file, char **endptr, t_shape *pl)
{
	(void)endptr;
	(void)pl;
	if (*skip_space(file) != '\0')
		return (-1);
	return (0);
}

#endif

#ifdef BONUS

static int	parse_bonus_value(char *file, char **endptr, t_shape *pl)
{
	if (*file == '\0')
		return (0);
	pl->material.reflective = ft_strtod(file, endptr);
	pl->material.transparency = ft_strtod(*endptr, endptr);
	pl->material.refractive_index = ft_strtod(*endptr, endptr);
	file = skip_space(*endptr);
	if (parse_texture(file, endptr, pl, planar_map) == -1)
		return (-1);
	file = *endptr;
	if (*file != '\0' && *skip_space(file) != '\0')
	{
		if (pl->material.pat.type == UV && pl->material.pat.uvpat.type == IMAGE)
			free(pl->material.pat.uvpat.file.canva);
		if (pl->material.normal_map.type == UV)
			free(pl->material.normal_map.uvpat.file.canva);
		return (-1);
	}
	return (0);
}

#endif

static int	parse_plane_value(char *file, t_world *world)
{
	char	*endptr;
	t_shape	pl;

	pl = plane(get_shape_id(world));
	if (parse_mandatory_value(file, &endptr, &pl) == -1)
		return (-1);
	file = endptr;
	if (parse_bonus_value(file, &endptr, &pl) == -1)
		return (-1);
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
