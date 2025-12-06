/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:31:22 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/27 18:07:36 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "tuples.h"
#include "shape.h"
#include "ray.h"
#include <math.h>

static t_tuple	local_cylinder_normal(t_shape cyl, t_tuple object_point)
{
	double const	dist = object_point.x * object_point.x
		+ object_point.z * object_point.z;

	if (dist < 1)
	{
		if (object_point.y >= cyl.cyl_max - 0.0001)
			return (vector(0, 1, 0));
		else if (object_point.y <= cyl.cyl_min + 0.0001)
			return (vector(0, -1, 0));
	}
	return (vector(object_point.x, 0, object_point.z));
}

static t_tuple	local_cone_normal(t_shape co, t_tuple object_point)
{
	double const	dist = sqrt(object_point.x * object_point.x
			+ object_point.z * object_point.z);
	double			y;

	if (dist < fabs(co.cyl_min) || dist < fabs(co.cyl_max))
	{
		if (object_point.y >= co.cyl_max - 0.0001)
			return (vector(0, 1, 0));
		else if (object_point.y <= co.cyl_min + 0.0001)
			return (vector(0, -1, 0));
	}
	y = sqrt(object_point.x * object_point.x + object_point.z * object_point.z);
	if (object_point.y > 0)
		y = -y;
	return (vector(object_point.x, y, object_point.z));
}

static t_tuple	local_cube_normal(t_tuple p)
{
	const double	maxc = fmax(fmax(fabs(p.x), fabs(p.y)), fabs(p.z));

	if (fabs(fabs(p.x) - maxc) < 0.0001)
		return (vector(p.x, 0, 0));
	if (fabs(fabs(p.y) - maxc) < 0.0001)
		return (vector(0, p.y, 0));
	return (vector(0, 0, p.z));
}

static t_tuple	local_object_normal(t_shape s, t_tuple object_point, t_inter *i)
{
	if (s.type == SPHERE)
		return (tuple_substract(object_point, point(0, 0, 0)));
	if (s.type == PLANE)
		return (vector(0, 1, 0));
	if (s.type == CYLINDER)
		return (local_cylinder_normal(s, object_point));
	if (s.type == CONE)
		return (local_cone_normal(s, object_point));
	if (s.type == CUBE)
		return (local_cube_normal(object_point));
	if (s.type == TRIANGLE)
		return (s.tri_normal);
	if (s.type == SMOOTH_TRIANGLE)
		return (tuple_add(tuple_add(tuple_scalar_mult(s.tri_n2, i->u),
					tuple_scalar_mult(s.tri_n3, i->v)),
				tuple_scalar_mult(s.tri_n1, (1 - i->u - i-> v))));
	return (tuple_substract(object_point, point(0, 0, 0)));
}

t_tuple	normal_at(t_shape s, t_tuple p, t_inter *i)
{
	t_tuple const	object_point = matrix_tuple_mult(s.final_inverted, p);
	t_tuple const	object_normal = local_object_normal(s, object_point, i);
	t_tuple			normal;

	normal = matrix_tuple_mult(matrix_transpose(s.final_inverted),
			object_normal);
	normal.w = 0;
	return (normalize(normal));
}
