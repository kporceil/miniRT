/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_world_lists.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:12:37 by kporceil          #+#    #+#             */
/*   Updated: 2025/12/22 17:12:41 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "scenes_parsing.h"
#include "groups.h"
#include "uid.h"
#include "bounding_box.h"
#include <stdlib.h>

static int	is_bvh_needed(t_world *world)
{
	t_shapelist	*shape;

	shape = world->tmp_obj;
	while (shape)
	{
		if (shape->shape.type != PLANE)
			return (1);
		shape = shape->next;
	}
	return (0);
}

static int	copy_shape_in_world(t_world *world, t_shapelist *shape)
{
	while (shape)
	{
		if (shape->shape.type == PLANE)
			world->objs[world->objs_count++] = shape->shape;
		else
		{
			if (group_add_shape(world->objs, shape->shape) == 1)
				return (-1);
		}
		shape = shape->next;
	}
	return (0);
}

static int	copy_list_in_array(t_world *world)
{
	t_lightlist	*light;
	t_shapelist	*shape;
	size_t		i_light;

	shape = world->tmp_obj;
	light = world->tmp_light;
	world->objs_count = 0;
	if (is_bvh_needed(world) == 1)
	{
		world->objs[0] = group(generate_uid(), ++world->objs_count);
		if (world->objs[0].child == NULL)
			return (-1);
	}
	if (copy_shape_in_world(world, shape) == -1)
		return (-1);
	divide(world->objs, 5);
	i_light = 0;
	while (i_light < world->lights_count)
	{
		world->lights[i_light] = light->light;
		light = light->next;
		++i_light;
	}
	return (0);
}

int	convert_world_list(t_world *world)
{
	world->lights = malloc(sizeof(t_plight) * world->lights_count);
	if (!world->lights)
	{
		free_world(world);
		return (-1);
	}
	if (world->objs_count != 0)
	{
		world->objs = malloc(sizeof(t_shape) * world->objs_count);
		if (!world->objs)
		{
			free_world(world);
			return (-1);
		}
	}
	if (copy_list_in_array(world) == -1)
	{
		free_world(world);
		return (-1);
	}
	world->buf_inter = malloc(sizeof(t_inter)
			* count_possible_intersections(world));
	return (0);
}
