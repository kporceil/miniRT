/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 22:33:34 by kporceil          #+#    #+#             */
/*   Updated: 2025/09/03 19:26:58 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "light.h"

#define EPS 0.0001

t_precomp	precompute(t_inter i, t_ray r)
{
	t_precomp	ret;

	ret.t = i.point;
	ret.obj = i.s;
	ret.point = ray_position(r, i.point);
	ret.eyev = tuple_negate(r.dir);
	ret.normalv = normal_at(*i.s, ret.point);
	ret.over_point = tuple_add(ret.point, tuple_scalar_mult(ret.normalv, EPS));
	ret.inside = false;
	if (dot(ret.normalv, ret.eyev) < 0)
	{
		ret.inside = true;
		ret.normalv = tuple_negate(ret.normalv);
	}
	return (ret);
}
