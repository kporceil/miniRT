/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:47:08 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/29 19:14:07 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "libft.h"
#include "scenes_parsing.h"
#include "visual_settings.h"
#include <math.h>

static int	parse_camera_value(char *file, t_world *world)
{
	t_tuple	pos;
	t_tuple	forward;
	double	fov;
	char	*sptr;

	if (parse_point(file, &sptr, &pos) == -1)
		return (-1);
	file = sptr;
	if (parse_normalized_vector(file, &sptr, &forward) == -1)
		return (-1);
	file = sptr;
	fov = ft_strtod(file, &sptr) * (M_PI / 180);
	if (file == sptr)
		return (-1);
	file = skip_space(sptr);
	if (*file != '\0')
	{
		ft_putendl_fd("Extra character after camera declaration", 2);
		return (-1);
	}
	world->cam = camera(WIDTH, HEIGHT, fov, pos);
	world->cam.look_at = tuple_add(forward, pos);
	camera_init_orientation(&world->cam, forward);
	camera_set_transform(&world->cam, view_transform_from_to(world->cam.pos,
			world->cam.look_at, world->cam.up));
	return (0);
}

int	parse_camera(char *file, t_world *world)
{
	if (world->had_cam == true)
	{
		ft_putendl_fd("A scene can only have one camera", 2);
		return (-1);
	}
	if (parse_camera_value(file, world) == -1)
		return (-1);
	world->had_cam = true;
	return (0);
}
