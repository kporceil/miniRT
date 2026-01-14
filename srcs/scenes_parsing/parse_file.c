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

#include "get_next_line.h"
#include "light.h"
#include "world.h"
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
	if (convert_world_list(world) == -1 || check_world_health(world) == false)
		return (-1);
	return (0);
}
