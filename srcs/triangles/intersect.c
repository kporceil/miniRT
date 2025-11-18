/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:58:50 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/17 13:21:08 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ray.h"
#include "tuples.h"

// NOTE: implementation from this detailed ray / triangle intersection
// algorithm : 
//
// https://sci-hub.se/https://doi.org/10.1080/10867651.1997.10487468

void	ray_triangle_intersect(t_shape *tri, t_ray r, t_intersections *xs)
{
	t_tuple const	dir_cross_e2 = cross(r.dir, tri->tri_e2);
	t_tuple			p1_to_origin;
	t_tuple			origin_cross_e1;
	double const	det = dot(tri->tri_e1, dir_cross_e2);
	double			det_inv;
	double			u;
	double			v;

	if (fabs(det) < 0.0001)
		return ;
	det_inv = 1.0 / det;
	p1_to_origin = tuple_substract(r.origin, tri->tri_p1);
	u = det_inv * dot(p1_to_origin, dir_cross_e2);
	if (u < 0 || u > 1)
		return ;
	origin_cross_e1 = cross(p1_to_origin, tri->tri_e1);
	v = det_inv * dot(r.dir, origin_cross_e1);
	if (v < 0 || (u + v) > 1)
		return ;
	xs->inters[xs->size++] = (t_inter){tri, det_inv * dot(tri->tri_e2, origin_cross_e1)};
}
