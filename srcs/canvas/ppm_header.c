/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:02:54 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/15 17:51:20 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "canvas.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

static char	*skip_comments_line(int fd)
{
	char	*line;

	line = get_next_line(fd, READ);
	while (line && *line == '#')
	{
		free(line);
		line = get_next_line(fd, READ);
	}
	return (line);
}

static int	check_magic_number(int fd)
{
	char	*line;

	line = skip_comments_line(fd);
	if (!line)
		return (-1);
	if (ft_strncmp("P3\n", line, 3))
	{
		free(line);
		return (-1);
	}
	free(line);
	return (0);
}

static int	parse_width_height(int fd, t_canva *c)
{
	char	*line;
	char	*ptr1;
	char	*ptr2;

	line = skip_comments_line(fd);
	if (!line)
		return (-1);
	ptr1 = line;
	c->width = ft_strtoul(ptr1, &ptr2, 10);
	if (ptr1 == ptr2)
	{
		free(line);
		return (-1);
	}
	c->height = ft_strtoul(ptr2, &ptr1, 10);
	if (ptr1 == ptr2)
	{
		free(line);
		return (-1);
	}
	free(line);
	return (0);
}

static int	parse_max_color(int fd, size_t *max_color)
{
	char	*line;
	char	*ptr1;
	char	*ptr2;

	line = skip_comments_line(fd);
	if (!line)
		return (-1);
	ptr1 = line;
	*max_color = ft_strtoul(ptr1, &ptr2, 10);
	if (ptr1 == ptr2)
	{
		free(line);
		return (-1);
	}
	free(line);
	return (0);
}

int	parse_ppm_header(int fd, t_canva *c, size_t *max_color)
{
	if (check_magic_number(fd) == -1)
		return (-1);
	if (parse_width_height(fd, c) == -1)
		return (-1);
	if (parse_max_color(fd, max_color) == -1)
		return (-1);
	return (0);
}
