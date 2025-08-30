/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:36:20 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/30 23:50:15 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "tuples.h"
# include "spheres.h"
# include "color.h"
# include "ray.h"

typedef struct s_plight
{
	t_tuple	pos;
	t_color	intensity;
}				t_plight;

typedef struct s_world t_world;

t_tuple		normal_at(t_sphere s, t_tuple p);
t_tuple		reflect(t_tuple in, t_tuple normal);
t_plight	point_light(t_tuple pos, t_color intensity);
t_color		lighting(t_material m, t_plight light, t_tuple point, t_tuple eye_nor[2]);
t_color		shade_hit(t_world world, t_precomp comps);
int			color_at(t_world w, t_ray r, t_color *c);

#endif
