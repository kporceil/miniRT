/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:48:17 by kporceil          #+#    #+#             */
/*   Updated: 2025/12/18 15:04:34 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bounding_box.h"
#include "get_next_line.h"
#include "light.h"
#include "world.h"
#include "uid.h"
#include "groups.h"
#include "scenes_parsing.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

static void	error_clear(int fd, char *to_free, t_world *world)
{
	(void)get_next_line(fd, DELETE);
	close(fd);
	free(to_free);
	free_light_list(world);
	free_shape_list(world);
}

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

static void	copy_list_in_array(t_world *world)
{
	t_lightlist	*light;
	t_shapelist	*shape;
	size_t		i_light;

	shape = world->tmp_obj;
	light = world->tmp_light;
	world->objs_count = 0;
	if (is_bvh_needed(world) == 1)
		world->objs[0] = group(generate_uid(), ++world->objs_count);
	while (shape)
	{
		if (shape->shape.type == PLANE)
			world->objs[world->objs_count++] = shape->shape;
		else
			group_add_shape(world->objs, shape->shape);
		shape = shape->next;
	}
	divide(world->objs, 5);
	i_light = 0;
	while (i_light < world->lights_count)
	{
		world->lights[i_light] = light->light;
		light = light->next;
		++i_light;
	}
}

static int	convert_world_list(t_world *world)
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
	copy_list_in_array(world);
	world->buf_inter = malloc(sizeof(t_inter)
			* count_possible_intersections(world));
	return (0);
}

int	parse_file(char *file, t_world *world)
{
	char		*line;
	const int	fd = open(file, O_RDONLY);

	if (fd == -1)
	{
		(void)!write(2, "Cannot open file\n", 18);
		return (-1);
	}
	line = get_next_line(fd, READ);
	while (line != NULL)
	{
		if (parse_line(line, world) == -1)
		{
			error_clear(fd, line, world);
			return (-1);
		}
		free(line);
		line = get_next_line(fd, READ);
	}
	(void)get_next_line(fd, DELETE);
	close(fd);
	if (check_world_health(world) == false || convert_world_list(world) == -1)
		return (-1);
	return (0);
}
