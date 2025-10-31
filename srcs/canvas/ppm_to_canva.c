/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm_to_canva.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:10:39 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/15 17:27:47 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "canvas.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	ppm_parse_line(char *line, t_canva *c, double scale, size_t *i)
{
	char			*ptr1;
	char			*ptr2;
	static int		rgb = 0;

	ptr1 = line;
	while (ft_isspace(*ptr1))
		++ptr1;
	while (*ptr1 && *ptr1 != '\n' && *ptr1 != '#')
	{
		if (rgb == 0)
			c->canva[*i].red = ft_strtoul(ptr1, &ptr2, 10) * scale;
		else if (rgb == 1)
			c->canva[*i].green = ft_strtoul(ptr1, &ptr2, 10) * scale;
		else if (rgb == 2)
			c->canva[(*i)++].blue = ft_strtoul(ptr1, &ptr2, 10) * scale;
		ptr1 = ptr2;
		rgb++;
		if (rgb == 3)
			rgb = 0;
		while (ft_isspace(*ptr1))
			++ptr1;
		if (*ptr1 && !ft_isdigit(*ptr1) && *ptr1 != '#')
			return (-1);
	}
	return (0);
}

int	parse_ppm_file(int fd, t_canva *c, double scale)
{
	char	*line;
	size_t	i;

	c->canva = malloc(sizeof(t_color) * c->height * c->width);
	if (!c->canva)
		return (-1);
	line = get_next_line(fd, READ);
	i = 0;
	while (line)
	{
		if (ppm_parse_line(line, c, scale, &i) == -1)
		{
			free(c->canva);
			free(line);
			return (-1);
		}
		free(line);
		line = get_next_line(fd, READ);
	}
	free(line);
	return (0);
}

t_canva	ppm_to_canva(char *file)
{
	const int	fd = open_file(file, O_RDONLY);
	size_t		max_color;
	double		scale;
	t_canva		c;

	if (fd == -1)
		return ((t_canva){0, 0, NULL});
	if (parse_ppm_header(fd, &c, &max_color) == -1)
	{
		close_ppm(fd);
		return ((t_canva){0, 0, NULL});
	}
	scale = 1.0 / max_color;
	if (parse_ppm_file(fd, &c, scale) == -1)
	{
		close_ppm(fd);
		return ((t_canva){0, 0, NULL});
	}
	close_ppm(fd);
	return (c);
}
