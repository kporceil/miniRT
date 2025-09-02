/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 22:06:03 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/29 00:00:39 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "spheres.h"
#include "tuples.h"
#include "ray.h"
#include <math.h>

t_intersect	ray_intersect(t_sphere *s, t_ray r)
{
	t_tuple	const sphere_to_ray = (t_tuple){r.origin.x, r.origin.y, r.origin.z, 0};
	register double const	a = dot(r.dir, r.dir);
	register double const	b = 2.0 * dot(r.dir, sphere_to_ray);
	register double const	discriminant = b * b - 4.0 * a * (dot(sphere_to_ray, sphere_to_ray) - 1.0);
	register double			t1;
	register double			sqrt_disc;
	register double			inv_2a;

	if (discriminant < 0)
		return ((t_intersect){0, {{s, 0}, {s, 0}}});
	sqrt_disc = sqrt(discriminant);
	inv_2a = 1.0 / (2.0 * a);
	t1 = (-b - sqrt_disc) * inv_2a;
	if (discriminant == 0)
		return ((t_intersect){2, {{s, t1}, {s, t1}}});
	return ((t_intersect){2, {{s, t1},
			{s, (-b + sqrt_disc) * inv_2a}}});
}
