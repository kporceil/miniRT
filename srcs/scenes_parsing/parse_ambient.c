/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:46:27 by kporceil          #+#    #+#             */
/*   Updated: 2025/12/02 21:01:15 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "libft.h"
#include "scenes_parsing.h"

static int	parse_ambient_value(char *file, t_world *world)
{
	char	*sptr;
	double	factor;
	t_color	rgb;

	factor = ft_strtod(file, &sptr);
	if (sptr == file)
		return (-1);
	file = sptr;
	if (parse_color(file, &sptr, &rgb) == -1)
		return (-1);
	file = skip_space(sptr);
	if (*file != '\0')
	{
		ft_putendl_fd("Extra character after ambient declaration", 2);
		return (-1);
	}
	world->ambient = color_scalar_mult(rgb, factor);
	return (0);
}

int	parse_ambient(char *file, t_world *world)
{
	if (world->had_ambient == true)
	{
		ft_putendl_fd("A scene can only have one ambient light", 2);
		return (-1);
	}
	if (parse_ambient_value(file, world) == -1)
		return (-1);
	world->had_ambient = true;
	return (0);
}
