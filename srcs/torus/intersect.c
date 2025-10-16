/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:50:00 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/16 15:50:00 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include <math.h>

static int	solve_quadratic(double a, double b, double c, double *t0,
		double *t1)
{
	double const	disc = b * b - 4.0 * a * c;

	if (disc < 0)
		return (0);
	if (fabs(a) < 1e-10)
	{
		if (fabs(b) < 1e-10)
			return (0);
		*t0 = -c / b;
		return (1);
	}
	*t0 = (-b - sqrt(disc)) / (2.0 * a);
	*t1 = (-b + sqrt(disc)) / (2.0 * a);
	return (2);
}

static int	solve_quartic(double c4, double c3, double c2, double c1,
		double c0, double *roots)
{
	double	z;
	double	u;
	double	v;
	double	sub;
	double	a;
	double	b;
	double	p;
	double	q;
	double	d;
	double	t[2];
	int		n;
	int		count;

	sub = c3 / (4.0 * c4);
	a = (c2 / c4) - 6.0 * sub * sub;
	b = (c1 / c4) + (8.0 * sub * sub * sub) - (2.0 * sub * c2 / c4);
	p = (c0 / c4) - (3.0 * sub * sub * sub * sub) + (sub * c2 / c4) - (sub * c1
			/ c4);
	if (fabs(b) < 1e-10)
	{
		n = solve_quadratic(1.0, a, p, &t[0], &t[1]);
		count = 0;
		while (count < n && count < 2)
		{
			if (t[count] >= 0)
			{
				u = sqrt(t[count]);
				roots[n * 2] = u - sub;
				roots[n * 2 + 1] = -u - sub;
				n += 2;
			}
			count++;
		}
		return (n);
	}
	q = a * a - 4.0 * p;
	d = a * a * a - 4.0 * a * p - b * b;
	if (fabs(d) < 1e-6 || q < 0)
		return (0);
	z = sqrt(q);
	u = (a - z) / 2.0;
	v = (a + z) / 2.0;
	count = 0;
	n = solve_quadratic(1.0, z, u, &t[0], &t[1]);
	if (n > 0)
		roots[count++] = t[0] - sub;
	if (n > 1)
		roots[count++] = t[1] - sub;
	n = solve_quadratic(1.0, -z, v, &t[0], &t[1]);
	if (n > 0)
		roots[count++] = t[0] - sub;
	if (n > 1)
		roots[count++] = t[1] - sub;
	return (count);
}

void	ray_torus_intersect(t_shape *s, t_ray r, t_intersections *inter)
{
	double const	rm = s->torus_major;
	double const	rn = s->torus_minor;
	double const	ox_sq = r.origin.x * r.origin.x;
	double const	oy_sq = r.origin.y * r.origin.y;
	double const	oz_sq = r.origin.z * r.origin.z;
	double const	sum_sq = ox_sq + oy_sq + oz_sq;
	double const	e = sum_sq - rm * rm - rn * rn;
	double const	f = dot(r.origin, r.dir);
	double const	four_rm_sq = 4.0 * rm * rm;
	double			roots[4];
	int				num_roots;
	int				i;

	num_roots = solve_quartic(1.0, 4.0 * f, 2.0 * sum_sq + 4.0 * f * f + e
			- four_rm_sq * (1.0 - r.dir.y * r.dir.y), 4.0 * f * e + 8.0
			* four_rm_sq * r.origin.y * r.dir.y, e * e - four_rm_sq * (rn * rn
				- oy_sq), roots);
	i = 0;
	while (i < num_roots)
	{
		if (roots[i] > 1e-6)
			inter->inters[inter->size++] = (t_inter){s, roots[i]};
		i++;
	}
}
