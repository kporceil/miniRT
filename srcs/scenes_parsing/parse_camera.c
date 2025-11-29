/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:47:08 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/28 19:11:35 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "libft.h"
#include "scenes_parsing.h"
#include <math.h>

#ifndef HEIGHT
# define HEIGHT 1080
#endif

#ifndef WIDTH
# define WIDTH 1920
#endif

static char	*skip_space(char *str)
{
	while (ft_isspace(*str))
		++str;
	return (str);
}

static int	parse_camera_value(char *file, t_world *world)
{
	t_tuple	pos;
	t_tuple	look_at;
	double	fov;
	char	*sptr;

	if (parse_point(file, &sptr, &pos) == -1)
		return (-1);
	file = sptr;
	if (parse_vector(file, &sptr, &look_at) == -1)
		return (-1);
	file = sptr;
	fov = ft_strtoul(file, &sptr, 10) * (M_PI / 180);
	if (file == sptr)
		return (-1);
	file = sptr;
	file = skip_space(file);
	if (*file != '\0')
	{
		ft_putendl_fd("Extra character after camera declaration", 2);
		return (-1);
	}
	world->cam = camera(HEIGHT, WIDTH, fov, pos);
	world->cam.look_at = tuple_add(look_at, pos);
	camera_set_transform(&world->cam, view_transform(world->cam.pos,
							world->cam.look_at, world->cam.up));
	return (0);
}

int	parse_camera(char *file, t_world *world)
{
	t_tuple	pos;

	pos.w = 1;
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
