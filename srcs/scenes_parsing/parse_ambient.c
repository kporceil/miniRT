/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:46:27 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/27 18:05:29 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "libft.h"

static char	*skip_space(char *str)
{
	while (ft_isspace(*str))
		++str;
	return (str);
}

static int	parse_ambient_value(char *file, t_world *world, double factor, double *rgb)
{
	char	*sptr;

	factor = ft_strtod(file, &sptr);
	if (sptr == file || !ft_isspace(*sptr))
		return (-1);
	file = sptr;
	rgb[0] = ft_strtoul(file, &sptr, 10) / 255.0;
	if (sptr == file || *sptr != ',')
		return (-1);
	file = sptr + 1;
	rgb[1] = ft_strtoul(file, &sptr, 10) / 255.0;
	if (sptr == file || *sptr != ',')
		return (-1);
	file = sptr + 1;
	rgb[2] = ft_strtoul(file, &sptr, 10) / 255.0;
	if (sptr == file)
		return (-1);
	file = skip_space(file);
	if (*file != '\0')
	{
		ft_putendl_fd("Extra character after ambient declaration", 2);
		return (-1);
	}
	world->had_ambient = true;
	world->ambient = color_scalar_mult(color(rgb[0], rgb[1], rgb[2]), factor);
}

int	parse_ambient(char *file, t_world *world)
{
	double	factor;
	double	rgb[3];

	if (world->had_ambient == true)
	{
		ft_putendl_fd("A scene can only have one ambient light", 2);
		return (-1);
	}
	if (parse_ambient_value(file, world, factor, rgb) == -1)
		return (-1);
	return (0);
}
