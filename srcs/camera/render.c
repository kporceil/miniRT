/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:25:20 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/31 14:33:03 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "ray.h"
#include "world.h"
#include "canvas.h"
#include <stdlib.h>

static t_canva	free_can_and_set_to_null(t_canva c)
{
	free(c.canva);
	c.canva = NULL;
	return (c);
}

static void put_square(t_canva *image, size_t x, size_t y, t_color c, size_t pixel_size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < pixel_size)
	{
		j = 0;
		while (j < pixel_size)
		{
			write_pixel(image, x + j, y + i, c);
			++j;
		}
		++i;
	}
}

t_canva	render(t_camera cam, t_world w, size_t pixel_size)
{
	t_canva	image;
	t_ray	r;
	t_color	c;
	size_t	x;
	size_t	y;

	image = canva(cam.hsize, cam.vsize);
	if (!image.canva)
		return (image);
	y = 0;
	while (y < cam.vsize)
	{
		x = 0;
		while (x < cam.hsize)
		{
			r = ray_for_pixel(cam, x, y);
			if (color_at(w, r, &c, MAX_RECU))
				return (free_can_and_set_to_null(image));
			put_square(&image, x, y, c, pixel_size);
			//write_pixel(&image, x, y, c);
			x += pixel_size;
		}
		y += pixel_size;
	}
	return (image);
}
