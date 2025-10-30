/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:15:03 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/30 15:27:48 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "tuples.h"
#include <stdbool.h>

void	move_camera_forward(t_camera *c, t_tuple translation, _Bool *should_render)
{
	t_tuple const	forward = normalize(tuple_substract(c->look_at, c->pos));

	translation = tuple_mult(forward,  translation);
	c->pos = tuple_add(c->pos, translation);
	c->look_at = tuple_add(c->look_at, translation);
	*should_render = true;
}

void	move_camera_sideway(t_camera *c, t_tuple translation, _Bool *should_render)
{
	t_tuple const	forward = normalize(tuple_substract(c->look_at, c->pos));
	t_tuple const	right = normalize(cross(forward, c->up));

	translation = tuple_mult(right, translation);
	c->pos = tuple_add(c->pos, translation);
	c->look_at = tuple_add(c->look_at, translation);
	*should_render = true;
}

void	move_camera_upward(t_camera *c, t_tuple translation, _Bool *should_render)
{
	translation = tuple_mult(c->up, translation);

	c->pos = tuple_add(c->pos, translation);
	c->look_at = tuple_add(c->look_at, translation);
	*should_render = true;
}

t_tuple	rotate_camera(int dx, int dy, t_tuple look_at, t_tuple cam_pos, t_tuple *up)
{
	t_tuple	ret;

	ret = tuple_substract(look_at, cam_pos);
	ret.w = 1;
	ret = matrix_tuple_mult(matrix_z_rotation(0.005 * dy), ret);
	ret = matrix_tuple_mult(matrix_y_rotation(0.005 * dx), ret);
	*up = normalize(matrix_tuple_mult(matrix_z_rotation(0.005 * dy), *up));
	*up = normalize(matrix_tuple_mult(matrix_y_rotation(0.005 * dx), *up));
	ret = tuple_add(ret, cam_pos);
	return (ret);
}
