/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:31:22 by kporceil          #+#    #+#             */
/*   Updated: 2025/09/30 11:33:46 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "tuples.h"
#include "shape.h"

static t_tuple	local_cylinder_normal(t_shape cyl, t_tuple object_point)
{
	double const	dist = object_point.x * object_point.x + object_point.z * object_point.z;
	if (dist < 1)
	{
		if (object_point.y >= cyl.cyl_max - 0.0001)
			return (vector(0, 1, 0));
		else if (object_point.y <= cyl.cyl_min + 0.0001)
			return (vector(0, -1, 0));
	}
	return (vector(object_point.x, 0, object_point.z));
}

static t_tuple	local_object_normal(t_shape s, t_tuple object_point)
{
	if (s.type == SPHERE)
		return (tuple_substract(object_point, point(0, 0, 0)));
	if (s.type == PLANE)
		return (vector(0, 1, 0));
	if (s.type == CYLINDER)
		return (local_cylinder_normal(s, object_point));
	return (tuple_substract(object_point, point(0, 0, 0)));
}

t_tuple	normal_at(t_shape s, t_tuple p)
{
	t_tuple const	object_point = matrix_tuple_mult(s.inverted, p);
	t_tuple const	object_normal = local_object_normal(s, object_point);
	t_tuple			normal;

	normal = matrix_tuple_mult(matrix_transpose(s.inverted), object_normal);
	normal.w = 0;
	return (normalize(normal));
}
