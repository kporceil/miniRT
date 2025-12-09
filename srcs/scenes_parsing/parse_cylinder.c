/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:48:24 by kporceil          #+#    #+#             */
/*   Updated: 2025/12/09 15:38:35 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "scenes_parsing.h"
#include "libft.h"
#include <stdlib.h>

static int	parse_mandatory_value(char *file, char **endptr, t_shape *cy)
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
	shape_set_matrix(cy, matrix_mult(object_orientation(pos, dir,
				vector(0, 1, 0)), matrix_scaling(d_h[0], 1, d_h[0])));
	if (fabs(dir.y) > 0.9)
		shape_set_matrix(cy, matrix_mult(object_orientation(pos, dir,
					vector(1, 0, 0)), matrix_scaling(d_h[0], 1, d_h[0])));
	cy->material.color = rgb;
	cy->cyl_max = d_h[1] / 2.0;
	cy->cyl_min = -(d_h[1] / 2.0);
	return (0);
}

static int	parse_bonus_value(char *file, char **endptr, t_shape *cy)
{
	if (*file == '\0')
		return (0);
	cy->material.reflective = ft_strtod(file, endptr);
	cy->material.transparency = ft_strtod(*endptr, endptr);
	cy->material.refractive_index = ft_strtod(*endptr, endptr);
	file = skip_space(*endptr);
	if (parse_texture(file, endptr, cy, cylindrical_map) == -1)
		return (-1);
	file = *endptr;
	if (*skip_space(file) != '\0')
	{
		if (cy->material.pat.type == UV && cy->material.pat.uvpat.type == IMAGE)
			free(cy->material.pat.uvpat.file.canva);
		if (cy->material.normal_map.type == UV)
			free(cy->material.normal_map.uvpat.file.canva);
		return (-1);
	}
	return (0);
}

static int	parse_cylinder_value(char *file, t_world *world)
{
	char	*endptr;
	t_shape	cy;

	cy = cylinder(get_shape_id(world));
	cy.cyl_closed = true;
	if (parse_mandatory_value(file, &endptr, &cy) == -1)
		return (-1);
	file = skip_space(endptr);
	if (parse_bonus_value(file, &endptr, &cy) == -1)
		return (-1);
	if (new_shape_node(world, &cy) == -1)
		return (-1);
	return (0);
}

int	parse_cylinder(char *file, t_world *world)
{
	if (parse_cylinder_value(file, world) == -1)
		return (-1);
	++world->objs_count;
	return (0);
}
