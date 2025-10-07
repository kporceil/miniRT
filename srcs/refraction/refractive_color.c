/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refractive_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:38:42 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/06 15:17:18 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include <math.h>

t_color	refracted_color(t_world world, t_precomp comps, size_t remaining)
{
	double	n_ratio;
	double	cos_i;
	double	cos_t;
	double	sin2_t;
	t_color	c;

	if (comps.obj->material.transparency == 0 || remaining == 0)
		return (color(0, 0, 0));
	n_ratio = comps.n1 / comps.n2;
	cos_i = dot(comps.eyev, comps.normalv);
	sin2_t = n_ratio * n_ratio * (1 - cos_i * cos_i);
	if (sin2_t > 1)
		return (color(0, 0, 0));
	cos_t = sqrt(1.0 - sin2_t);
	color_at(world, ray(comps.under_point, tuple_substract(tuple_scalar_mult
				(comps.normalv, n_ratio * cos_i - cos_t), tuple_scalar_mult
				(comps.eyev, n_ratio))), &c, remaining - 1);
	return (color_scalar_mult(c, comps.obj->material.transparency));
}
