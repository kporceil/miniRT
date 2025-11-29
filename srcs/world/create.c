/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:44:06 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/28 19:22:15 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_world	world_create(void)
{
	return ((t_world){false, false, camera(0, 0, 0, point(0, 0, 0)),
		NULL, NULL, 0, 0, (t_color){0, 0, 0},
		NULL, NULL, NULL});
}
