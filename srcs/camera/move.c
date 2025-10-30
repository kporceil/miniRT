/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:15:03 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/30 14:28:33 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "tuples.h"
#include <stdbool.h>

void	move_camera(t_camera *c, t_tuple translation, _Bool *should_render)
{
	c->pos = tuple_add(c->pos, translation);
	c->look_at = tuple_add(c->look_at, translation);
	//c->pos = tuple_add(c->pos, tuple_mult(tuple_substract(c->pos, c->look_at), translation));
	//c->look_at = tuple_add(c->look_at, tuple_mult(tuple_substract(c->pos, c->look_at), translation));
	*should_render = true;
}

// NOTE: to rotate, rotate look at point arround the origin by substracting camera coords from look at point. the add them bacj after the rotation was done.

t_tuple	rotate_camera(int dx, int dy, t_tuple look_at, t_tuple cam_pos, t_tuple *up)
{
	t_tuple	ret;

	ret = tuple_substract(look_at, cam_pos);
	ret.w = 1;
	ret = matrix_tuple_mult(matrix_z_rotation(0.01 * dy), ret);
	ret = matrix_tuple_mult(matrix_y_rotation(0.01 * dx), ret);
	*up = matrix_tuple_mult(matrix_z_rotation(0.01 * dy), *up);
	*up = matrix_tuple_mult(matrix_y_rotation(0.01 * dx), *up);
	ret = tuple_add(ret, cam_pos);
	return (ret);
}
