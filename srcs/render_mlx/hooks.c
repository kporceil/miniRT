/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:50:07 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/30 15:14:46 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>
#include <stdbool.h>
#include "display_mlx.h"
#include "camera.h"

#include <stdio.h>

int	key_hooks(int keycode, t_loop_params *p)
{
	if (keycode == XK_Escape)
		mlx_loop_end(p->display.mlx_ptr);
	if (keycode == XK_Return)
	{
		p->moving ^= true;
		p->should_render = true;
		mlx_mouse_get_pos(p->display.mlx_ptr, p->display.window, &p->last_x, &p->last_y);
		if (p->moving)
			mlx_mouse_hide(p->display.mlx_ptr, p->display.window);
		else
			mlx_mouse_show(p->display.mlx_ptr, p->display.window);
	}
	else if (p->moving && keycode == XK_w)
		move_camera_forward(p->camera, vector(0.1, 0.1, 0.1), &p->should_render);
	else if (p->moving && keycode == XK_s)
		move_camera_forward(p->camera, vector(-0.1, -0.1, -0.1), &p->should_render);
	else if (p->moving && keycode == XK_a)
		move_camera_sideway(p->camera, vector(0.1, 0.1, 0.1), &p->should_render);
	else if (p->moving && keycode == XK_d)
		move_camera_sideway(p->camera, vector(-0.1, -0.1, -0.1), &p->should_render);
	else if (p->moving && keycode == XK_q)
		move_camera_upward(p->camera, vector(0.1, 0.1, 0.1), &p->should_render);
	else if (p->moving && keycode == XK_e)
		move_camera_upward(p->camera, vector(-0.1, -0.1, -0.1), &p->should_render);
	return (0);
}
