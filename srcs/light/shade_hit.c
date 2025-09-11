/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 23:13:07 by kporceil          #+#    #+#             */
/*   Updated: 2025/09/03 19:27:11 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "world.h"

t_color	shade_hit(t_world world, t_precomp comps)
{
	size_t		i;
	t_color		ret;
	t_lighting	lighting_data;

	i = 0;
	ret = color(0, 0, 0);
	while (i < world.lights_count)
	{
		lighting_data.m = comps.obj->material;
		lighting_data.light = world.lights[i];
		lighting_data.p = comps.point;
		lighting_data.eyev = comps.eyev;
		lighting_data.normalv = comps.normalv;
		lighting_data.in_shadow = is_shadowed(world, comps.over_point, i);
		ret = color_add(ret, lighting(lighting_data));
		++i;
	}
	return (ret);
}
