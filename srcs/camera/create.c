/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 13:11:30 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/06 14:02:20 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "tuples.h"
#include <math.h>

void	camera_set_transform(t_camera *cam, t_matrix m)
{
	cam->transform = m;
	cam->inverted_transform = m;
	if (is_matrix_invertible(m))
		cam->inverted_transform = matrix_invert(m);
}

void	camera_init_orientation(t_camera *cam, t_tuple direction)
{
	t_tuple const	dir = normalize(direction);

	cam->pitch = asin(-dir.y);
	cam->yaw = atan2(dir.x, dir.z);
}

static void	init_base_camera_values(t_camera *c, size_t hsize, size_t vsize,
									t_tuple pos)
{
	c->pos = pos;
	c->look_at = point(0, 0, 0);
	c->up = vector(0, 1, 0);
	c->hsize = hsize;
	c->vsize = vsize;
	c->transform = identity_matrix(4);
	c->inverted_transform = identity_matrix(4);
	c->yaw = 0.0;
	c->pitch = 0.0;
}

t_camera	camera(size_t hsize, size_t vsize, double fov, t_tuple pos)
{
	t_camera	ret;
	double		half_view;
	double		aspect;

	init_base_camera_values(&ret, hsize, vsize, pos);
	ret.fov = fov;
	half_view = tan(fov / 2);
	aspect = (double)hsize / vsize;
	if (aspect >= 1)
		ret.half_width = half_view;
	if (aspect >= 1)
		ret.half_height = half_view / aspect;
	else
	{
		ret.half_width = half_view * aspect;
		ret.half_height = half_view;
	}
	ret.pixel_size = (ret.half_width * 2) / hsize;
	return (ret);
}
