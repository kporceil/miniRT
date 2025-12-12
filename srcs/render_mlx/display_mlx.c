/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:24:33 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/06 14:11:46 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <mlx.h>
#include "display_mlx.h"
#include "canvas.h"
#include "camera.h"

#include <unistd.h> 

int	display_mlx(t_canva canva, t_camera *camera, t_world world,
				size_t render_time)
{
	t_display const	display = init_mlx_display(camera->hsize, camera->vsize);
	t_loop_params	params;

	if (!display.mlx_ptr)
		return (1);
	params = (t_loop_params){canva, world, camera, display, render_time,
		camera->vsize / 2, camera->hsize / 2, false, true, true};

	mlx_loop_hook(display.mlx_ptr, render_loop, &params);
	mlx_hook(display.window, KeyPress, KeyPressMask, &key_hooks, &params);
	mlx_hook(display.window, DestroyNotify, StructureNotifyMask,
		&mlx_loop_end, display.mlx_ptr);
	mlx_hook(display.window, MotionNotify, PointerMotionMask,
		&mouse_movement_hook, &params);
	mlx_loop(display.mlx_ptr);
	exit_mlx(display);
	//canva_to_mlx_image(params.display, params.canva);
	//mlx_put_image_to_window(params.display.mlx_ptr, params.display.window,
	//	params.display.image, 0, 0);
	//sleep(10);
	return (0);
}
