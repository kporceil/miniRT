/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   schlick.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 20:45:50 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/07 21:05:43 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include <math.h>

double	schlick(t_precomp comps)
{
	double			cos;
	double			n;
	double			sin2_t;
	double			r0;
	double			x;

	cos = dot(comps.eyev, comps.normalv);
	if (comps.n1 > comps.n2)
	{
		n = comps.n1 / comps.n2;
		sin2_t = n * n * (1 - cos * cos);
		if (sin2_t > 1)
			return (1);
		cos = sqrt(1 - sin2_t);
	}
	r0 = (comps.n1 - comps.n2) / (comps.n1 + comps.n2);
	r0 *= r0;
	x = 1 - cos;
	return (r0 + (1 - r0) * x * x * x * x * x);
}
