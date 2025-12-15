/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:04:43 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/29 19:25:50 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "camera.h"
# include "light.h"
# include "shape.h"
# include "ray.h"

typedef struct s_lightlist
{
	t_plight			light;
	struct s_lightlist	*next;
}				t_lightlist;

typedef struct s_shapelist
{
	t_shape				shape;
	struct s_shapelist	*next;
}				t_shapelist;

typedef struct s_world
{
	bool		had_cam;
	bool		had_ambient;
	t_camera	cam;
	t_shape		*objs;
	t_plight	*lights;
	size_t		objs_count;
	size_t		lights_count;
	t_color		ambient;
	t_inter		*buf_inter;
	t_lightlist	*tmp_light;
	t_shapelist	*tmp_obj;
}				t_world;

t_world			world_create(void);
t_intersections	world_intersect(t_world	world, t_ray r);
void			free_world(t_world *w);

#endif
