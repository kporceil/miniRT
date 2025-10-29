/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:50:07 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/29 16:40:34 by lcesbron         ###   ########lyon.fr   */
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
	}
	else if (p->moving && keycode == XK_s)
		move_camera(p->camera, (t_tuple){0.1, 0, 0, 0}, &p->should_render);
	else if (p->moving && keycode == XK_w)
		move_camera(p->camera, (t_tuple){-0.1, 0, 0, 0}, &p->should_render);
	else if (p->moving && keycode == XK_d)
		move_camera(p->camera, (t_tuple){0, 0, 0.1, 0}, &p->should_render);
	else if (p->moving && keycode == XK_a)
		move_camera(p->camera, (t_tuple){0, 0, -0.1, 0}, &p->should_render);
	printf("%lf\n", p->camera->pos.x);
	return (0);
}
