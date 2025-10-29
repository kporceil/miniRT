/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:30:11 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/29 16:46:26 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdbool.h>
#include "display_mlx.h"
#include "camera.h"
#include "matrix.h"

static int	color_to_int(t_color c)
{
	int	ret;

	ret = 0;
	if (c.red >= 1.0)
		ret += 255 << 16;
	else
		ret += (unsigned char)(c.red * 255) << 16;
	if (c.green >= 1.0)
		ret += 255 << 8;
	else
		ret += (unsigned char)(c.green * 255) << 8;
	if (c.blue >= 1.0)
		ret += 255;
	else
		ret += (unsigned char)(c.blue * 255);
	return (ret);
}

static void	canva_to_mlx_image(t_display display, t_canva canva)
{
	size_t			pos;
	size_t			pos_max;

	pos = 0;
	pos_max = canva.height * canva.width;
	while (pos < pos_max)
	{
		((int *)display.data_addr)[pos]
			= mlx_get_color_value(display.mlx_ptr,
				color_to_int(canva.canva[pos]));
		++pos;
	}
}

#include <stdio.h>

int	render_loop(t_loop_params *p)
{
	static size_t	frame = 0;
	//static int x;
	//static int y;

	if (p->should_render)
	{
		if (frame)
		{
			if (p->moving)
			{
				//mlx_mouse_get_pos(p->display.mlx_ptr, p->display.window, &x, &y);
				camera_set_transform(p->camera, view_transform(p->camera->pos, p->camera->look_at, p->camera->up));
				render_on_canva(&p->canva, *p->camera, p->world, 10);
			}
			else
				render_on_canva(&p->canva, *p->camera, p->world, 1);
			p->should_render = false;
		}
		canva_to_mlx_image(p->display, p->canva);
		mlx_put_image_to_window(p->display.mlx_ptr, p->display.window,
			p->display.image, 0, 0);
	}
	return (++frame);
}
