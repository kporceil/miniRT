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
	t_tuple	sphere_to_ray;
	double	a;
	double	b;
	double	discriminant;
	double	t1;

	r = ray_transform(r, s->inverted);
	sphere_to_ray = tuple_substract(r.origin, point(0, 0, 0));
	a = dot(r.direction, r.direction);
	b = 2 * dot(r.direction, sphere_to_ray);
	discriminant = b * b - 4 * a * (dot(sphere_to_ray, sphere_to_ray) - 1);
	if (discriminant < 0)
		return ((t_intersect){0, {{s, 0}, {s, 0}}});
	t1 = (-b - sqrt(discriminant)) / (2 * a);
	if (discriminant == 0)
		return ((t_intersect){2, {{s, t1}, {s, t1}}});
	return ((t_intersect){2, {{s, t1},
			{s, (-b + sqrt(discriminant)) / (2 * a)}}});
}
