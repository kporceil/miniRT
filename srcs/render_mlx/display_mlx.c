/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:24:33 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/13 13:54:08 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include <mlx.h>
#include "display_mlx.h"
#include "canvas.h"
#include "camera.h"

int	display_mlx(t_canva canva, t_camera camera, t_world world)
{
	t_display const	display = init_mlx_display(camera.hsize, camera.vsize);

	if (!display.mlx_ptr)
		return (1);
	mlx_loop_hook(display.mlx_ptr, render_loop,
		&(t_loop_params){canva, world, camera, display});
	mlx_hook(display.window, KeyPress, KeyPressMask,
			&key_hooks, &(t_loop_params){canva, world, camera, display});
	mlx_hook(display.window, DestroyNotify, StructureNotifyMask,
			&mlx_loop_end, display.mlx_ptr);
	mlx_loop(display.mlx_ptr);
	exit_mlx(display);
	return (0);
}
