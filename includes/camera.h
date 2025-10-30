/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 13:05:42 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/30 14:58:25 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "matrix.h"
# include "ray.h"
# include "world.h"
# include "canvas.h"
# include <stddef.h>
# include <stdbool.h>

typedef struct s_camera
{
	t_matrix	transform;
	t_matrix	inverted_transform;
	t_tuple		pos;
	t_tuple		look_at;
	t_tuple		up;
	size_t		hsize;
	size_t		vsize;
	double		fov;
	double		pixel_size;
	double		half_width;
	double		half_height;
}				t_camera;

t_camera	camera(size_t hsize, size_t vsize, double fov, t_tuple pos);
void		camera_set_transform(t_camera *cam, t_matrix m);
t_ray		ray_for_pixel(t_camera cam, size_t px, size_t py);
t_canva	render(t_camera cam, t_world w, size_t pixel_size);
void	render_on_canva(t_canva *canva, t_camera cam, t_world w, size_t pixel_size);
void	move_camera_forward(t_camera *c, t_tuple translation, _Bool *should_render);
void	move_camera_sideway(t_camera *c, t_tuple translation, _Bool *should_render);
void	move_camera_upward(t_camera *c, t_tuple translation, _Bool *should_render);
t_tuple	rotate_camera(int dx, int dy, t_tuple look_at, t_tuple cam_pos, t_tuple *up);

#endif
