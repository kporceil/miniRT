/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm_to_canva.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:10:39 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/13 19:57:26 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "canvas.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

static int	get_width_and_height(int fd, t_canva *c)
{
	char	*line;
	char	*ptr1;
	char	*ptr2;

	line = get_next_line(fd);
	if (!line)
		return (-1);
	c->width = ft_strtoul(line, &ptr1, 10);
	if (ptr1 == line)
	{
		free(line);
		ft_putendl_fd("Internal error", 2);
		return (-1);
	}
	c->height = ft_strtoul(ptr1, &ptr2, 10);
	if (ptr2 == ptr1)
	{
		free(line);
		ft_putendl_fd("Internal error", 2);
		return (-1);
	}
	free(line);
	return (0);
}

static t_canva	create_canva(char *file, int fd)
{
	char	*line;
	t_canva	c;

	line = get_next_line(fd);
	if (!line)
	{
		ft_putendl_fd("Malloc error", 2);
		return ((t_canva){0, 0, NULL});
	}
	if (ft_strncmp("P3\n", line, 3))
	{
		ft_putstr_fd(file, 2);
		ft_putendl_fd(": corrupted file", 2);
		return ((t_canva){0, 0, NULL});
	}
	free(line);
	if (get_width_and_height(fd, &c) == -1)
		return ((t_canva){0, 0, NULL});
	c.canva = malloc(sizeof(t_color) * (c.height * c.width));
	if (!c.canva)
	{
		ft_putendl_fd("Malloc error", 2);
		return ((t_canva){0, 0, NULL});
	}
	return (c);
}

t_canva	ppm_to_canva(char *file)
{
	const int	fd = open(file, O_RDONLY);
	t_canva		c;

	c.canva = NULL;
	c.height = 0;
	c.width = 0;
	if (fd == -1)
	{
		ft_putstr_fd(file, 2);
		ft_putendl_fd(": no such file or directory", 2);
		return (c);
	}
	c = create_canva(file, fd);
	if (!c.canva)
		return (c);
	if (fill_canva(fd, &c) == -1)
	{
		free(c.canva);
		c.canva = NULL;
		return (c);
	}
	close(fd);
	return (c);
}
