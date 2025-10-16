/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:31:22 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/08 15:26:19 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "tuples.h"
#include "shape.h"
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

static t_tuple	local_torus_normal(t_shape s, t_tuple p)
{
	double const	rm = s.torus_major;
	double const	sum_sq = p.x * p.x + p.z * p.z;
	double const	factor = 1.0 - rm / sqrt(sum_sq);

	return (vector(p.x * factor, p.y, p.z * factor));
}

static t_tuple	local_object_normal(t_shape s, t_tuple object_point)
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
	if (s.type == TORUS)
		return (local_torus_normal(s, object_point));
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
