/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:36:20 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/26 18:18:26 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "tuples.h"
# include "shape.h"
# include "color.h"
# include "ray.h"

typedef struct s_plight
{
	t_tuple	pos;
	t_color	intensity;
}				t_plight;

typedef struct s_lighting
{
	t_material	m;
	t_plight	light;
	t_tuple		p;
	t_tuple		eyev;
	t_tuple		normalv;
	t_tuple		lightv;
	t_color		eff_color;
	t_shape		*obj;
	double		light_dot_norm;
	double		ref_dot_eye;
	double		factor;
	bool		in_shadow;
}				t_lighting;

typedef struct s_shadow
{
	t_tuple			v_to_light;
	t_tuple			direction;
	t_ray			r;
	t_intersections	inters;
	t_inter			*hit_point;
	double			distance;
	size_t			i;
}				t_shadow;

typedef struct s_world	t_world;

t_tuple		normal_at(t_shape s, t_tuple p, t_inter *i);
t_tuple		reflect(t_tuple in, t_tuple normal);
t_plight	point_light(t_tuple pos, t_color intensity);
t_color		lighting(t_lighting data);
t_color		shade_hit(t_world world, t_precomp comps, size_t remaining);
int			color_at(t_world w, t_ray r, t_color *c, size_t remaining);
bool		is_shadowed(t_world w, t_tuple p, size_t i);
t_color		reflected_color(t_world world, t_precomp comps, size_t remaining);

#endif
