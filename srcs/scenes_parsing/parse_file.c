/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:48:17 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/27 16:42:34 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "light.h"
#include "world.h"
#include "scenes_parsing.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

static bool	check_world_health(t_world *world)
{
	if (world->had_ambient == false || world->had_cam == false)
	{
		free_world(world);
		return (false);
	}
	return (true);
}

static void	error_clear(int fd, char *to_free)
{
	(void)get_next_line(fd, DELETE);
	close(fd);
	free(to_free);
}

static void	copy_list_in_array(t_world *world)
{
	t_lightlist	*light;
	t_shapelist	*shape;
	size_t		i_light;
	size_t		i_shape;

	shape = world->tmp_obj;
	light = world->tmp_light;
	i_shape = 0;
	while (i_shape < world->objs_count)
	{
		world->objs[i_shape] = shape->shape;
		shape = shape->next;
		++i_shape;
	}
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
	world->objs = malloc(sizeof(t_shape) * world->objs_count);
	if (!world->objs)
	{
		free_world(world);
		return (-1);
	}
	world->buf_inter = malloc(sizeof(t_inter) * world->objs_count * 2);
	copy_list_in_array(world);
	return (0);
}

int	parse_file(char *file, t_world *world)
{
	char		*line;
	const int	fd = open(file, O_RDONLY);

	if (fd == -1)
	{
		write(2, "Cannot open file\n", 18);
		return (-1);
	}
	line = get_next_line(fd, READ);
	while (line != NULL)
	{
		if (parse_line(line, world) == -1)
		{
			error_clear(fd, line);
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
