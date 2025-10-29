/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 13:05:42 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/31 14:33:33 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "matrix.h"
# include "ray.h"
# include "world.h"
# include "canvas.h"
# include <stddef.h>

typedef struct s_camera
{
	t_matrix	transform;
	t_matrix	inverted_transform;
	size_t		hsize;
	size_t		vsize;
	double		fov;
	double		pixel_size;
	double		half_width;
	double		half_height;
}				t_camera;

t_camera	camera(size_t hsize, size_t vsize, double fov);
void		camera_set_transform(t_camera *cam, t_matrix m);
t_ray		ray_for_pixel(t_camera cam, size_t px, size_t py);
t_canva	render(t_camera cam, t_world w, size_t pixel_size);

#endif
