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

static t_intersections	sort_inter(t_intersections *inter)
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
	return (*inter);
}

t_intersections	world_intersect(t_world	world, t_ray r)
{
	t_intersections	inter;
	size_t			i;

	inter.size = 0;
	inter.inters = world.buf_inter;
	if (!world.objs_count)
		return (inter);
	i = 0;
	while (i < world.objs_count)
	{
		ray_intersect(world.objs + i, r, &inter);
		++i;
	}
	return (sort_inter(&inter));
}
