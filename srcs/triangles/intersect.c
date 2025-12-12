/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:58:50 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/26 16:43:47 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ray.h"
#include "tuples.h"

// NOTE: implementation from this detailed ray / triangle intersection
// algorithm : 
//
// https://sci-hub.se/https://doi.org/10.1080/10867651.1997.10487468

static double	calculate_inv_det(t_shape *tri, t_tuple dir_cross_e2)
{
	double const	det = dot(tri->tri_e1, dir_cross_e2);

	if (fabs(det) < 0.0001)
		return (0);
	return (1.0 / det);
}

#include <stdio.h>

void	ray_triangle_intersect(t_shape *tri, t_ray r, t_intersections *xs)
{
	t_tuple	p1_to_origin;
	t_tuple	cross_buffer;
	double	det_inv;
	double	u;
	double	v;

	//if (tri->parent)
	//{
	//	printf("%zu\n", tri->parent->id);
	//}
	cross_buffer = cross(r.dir, tri->tri_e2);
	det_inv = calculate_inv_det(tri, cross_buffer);
	if (det_inv == 0)
		return ;
	p1_to_origin = tuple_substract(r.origin, tri->tri_p1);
	u = det_inv * dot(p1_to_origin, cross_buffer);
	if (u < 0 || u > 1)
		return ;
	cross_buffer = cross(p1_to_origin, tri->tri_e1);
	v = det_inv * dot(r.dir, cross_buffer);
	if (v < 0 || (u + v) > 1)
		return ;
	xs->inters[xs->size++] = (t_inter)
	{tri, det_inv * dot(tri->tri_e2, cross_buffer), u, v};
}
