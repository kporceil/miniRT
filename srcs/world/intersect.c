/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:15:15 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/26 16:46:27 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "world.h"
#include "ray.h"

static void	adjust_inter(t_intersections *inter)
{
	t_inter	*adjusted;
	size_t	i;

	adjusted = malloc(sizeof(t_inter) * inter->size);
	if (!adjusted)
		return ;
	i = 0;
	while (i < inter->size)
	{
		adjusted[i] = inter->inters[i];
		++i;
	}
	free(inter->inters);
	inter->inters = adjusted;
}

static t_intersections	adjust_and_sort_inter(t_intersections *inter)
{
	t_inter	tmp;
	size_t	i;

	i = 0;
	while (i + 1 < inter->size)
	{
		if (inter->inters[i].point > inter->inters[i + 1].point)
		{
			tmp = inter->inters[i];
			inter->inters[i] = inter->inters[i + 1];
			inter->inters[i + 1] = tmp;
			i = 0;
		}
		else
			++i;
	}
	adjust_inter(inter);
	return (*inter);
}

static size_t	count_possible_intersection(t_world world)
{
	size_t	ret;
	size_t	i;

	ret = 0;
	i = 0;
	while (i < world.objs_count)
	{
		if (world.objs[i].type == CONE)
			ret += 4;
		else if (world.objs[i].type == GROUP)
			ret += count_possible_intersection(
					(t_world){world.objs[i].child, NULL,
					world.objs[i].nb_members, 0});
		else
			ret += 2;
		++i;
	}
	return (ret);
}

t_intersections	world_intersect(t_world	world, t_ray r)
{
	t_intersections	inter;
	size_t			i;

	inter.size = 0;
	inter.inters = NULL;
	if (!world.objs_count)
		return (inter);
	i = 0;
	inter.inters = malloc(sizeof(t_inter) * count_possible_intersection(world));
	if (!inter.inters)
		return (inter);
	while (i < world.objs_count)
	{
		ray_intersect(world.objs + i, r, &inter);
		++i;
	}
	return (adjust_and_sort_inter(&inter));
}
