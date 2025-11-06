/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:50:07 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/06 14:55:27 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "mlx_int.h"
#include <stdbool.h>
#include "display_mlx.h"
#include "camera.h"

static void	toggle_moving_mode(t_loop_params *p)
{
	p->moving ^= true;
	p->last_x = p->canva.width / 2;
	p->last_y = p->canva.height / 2;
	if (p->moving)
		mlx_mouse_hide(p->display.mlx_ptr, p->display.window);
	else
		mlx_mouse_show(p->display.mlx_ptr, p->display.window);
}

int	key_hooks(int keycode, t_loop_params *p)
{
	if (keycode == XK_Escape)
		return (mlx_loop_end(p->display.mlx_ptr));
	if (keycode == XK_Return)
		toggle_moving_mode(p);
	else if (p->moving && keycode == XK_w)
		move_camera_forward(p->camera, vector(0.1, 0.1, 0.1));
	else if (p->moving && keycode == XK_s)
		move_camera_forward(p->camera, vector(-0.1, -0.1, -0.1));
	else if (p->moving && keycode == XK_a)
		move_camera_sideway(p->camera, vector(0.1, 0.1, 0.1));
	else if (p->moving && keycode == XK_d)
		move_camera_sideway(p->camera, vector(-0.1, -0.1, -0.1));
	else if (p->moving && keycode == XK_q)
		move_camera_upward(p->camera, vector(0.1, 0.1, 0.1));
	else if (p->moving && keycode == XK_e)
		move_camera_upward(p->camera, vector(-0.1, -0.1, -0.1));
	p->should_render = true;
	return (0);
}

int	mouse_movement_hook(int x, int y, t_loop_params *p)
{
	if (!p->expect_moving_cursor)
	{
		p->expect_moving_cursor = true;
		return (0);
	}
	if (p->moving)
	{
		p->camera->look_at = rotate_camera(x - p->last_x, y - p->last_y,
				p->camera);
		p->expect_moving_cursor = false;
		mlx_mouse_move(p->display.mlx_ptr, p->display.window, p->canva.width / 2, p->canva.height / 2);
		//mlx_mouse_move(p->display.mlx_ptr, p->display.window, p->last_x,
		//	p->last_y);
		XFlush(((t_xvar *)p->display.mlx_ptr)->display);
		p->should_render = true;
	}
	else
	{
		mlx_mouse_get_pos(p->display.mlx_ptr, p->display.window, &p->last_x,
			&p->last_y);
	}
	return (0);
}
