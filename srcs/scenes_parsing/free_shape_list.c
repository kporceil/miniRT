/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_shape_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 19:32:39 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/29 19:32:52 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include <stdlib.h>

void	free_shape_list(t_world *world)
{
	t_shapelist	*current;
	t_shapelist	*prev;

	current = world->tmp_obj;
	while (current)
	{
		prev = current;
		current = current->next;
		free(prev);
	}
	world->tmp_obj = NULL;
}
