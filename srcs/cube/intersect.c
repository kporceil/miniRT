/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:57:48 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/26 16:44:59 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include <math.h>

static void	check_axis(double origin, double dir, double *ret)
{
	const double	tmin_num = (-1 - origin);
	const double	tmax_num = (1 - origin);
	double			tmin;
	double			tmax;

	if (fabs(dir) >= 0.0001)
	{
		tmin = tmin_num / dir;
		tmax = tmax_num / dir;
	}
	else
	{
		tmin = tmin_num * INFINITY;
		tmax = tmax_num * INFINITY;
	}
	ret[0] = tmin;
	ret[1] = tmax;
	if (tmin > tmax)
	{
		ret[0] = tmax;
		ret[1] = tmin;
	}
}

void	ray_cube_intersect(t_shape *s, t_ray r, t_intersections *xs)
{
	double	xt[2];
	double	yt[2];
	double	zt[2];
	double	tmin;
	double	tmax;

	check_axis(r.origin.x, r.dir.x, xt);
	check_axis(r.origin.y, r.dir.y, yt);
	check_axis(r.origin.z, r.dir.z, zt);
	tmin = fmax(fmax(xt[0], yt[0]), zt[0]);
	tmax = fmin(fmin(xt[1], yt[1]), zt[1]);
	if (tmin > tmax)
		return ;
	xs->inters[xs->size++] = (t_inter){.s = s, .point = tmin};
	xs->inters[xs->size++] = (t_inter){.s = s, .point = tmax};
}
