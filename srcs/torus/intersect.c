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

static int	solve_quartic(double a, double b, double c, double d, double e,
		double *roots)
{
	double	p;
	double	q;
	double	r;
	double	disc;
	double	y;
	double	u;
	double	v;
	double	m;
	double	n;
	int		count;

	a = b / a;
	b = c / a;
	c = d / a;
	d = e / a;
	p = b - 3.0 * a * a / 8.0;
	q = a * a * a / 8.0 - a * b / 2.0 + c;
	r = -3.0 * a * a * a * a / 256.0 + a * a * b / 16.0 - a * c / 4.0 + d;
	if (fabs(r) < 1e-10)
	{
		disc = q * q - 4.0 * p * r;
		if (disc < 0)
			return (0);
		y = (-q + sqrt(disc)) / 2.0;
	}
	else
	{
		disc = q * q / 4.0 + r * (p * p - r) / 27.0;
		if (disc < 0)
			return (0);
		u = cbrt(-q / 2.0 + sqrt(disc));
		v = cbrt(-q / 2.0 - sqrt(disc));
		y = u + v - p / 3.0;
	}
	m = sqrt(2.0 * y - p);
	n = q / m;
	count = 0;
	disc = y - p / 2.0 - n;
	if (disc >= 0)
	{
		roots[count++] = (-a / 4.0) - m / 2.0 - sqrt(disc);
		roots[count++] = (-a / 4.0) - m / 2.0 + sqrt(disc);
	}
	disc = y - p / 2.0 + n;
	if (disc >= 0)
	{
		roots[count++] = (-a / 4.0) + m / 2.0 - sqrt(disc);
		roots[count++] = (-a / 4.0) + m / 2.0 + sqrt(disc);
	}
	return (count);
}

void	ray_torus_intersect(t_shape *s, t_ray r, t_intersections *inter)
{
	double const	rm = s->torus_major;
	double const	rn = s->torus_minor;
	double const	sum_sq = dot(r.origin, r.origin);
	double const	e = sum_sq - rm * rm - rn * rn;
	double const	f = dot(r.origin, r.dir);
	double const	four_sq_rm = 4.0 * rm * rm;
	double			coeffs[5];
	double			roots[4];
	int				num_roots;
	int				i;

	coeffs[0] = 1.0;
	coeffs[1] = 4.0 * f;
	coeffs[2] = 2.0 * sum_sq + 4.0 * f * f + e - four_sq_rm * (1.0 - r.dir.y
			* r.dir.y);
	coeffs[3] = 4.0 * f * e + 8.0 * four_sq_rm * r.origin.y * r.dir.y;
	coeffs[4] = e * e - four_sq_rm * (rn * rn - r.origin.y * r.origin.y);
	num_roots = solve_quartic(coeffs[0], coeffs[1], coeffs[2], coeffs[3],
			coeffs[4], roots);
	i = 0;
	while (i < num_roots)
	{
		if (roots[i] > 0)
			inter->inters[inter->size++] = (t_inter){s, roots[i]};
		i++;
	}
}
