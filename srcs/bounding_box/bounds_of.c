/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounds_of.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:15:29 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/02 11:24:40 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bounding_box.h"

static t_bounding_box	bounds_of_cone(t_shape *cone)
{
	double const	a = fabs(cone->cyl_min);
	double const	b = fabs(cone->cyl_max);
	double			limit;

	if (a > b)
		limit = a;
	else
		limit = b;
	return ((t_bounding_box){.min = point(-limit, cone->cyl_min, -limit),
							.max = point(limit, cone->cyl_max, limit)});
}

static t_bounding_box	bounds_of_triangle(t_shape *triangle)
{
	t_bounding_box	ret;

	ret = bounding_box(0, (t_tuple){0}, (t_tuple){0});
	bb_add_point(&ret, triangle->tri_p1);
	bb_add_point(&ret, triangle->tri_p2);
	bb_add_point(&ret, triangle->tri_p3);
	return (ret);
}

static t_bounding_box	bounds_of_group(t_shape *g)
{
	t_bounding_box	ret;
	t_bounding_box	buf;
	size_t			i;

	ret = bounding_box(false, (t_tuple){0}, (t_tuple){0});
	i = 0;
	while (i < g->nb_members)
	{
		buf = bb_parent_space_bounds_of(g->child + i);
		bb_add(&ret, buf);
		++i;
	}
	return (ret);
}

t_bounding_box	bb_bounds_of(t_shape s)
{
	if (s.type == SPHERE || s.type == CUBE)
	{
		return ((t_bounding_box){.min = point(-1, -1, -1),
			.max = point(1, 1, 1)});
	}
	if (s.type == PLANE)
	{
		return ((t_bounding_box){.min = point(-INFINITY, 0, -INFINITY),
			.max = point(INFINITY, 0, INFINITY)});
	}
	if (s.type == CYLINDER)
	{
		return ((t_bounding_box){.min = point(-1, s.cyl_min, -1),
			.max = point(1, s.cyl_max, 1)});
	}
	if (s.type == CONE)
		return (bounds_of_cone(&s));
	if (s.type == TRIANGLE || s.type == SMOOTH_TRIANGLE)
		return (bounds_of_triangle(&s));
	if (s.type == GROUP)
		return (bounds_of_group(&s));
	return (bounding_box(false, (t_tuple){0}, (t_tuple){0}));
}
