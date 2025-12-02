/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:45:40 by kporceil          #+#    #+#             */
/*   Updated: 2025/12/02 21:04:32 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "scenes_parsing.h"
#include "libft.h"

static char	*skip_space(char *str)
{
	while (ft_isspace(*str))
		++str;
	return (str);
}

static int	parse_light_value(char *file, t_world *world)
{
	char		*sptr;
	double		factor;
	t_color		rgb;
	t_tuple		pos;
	t_plight	light;

	if (parse_point(file, &sptr, &pos) == -1)
		return (-1);
	file = sptr;
	factor = ft_strtod(file, &sptr);
	if (file == sptr)
		return (-1);
	file = sptr;
	if (parse_color(file, &sptr, &rgb) == -1)
		return (-1);
	file = skip_space(sptr);
	if (*file != '\0')
		return (-1);
	light = point_light(pos, color_scalar_mult(rgb, factor));
	if (new_light_node(world, &light) == -1)
		return (-1);
	return (0);
}

int	parse_light(char *file, t_world *world)
{
	if (parse_light_value(file, world) == -1)
		return (-1);
	++world->lights_count;
	return (0);
}
