/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 23:13:07 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/07 21:30:52 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "world.h"
#include "refract.h"

static void	copy_data(t_precomp *comps, t_lighting *data, t_world *w,
		size_t i)
{
	data->m = comps->obj->material;
	data->light = w->lights[i];
	data->p = comps->point;
	data->eyev = comps->eyev;
	data->normalv = comps->normalv;
	data->in_shadow = is_shadowed(*w, comps->over_point, i);
	data->obj = comps->obj;
	data->ambient = w->ambient;
}

t_color	shade_hit(t_world world, t_precomp comps, size_t remaining)
{
	size_t		i;
	t_color		ret;
	t_lighting	lighting_data;
	double		reflectance;

	i = 0;
	ret = color(0, 0, 0);
	while (i < world.lights_count)
	{
		copy_data(&comps, &lighting_data, &world, i);
		ret = color_add(ret, lighting(lighting_data));
		++i;
	}
	if (comps.obj->material.reflective && comps.obj->material.transparency)
	{
		reflectance = schlick(comps);
		return (color_add(color_add(ret,
					color_scalar_mult(reflected_color(world, comps,
							remaining), reflectance)), color_scalar_mult(
					refracted_color(world, comps, remaining),
					1 - reflectance)));
	}
	return (color_add(color_add(ret, reflected_color(world, comps, remaining)),
			refracted_color(world, comps, remaining)));
}
