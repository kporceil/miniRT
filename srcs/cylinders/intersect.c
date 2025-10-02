/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:56:22 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/02 13:59:34 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "caps.h"
#include <math.h>

static int	is_between(double min, double a, double max)
{
	return (min < a && a < max);
}

static void	double_swap(double *i1, double *i2)
{
	double const	buf = *i1;

	*i1 = *i2;
	*i2 = buf;
}

// NOTE: disc = b^2 - 4ac line is a bit wanky. For optimisation we dont need c
// to be stored in a variable.

void	ray_cylinder_intersect(t_shape *cyl, t_ray r, t_intersections *inter)
{
	register double const	a = r.dir.x * r.dir.x + r.dir.z * r.dir.z;
	register double			b;
	register double			disc;
	double					t0;
	double					t1;

	if (-0.001 <= a && a <= 0.001)
		return (intersect_caps(cyl, r, inter));
	b = 2 * r.origin.x * r.dir.x + 2 * r.origin.z * r.dir.z;
	disc = b * b - 4 * a * (r.origin.x * r.origin.x + r.origin.z * r.origin.z - 1);
	if (disc >= 0)
	{
		t0 = (- b - sqrt(disc)) / (2 * a);
		t1 = (- b + sqrt(disc)) / (2 * a);
		if (t0 > t1)
			double_swap(&t0, &t1);
		if (is_between(cyl->cyl_min, r.origin.y + t0 * r.dir.y, cyl->cyl_max))
			inter->inters[inter->size++] = (t_inter){cyl, t0};
		if (is_between(cyl->cyl_min, r.origin.y + t1 * r.dir.y, cyl->cyl_max))
			inter->inters[inter->size++] = (t_inter){cyl, t1};
	}
	intersect_caps(cyl, r, inter);
}
