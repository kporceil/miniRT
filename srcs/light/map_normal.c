/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:03:07 by kporceil          #+#    #+#             */
/*   Updated: 2025/12/09 13:12:06 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"
#include "shape.h"
#include "light.h"

t_tuple	map_normal(t_shape *sh, t_tuple o_p, t_tuple o_n)
{
	t_tuple	t;
	t_tuple	b;
	t_tuple	normal_from_map;
	t_tuple	perturbed_normal;
	t_color	map_color;

	if (sh->material.normal_map.type != UV)
		return (o_n);
	map_color = uv_pattern_at_point(sh->material.normal_map, o_p);
	normal_from_map = vector(
			map_color.red * 2.0 - 1.0,
			map_color.green * 2.0 - 1.0,
			map_color.blue * 2.0 - 1.0
			);
	normal_from_map = normalize(normal_from_map);
	compute_tbn(sh, o_p, o_n, (t_tuple *[2]){&t, &b});
	perturbed_normal = tuple_add(
			tuple_add(
				tuple_scalar_mult(t, normal_from_map.x),
				tuple_scalar_mult(b, normal_from_map.y)
				),
			tuple_scalar_mult(o_n, normal_from_map.z)
			);
	return (normalize(perturbed_normal));
}
