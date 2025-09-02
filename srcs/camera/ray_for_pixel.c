/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_for_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 13:53:28 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/31 14:01:52 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "ray.h"

t_ray	ray_for_pixel(t_camera cam, size_t px, size_t py)
{
	const double	xyoffset[2] = {(px + 0.5) * cam.pixel_size,
		(py + 0.5) * cam.pixel_size};
	const double	world_xy[2] = {cam.half_width - xyoffset[0],
		cam.half_height - xyoffset[1]};
	const t_tuple	pixel = matrix_tuple_mult(cam.inverted_transform,
			point(world_xy[0], world_xy[1], -1));
	const t_tuple	origin = matrix_tuple_mult(cam.inverted_transform,
			point(0, 0, 0));

	return (ray(origin, normalize(tuple_substract(pixel, origin))));
}
