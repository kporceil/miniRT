/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:47:08 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/27 17:08:22 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "libft.h"

int	parse_camera(char *file, t_world *world)
{
	(void)file;
	if (world->had_cam == true)
	{
		ft_putendl_fd("A scene can only have one camera", 2);
		return (-1);
	}
	world->had_cam = true;
	return (0);
}
