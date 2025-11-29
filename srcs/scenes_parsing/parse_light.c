/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:45:40 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/28 19:28:25 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "scenes_parsing.h"
#include "libft.h"
#include <stdlib.h>

void	free_light_list(t_world *world)
{
	t_lightlist	*current;
	t_lightlist	*prev;

	current = world->tmp_light;
	while (current)
	{
		prev = current;
		current = current->next;
		free(prev);
	}
	world->tmp_light = NULL;
}

int	new_light_node(t_world *world, t_plight *light)
{
	t_lightlist	*new_node;
	t_lightlist	*current;

	new_node = malloc(sizeof(t_lightlist));
	if (!new_node)
	{
		free_light_list(world);
		return (-1);
	}
	new_node->light = *light;
	new_node->next = NULL;
	if (world->tmp_light == NULL)
	{
		world->tmp_light = new_node;
		return (0);
	}
	current = world->tmp_light;
	while (current->next)
		current = current->next;
	current->next = new_node;
	return (0);
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
