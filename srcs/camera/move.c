/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:15:03 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/30 17:11:36 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "tuples.h"

void	move_camera_forward(t_camera *c, t_tuple translation)
{
	t_tuple const	forward = normalize(tuple_substract(c->look_at, c->pos));

	translation = tuple_mult(forward,  translation);
	c->pos = tuple_add(c->pos, translation);
	c->look_at = tuple_add(c->look_at, translation);
}

void	move_camera_sideway(t_camera *c, t_tuple translation)
{
	t_tuple const	forward = normalize(tuple_substract(c->look_at, c->pos));
	t_tuple const	right = normalize(cross(forward, c->up));

	translation = tuple_mult(right, translation);
	c->pos = tuple_add(c->pos, translation);
	c->look_at = tuple_add(c->look_at, translation);
}

void	move_camera_upward(t_camera *c, t_tuple translation)
{
	translation = tuple_mult(normalize(c->up), translation);

	c->pos = tuple_add(c->pos, translation);
	c->look_at = tuple_add(c->look_at, translation);
}

t_tuple	rotate_camera(int dx, int dy, t_camera *c)
{
	t_tuple	ret;
	t_tuple const	forward = normalize(tuple_substract(c->look_at, c->pos));

	ret = tuple_substract(c->look_at, c->pos);
	ret.w = 1;
	ret = matrix_tuple_mult(matrix_z_rotation(0.001 * dy), ret);
	ret = matrix_tuple_mult(matrix_y_rotation(0.001 * dx), ret);
	c->up = normalize(matrix_tuple_mult(matrix_z_rotation(0.001 * dy), c->up));
	c->up = normalize(matrix_tuple_mult(matrix_y_rotation(0.001 * dx), c->up));
	c->up = normalize(cross(normalize(cross(forward, vector(0, 1, 0))), forward));
	ret = tuple_add(ret, c->pos);
	return (ret);
}
