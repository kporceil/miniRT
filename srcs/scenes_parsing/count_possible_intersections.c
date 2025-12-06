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

static size_t	get_max_inter_for_shape(t_tshape type)
{
	if (type == CONE)
		return (4);
	return (2);
}

static size_t	inter_nb_for_shape(t_shape *shape)
{
	size_t	i;
	size_t	count;

	if (shape->type == GROUP)
	{
		i = 0;
		count = 0;
		while (i < shape->nb_members)
		{
			count += inter_nb_for_shape(shape->child + i);
			++i;
		}
		return (count);
	}
	return (get_max_inter_for_shape(shape->type));
}

size_t	count_possible_intersections(t_world *world)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (i < world->objs_count)
	{
		count += inter_nb_for_shape(world->objs + i);
		++i;
	}
	return (count);
}
