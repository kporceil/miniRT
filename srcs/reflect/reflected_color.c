/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflected_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:16:19 by kporceil          #+#    #+#             */
/*   Updated: 2025/09/27 16:21:54 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "ray.h"

t_color	reflected_color(t_world world, t_precomp comps, size_t remaining)
{
	t_color	c;

	c = color(0, 0, 0);
	if (comps.obj->material.reflective == 0 || !remaining)
		return (c);
	color_at(world, ray(comps.over_point, comps.reflectv), &c, remaining - 1);
	return (color_scalar_mult(c, comps.obj->material.reflective));
}
