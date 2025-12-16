/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:15:03 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/06 14:06:41 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "tuples.h"
#include <math.h>

#define MOUSE_SENSITIVITY 0.002
#define PITCH_LIMIT 1.553343

static double	clamp(double value, double min, double max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

void	move_camera_forward(t_camera *c, double distance)
{
	t_tuple const	forward = normalize(tuple_substract(c->look_at, c->pos));
	t_tuple const	translation = tuple_scalar_mult(forward, distance);

	c->pos = tuple_add(c->pos, translation);
	c->look_at = tuple_add(c->look_at, translation);
}

void	move_camera_sideway(t_camera *c, double distance)
{
	t_tuple const	forward = normalize(tuple_substract(c->look_at, c->pos));
	t_tuple const	right = normalize(cross(c->up, forward));
	t_tuple const	translation = tuple_scalar_mult(right, distance);

	c->pos = tuple_add(c->pos, translation);
	c->look_at = tuple_add(c->look_at, translation);
}

void	move_camera_upward(t_camera *c, double distance)
{
	t_tuple const	translation = tuple_scalar_mult(normalize(c->up), distance);

	c->pos = tuple_add(c->pos, translation);
	c->look_at = tuple_add(c->look_at, translation);
}

void	rotate_camera(int dx, int dy, t_camera *c)
{
	t_tuple	direction;
	t_tuple	right;

	c->yaw += dx * MOUSE_SENSITIVITY;
	c->pitch -= dy * MOUSE_SENSITIVITY;
	c->pitch = clamp(c->pitch, -PITCH_LIMIT, PITCH_LIMIT);
	direction.x = cos(c->pitch) * sin(c->yaw);
	direction.y = -sin(c->pitch);
	direction.z = cos(c->pitch) * cos(c->yaw);
	direction.w = 0;
	right.x = cos(c->yaw);
	right.y = 0;
	right.z = -sin(c->yaw);
	right.w = 0;
	c->up = normalize(cross(direction, right));
	c->look_at = tuple_add(c->pos, direction);
}
