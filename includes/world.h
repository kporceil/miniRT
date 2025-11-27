/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:04:43 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/27 16:58:22 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "camera.h"
# include "light.h"
# include "shape.h"
# include "ray.h"

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
}				t_world;

t_world			world_create(void);
t_intersections	world_intersect(t_world	world, t_ray r);
void			free_world(t_world *w);

#endif
