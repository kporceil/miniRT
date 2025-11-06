/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:30:11 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/30 17:14:37 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdbool.h>
#include "display_mlx.h"
#include "camera.h"
#include "matrix.h"
#include "tuples.h"

#include <stdio.h>

static void	should_render(t_loop_params *p, size_t frame)
{
	if (frame)
	{
		if (p->moving)
		{
			camera_set_transform(p->camera, view_transform(p->camera->pos, p->camera->look_at, p->camera->up));
			render_on_canva(&p->canva, *p->camera, p->world, 10);
		}
		else
		{
			render_on_canva(&p->canva, *p->camera, p->world, 1);
		}
		p->should_render = false;
	}
	canva_to_mlx_image(p->display, p->canva);
	mlx_put_image_to_window(p->display.mlx_ptr, p->display.window,
		p->display.image, 0, 0);
}

int	render_loop(t_loop_params *p)
{
	static size_t	frame = 0;

	if (p->should_render)
	{
		should_render(p, frame);
	}
	return (++frame);
}
