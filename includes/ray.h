/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:20:40 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/28 23:33:21 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "tuples.h"
# include "spheres.h"
# include "matrix.h"

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}				t_ray;

typedef struct s_inter
{
	t_sphere	*s;
	double		point;
}				t_inter;

typedef struct s_intersect
{
	int		count;
	t_inter	object[2];
}				t_intersect;

t_ray		ray(t_tuple origin, t_tuple direction);
t_tuple		ray_position(t_ray r, double t);
t_intersect	ray_intersect(t_sphere *s, t_ray r);
t_inter		*inter_hit(t_intersect *intersect, size_t size);
t_ray		ray_transform(t_ray r, t_matrix m);

#endif
