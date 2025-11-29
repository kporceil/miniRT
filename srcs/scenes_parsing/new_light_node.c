/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_light_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 19:10:24 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/29 19:11:58 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "scenes_parsing.h"
#include <stdlib.h>

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
