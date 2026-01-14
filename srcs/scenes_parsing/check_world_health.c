/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_world_health.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:04:26 by kporceil          #+#    #+#             */
/*   Updated: 2025/12/18 15:04:34 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

bool	check_world_health(t_world *world)
{
	if (world->had_ambient == false || world->had_cam == false
		|| world->lights_count == 0 || world->objs_count)
	{
		free_world(world);
		return (false);
	}
	return (true);
}
