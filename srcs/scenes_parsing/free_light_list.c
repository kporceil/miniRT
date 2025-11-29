/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_light_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 19:11:13 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/29 19:11:36 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
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
