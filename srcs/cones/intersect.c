/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:56:22 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/06 17:21:05 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "cone_caps.h"
#include "equation.h"
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

void	ray_cone_intersect(t_shape *cone, t_ray r, t_intersections *inter)
{
	t_equation			eq;
	register double const	a = r.dir.x * r.dir.x - r.dir.y * r.dir.y + r.dir.z * r.dir.z;
	register double			b;
	register double			disc;
	double					t0;
	double					t1;

	eq = (t_equation){.a = r.dir.x * r.dir.x - r.dir.y * r.dir.y + r.dir.z
		* r.dir.z,
	.b = 2 * r.origin.x * r.dir.x - 2 * r.origin.y * r.dir.y + 2 * r.origin.z
		* r.dir.z,
	.c = r.origin.x * r.origin.x - r.origin.y * r.origin.y + r.origin.z
		* r.origin.z};
	if (-0.001 <= eq.a && eq.a <= 0.001)
	{
		if (-0.001 <= eq.b && eq.b <= 0.001)
			return (intersect_cone_caps(cone, r, inter));
		inter->inters[inter->size++] = (t_inter){cone, - eq.c / (2 * eq.b)};
		return (intersect_cone_caps(cone, r, inter));
	}
	eq.disc = eq.b * eq.b - 4 * eq.a * eq.c;
	if (eq.disc >= 0)
	{
		t0 = (- b - sqrt(disc)) / (2 * a);
		t1 = (- b + sqrt(disc)) / (2 * a);
		if (t0 > t1)
			double_swap(&t0, &t1);
		if (is_between(cone->cyl_min, r.origin.y + t0 * r.dir.y, cone->cyl_max))
			inter->inters[inter->size++] = (t_inter){cone, t0};
		if (is_between(cone->cyl_min, r.origin.y + t1 * r.dir.y, cone->cyl_max))
			inter->inters[inter->size++] = (t_inter){cone, t1};
	}
	intersect_cone_caps(cone, r, inter);
}
