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

void	ray_group_intersect(t_shape *g, t_ray r, t_intersections *xs)
{
	size_t	i;

	i = 0;
	while (i < g->nb_members)
	{
		ray_intersect(g->child + i, r, xs);
		++i;
	}
}
