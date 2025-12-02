/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:31:29 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/02 13:34:25 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bounding_box.h"

static void	check_axis(t_one_d_ray r, double *ret, double min, double max)
{
	const double	tmin_num = (min - r.origin);
	const double	tmax_num = (max - r.origin);
	double			tmin;
	double			tmax;

	if (fabs(r.dir) >= 0.0001)
	{
		tmin = tmin_num / r.dir;
		tmax = tmax_num / r.dir;
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

_Bool	bb_intersect(t_bounding_box b, t_ray r)
{
	double	xt[2];
	double	yt[2];
	double	zt[2];
	double	tmin;
	double	tmax;

	(void)b;
	check_axis((t_one_d_ray){r.origin.x, r.dir.x}, xt, b.min.x, b.max.x);
	check_axis((t_one_d_ray){r.origin.y, r.dir.y}, yt, b.min.y, b.max.y);
	check_axis((t_one_d_ray){r.origin.z, r.dir.z}, zt, b.min.z, b.max.z);
	tmin = fmax(fmax(xt[0], yt[0]), zt[0]);
	tmax = fmin(fmin(xt[1], yt[1]), zt[1]);
	if (tmin > tmax)
		return (false);
	return (true);
}
