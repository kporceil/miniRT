/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_caps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:11:04 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/02 13:59:33 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "ray.h"

static int	check_cap(t_ray r, double t)
{
	double const x	= r.origin.x + t * r.dir.x;
	double const z	= r.origin.z + t * r.dir.z;

	return ((x * x + z * z) <= 1);
}

void	intersect_caps(t_shape *cyl, t_ray r, t_intersections *xs)
{
	double	t;

	if (!cyl->cyl_closed || (-0.001 <= r.dir.y && r.dir.y <= 0.001))
		return ;
	t = (cyl->cyl_min - r.origin.y) / r.dir.y;
	if (check_cap(r, t))
		xs->inters[xs->size++] = (t_inter){cyl, t};
	t = (cyl->cyl_max - r.origin.y) / r.dir.y;
	if (check_cap(r, t))
		xs->inters[xs->size++] = (t_inter){cyl, t};
}
