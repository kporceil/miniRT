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
#include "world.h"
#include "scenes_parsing.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

static bool	check_world_health(t_world *world)
{
	if (world->had_ambient == false || world->had_cam == false)
		return (false);
	return (true);
}

static void	error_clear(int fd, char *to_free)
{
	(void)get_next_line(fd, DELETE);
	close(fd);
	free(to_free);
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
	if (check_world_health(world) == false)
		return (-1);
	return (0);
}
