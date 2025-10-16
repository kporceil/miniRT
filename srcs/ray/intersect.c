/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 22:06:03 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/08 12:57:03 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "ray.h"

void	ray_intersect(t_shape *s, t_ray r, t_intersections *inter)
{
	if (s->type == SPHERE)
		ray_sphere_intersect(s, ray_transform(&r, &s->inverted), inter);
	if (s->type == PLANE)
		ray_plane_intersect(s, ray_transform(&r, &s->inverted), inter);
	if (s->type == CYLINDER)
		ray_cylinder_intersect(s, ray_transform(&r, &s->inverted), inter);
	if (s->type == CONE)
		ray_cone_intersect(s, ray_transform(&r, &s->inverted), inter);
	if (s->type == CUBE)
		ray_cube_intersect(s, ray_transform(&r, &s->inverted), inter);
	if (s->type == TORUS)
		ray_torus_intersect(s, ray_transform(&r, &s->inverted), inter);
}
