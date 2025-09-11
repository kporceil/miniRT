/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:56:22 by kporceil          #+#    #+#             */
/*   Updated: 2025/09/11 14:56:40 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include <math.h>

t_intersect	ray_sphere_intersect(t_shape *s, t_ray r)
{
	t_tuple const			sphere_to_ray = (t_tuple){r.origin.x, r.origin.y,
		r.origin.z, 0};
	register double const	a = dot(r.dir, r.dir);
	register double const	b = 2.0 * dot(r.dir, sphere_to_ray);
	register double const	discriminant = b * b - 4.0 * a * (dot(sphere_to_ray,
				sphere_to_ray) - 1.0);
	double					opti[3];

	if (discriminant < 0)
		return ((t_intersect){0, {{s, 0}, {s, 0}}});
	opti[1] = sqrt(discriminant);
	opti[2] = 1.0 / (2.0 * a);
	opti[0] = (-b - opti[1]) * opti[2];
	if (discriminant == 0)
		return ((t_intersect){2, {{s, opti[0]}, {s, opti[0]}}});
	return ((t_intersect){2, {{s, opti[0]},
			{s, (-b + opti[1]) * opti[2]}}});
}
