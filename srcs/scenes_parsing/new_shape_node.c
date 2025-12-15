/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_shape_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 19:33:10 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/29 19:33:29 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include <stdlib.h>
#include "scenes_parsing.h"

int	new_shape_node(t_world *world, t_shape *shape)
{
	t_shapelist	*new_node;
	t_shapelist	*current;

	new_node = malloc(sizeof(t_shapelist));
	if (!new_node)
	{
		free_shape_list(world);
		return (-1);
	}
	new_node->shape = *shape;
	new_node->next = NULL;
	if (world->tmp_obj == NULL)
	{
		world->tmp_obj = new_node;
		return (0);
	}
	current = world->tmp_obj;
	while (current->next)
		current = current->next;
	current->next = new_node;
	return (0);
}
