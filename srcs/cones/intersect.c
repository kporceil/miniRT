/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:56:22 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/26 16:46:08 by lcesbron         ###   ########lyon.fr   */
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

static void	put_solutions(t_equation eq, t_intersections *inter, t_ray r,
		t_shape *co)
{
	double	t0;
	double	t1;

	t0 = (-eq.b - sqrt(eq.disc)) / (2 * eq.a);
	t1 = (-eq.b + sqrt(eq.disc)) / (2 * eq.a);
	if (t0 > t1)
		double_swap(&t0, &t1);
	if (is_between(co->cyl_min, r.origin.y + t0 * r.dir.y, co->cyl_max))
		inter->inters[inter->size++] = (t_inter){.s = co, .point = t0};
	if (is_between(co->cyl_min, r.origin.y + t1 * r.dir.y, co->cyl_max))
		inter->inters[inter->size++] = (t_inter){.s = co, .point = t1};
}

void	ray_cone_intersect(t_shape *co, t_ray r, t_intersections *inter)
{
	t_equation	eq;

	eq = (t_equation){.a = r.dir.x * r.dir.x - r.dir.y * r.dir.y + r.dir.z
		* r.dir.z,
		.b = 2 * r.origin.x * r.dir.x - 2 * r.origin.y * r.dir.y + 2
		* r.origin.z
		* r.dir.z,
		.c = r.origin.x * r.origin.x - r.origin.y * r.origin.y + r.origin.z
		* r.origin.z};
	if (fabs(eq.a) == 0)
	{
		if (fabs(eq.b) == 0)
			return (intersect_cone_caps(co, r, inter));
		inter->inters[inter->size++] = (t_inter){.s = co,
			.point = -eq.c / (2 * eq.b)};
		return (intersect_cone_caps(co, r, inter));
	}
	eq.disc = eq.b * eq.b - 4 * eq.a * eq.c;
	if (eq.disc >= 0)
		put_solutions(eq, inter, r, co);
	intersect_cone_caps(co, r, inter);
}
