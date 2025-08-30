/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 22:33:34 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/30 22:46:46 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "light.h"

t_precomp	precompute(t_inter i, t_ray r)
{
	t_precomp	ret;

	ret.t = i.point;
	ret.obj = i.s;
	ret.point = ray_position(r, i.point);
	ret.eyev = tuple_negate(r.direction);
	ret.normalv = normal_at(*i.s, ret.point);
	ret.inside = false;
	if (dot(ret.normalv, ret.eyev) < 0)
	{
		ret.inside = true;
		ret.normalv = tuple_negate(ret.normalv);
	}
	return (ret);
}
