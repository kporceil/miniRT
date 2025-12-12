/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:05:50 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/16 13:48:26 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "ray.h"
#include "bounding_box.h"

#include <stdio.h>

void	ray_group_intersect(t_shape *g, t_ray r, t_intersections *xs)
{
	size_t	i;

	i = 0;
	if (bb_intersect(bb_transform(g->group_bbox, g->local_transformation), r))
	{
		//printf("in box %zu: xmin %lf ymin %lf zmin %lf xmax %lf ymax %lf zmax %lf\n", g->id, g->group_bbox.min.x, g->group_bbox.min.y, g->group_bbox.min.z, g->group_bbox.max.x, g->group_bbox.max.y, g->group_bbox.max.z);
		while (i < g->nb_members)
		{
			ray_intersect(g->child + i, r, xs);
			++i;
		}
	}
}
