/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:20:40 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/02 17:20:32 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "tuples.h"
# include "shape.h"

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	dir;
}				t_ray;

typedef struct s_inter
{
	t_shape	*s;
	double		point;
}				t_inter;

typedef struct s_intersections
{
	t_inter	*inters;
	size_t		size;
}				t_intersections;

typedef struct s_precomp
{
	t_shape	*obj;
	t_tuple		point;
	t_tuple		over_point;
	t_tuple		eyev;
	t_tuple		normalv;
	double		t;
	bool		inside;
}				t_precomp;

t_ray		ray(t_tuple origin, t_tuple direction);
t_tuple		ray_position(t_ray r, double t);
void	ray_sphere_intersect(t_shape *s, t_ray r, t_intersections *inter)__attribute__((hot));
void	ray_plane_intersect(t_shape *s, t_ray r, t_intersections *inter)__attribute__((hot));
void	ray_cylinder_intersect(t_shape *s, t_ray r, t_intersections *inter);
void	ray_cone_intersect(t_shape *s, t_ray r, t_intersections *inter);
void	ray_intersect(t_shape *s, t_ray r, t_intersections *inter);
t_inter		*inter_hit(t_inter *intersect, size_t size);
t_ray		ray_transform(t_ray *r, t_matrix *m)__attribute__((hot));
t_precomp	precompute(t_inter i, t_ray r);

#endif
