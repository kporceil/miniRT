/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 23:28:56 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/31 14:38:20 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "ray.h"
#include "world.h"
#include <stdlib.h>

int	color_at(t_world w, t_ray r, t_color *c)
{
	const t_intersections	inters = world_intersect(w, r);
	t_inter					*hit;
	t_precomp				comps;

	*c = color(0, 0, 0);
	if (!inters.inters)
		return (-1);
	hit = inter_hit(inters.inters, inters.size);
	if (!hit)
	{
		free(inters.inters);
		return (0);
	}
	comps = precompute(*hit, r);
	*c = shade_hit(w, comps);
	free(inters.inters);
	return (0);
}
