/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 13:11:30 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/31 13:52:47 by kporceil         ###   ########lyon.fr   */
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

t_camera	camera(size_t hsize, size_t vsize, double fov)
{
	t_camera	ret;
	double		half_view;
	double		aspect;

	ret.hsize = hsize;
	ret.vsize = vsize;
	ret.fov = fov;
	ret.transform = identity_matrix(4);
	ret.inverted_transform = identity_matrix(4);
	half_view = tan(fov / 2);
	aspect = (double)hsize / vsize;
	if (aspect >= 1)
	{
		ret.half_width = half_view;
		ret.half_height = half_view / aspect;
	}
	else
	{
		ret.half_width = half_view * aspect;
		ret.half_height = half_view;
	}
	ret.pixel_size = (ret.half_width * 2) / hsize;
	return (ret);
}
