/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_possible_intersections.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:51:45 by kporceil          #+#    #+#             */
/*   Updated: 2025/12/05 17:51:52 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

size_t	count_possible_intersections(t_world *world)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (i < world->objs_count)
	{
		if (world->objs[i++].type == CONE)
			count += 4;
		else
			count += 2;
	}
	return (count);
}
