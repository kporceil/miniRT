/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:15:15 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/30 19:21:54 by kporceil         ###   ########lyon.fr   */
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

static void	adjust_and_sort_inter(t_intersections *inter)
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
}

#include <stdio.h>
t_intersections	world_intersect(t_world	world, t_ray r)
{
	t_intersections	inter;
	t_intersect		tmp_inter;
	size_t			i;
	size_t			k;
	int				j;

	i = 0;
	k = 0;
	inter.inters = NULL;
	if (!world.objs_count)
		return (inter);
	inter.inters = malloc(sizeof(t_inter) * world.objs_count * 2);
	if (!inter.inters)
		return (inter);
	while (i < world.objs_count)
	{
		tmp_inter = ray_intersect(world.objs + i, ray_transform(r, world.objs[i].inverted));
		j = 0;
		while (j < tmp_inter.count)
			inter.inters[k++] = tmp_inter.object[j++];
		++i;
	}
	inter.size = k;
	adjust_and_sort_inter(&inter);
	return (inter);
}
