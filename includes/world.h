/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:04:43 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/09 14:54:34 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "light.h"
# include "shape.h"
# include "ray.h"

typedef struct s_world
{
	t_shape		*objs;
	t_plight	*lights;
	size_t		objs_count;
	size_t		lights_count;
	t_inter		*buf_inter;
}				t_world;

t_world			world_create(void);
t_intersections	world_intersect(t_world	world, t_ray r);
void			free_world(t_world *w);

#endif
