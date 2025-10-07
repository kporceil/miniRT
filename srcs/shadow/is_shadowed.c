/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_shadowed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:34:26 by kporceil          #+#    #+#             */
/*   Updated: 2025/09/03 18:59:53 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "tuples.h"
#include "world.h"
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

bool	is_shadowed(t_world w, t_tuple p, size_t i)
{
	t_shadow	shadow;

	shadow.v_to_light = tuple_substract(w.lights[i].pos, p);
	shadow.distance = magnitude(shadow.v_to_light);
	shadow.direction = normalize(shadow.v_to_light);
	shadow.r = ray(p, shadow.direction);
	shadow.inters = world_intersect(w, shadow.r);
	if (!shadow.inters.inters)
		return (false);
	shadow.hit_point = inter_hit(shadow.inters.inters, shadow.inters.size);
	if (shadow.hit_point && shadow.distance - shadow.hit_point->point > 0.0001)
	{
		free(shadow.inters.inters);
		return (true);
	}
	free(shadow.inters.inters);
	return (false);
}
