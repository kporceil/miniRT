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
#include <math.h>

void	camera_set_transform(t_camera *cam, t_matrix m)
{
	cam->transform = m;
	cam->inverted_transform = m;
	if (is_matrix_invertible(m))
		cam->inverted_transform = matrix_invert(m);
}

t_camera	camera(size_t hsize, size_t vsize, double fov, t_tuple pos)
{
	t_camera	ret;
	double		half_view;
	double		aspect;

	ret.pos = pos;
	ret.look_at = point(-10, 0, 0);
	ret.up = vector(0, 1, 0);
	ret.hsize = hsize;
	ret.vsize = vsize;
	ret.fov = fov;
	ret.transform = identity_matrix(4);
	ret.inverted_transform = identity_matrix(4);
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
