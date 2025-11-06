/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:30:11 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/06 13:48:48 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include "display_mlx.h"
#include "camera.h"
#include "matrix.h"
#include "tuples.h"
#include "visual_settings.h"

#include <stdio.h>

static size_t	optimal_pixel_size(size_t target_fps, size_t render_time, size_t last_pixel_size)
{
	size_t	new_px_size;

	printf("%zu\n", render_time);
	new_px_size = last_pixel_size;
	if (render_time > (1.0 / target_fps) * 1000)
	{
		// decrease res
		++new_px_size;
		while (new_px_size <= WIDTH && new_px_size <= HEIGHT && (WIDTH % new_px_size) && (HEIGHT % new_px_size))
			++new_px_size;
		if (new_px_size == WIDTH || new_px_size == HEIGHT)
			return (last_pixel_size);
	}
	else
	{
		// increase res
		--new_px_size;
		while (new_px_size && (WIDTH % new_px_size) && (HEIGHT % new_px_size))
			--new_px_size;
		if (!new_px_size)
			return (last_pixel_size);
	}
	return (new_px_size);
}

static void	should_render(t_loop_params *p, size_t frame, size_t last_render_time)
{
	static size_t	pixel_size = 10;

	if (frame)
	{
		if (p->moving)
		{
			camera_set_transform(p->camera, view_transform(p->camera->pos, p->camera->look_at, p->camera->up));
			pixel_size = optimal_pixel_size(TARGET_FPS, last_render_time, pixel_size);
		}
		else
			pixel_size = 1;
		printf("%ld\n", pixel_size);
		render_on_canva(&p->canva, *p->camera, p->world, pixel_size);
		p->should_render = false;
	}
	canva_to_mlx_image(p->display, p->canva);
	mlx_put_image_to_window(p->display.mlx_ptr, p->display.window,
		p->display.image, 0, 0);
}

int	render_loop(t_loop_params *p)
{
	static size_t			frame = 0;
	static size_t			render_time = (1.0 / TARGET_FPS) * 1000;
	static struct timeval 	tv_a = (struct timeval){0};
	static struct timeval 	tv_b = (struct timeval){0};

	if (p->should_render)
	{
		gettimeofday(&tv_b, NULL);
		should_render(p, frame, render_time);
		gettimeofday(&tv_a, NULL);
		render_time = 1000 * (tv_a.tv_sec - tv_b.tv_sec) + (tv_a.tv_usec - tv_b.tv_usec) / 1000;
	}
	return (++frame);
}
