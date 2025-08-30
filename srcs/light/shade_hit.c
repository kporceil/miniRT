/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 23:13:07 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/30 23:16:54 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "world.h"

t_color	shade_hit(t_world world, t_precomp comps)
{
	size_t	i;
	t_color	ret;

	i = 0;
	ret = color(0, 0, 0);
	while (i < world.lights_count)
	{
		ret = color_add(ret, lighting(comps.obj->material, world.lights[i],
				comps.point, (t_tuple[2]){comps.eyev, comps.normalv}));
		++i;
	}
	return (ret);
}
