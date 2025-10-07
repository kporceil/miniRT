/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 22:04:06 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/07 15:24:13 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "patterns.h"
#include "shape.h"
#include "tuples.h"
#include "canvas.h"
#include "libft.h"
#include "light.h"
#include "world.h"
#include "camera.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	tick(t_tuple *env, t_tuple *proj);

void	write_file(char	*name, char	*ppm)
{
	int	fd;

	fd = open(name, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd == -1)
		return ;
	ft_putstr_fd(ppm, fd);
	close(fd);
}

int	main(void)
{
	t_world	world = world_create();

	world.lights_count = 1;
	world.objs_count = 1;
	world.objs = malloc(sizeof(t_shape) * world.objs_count);
	world.lights = malloc(sizeof(t_plight) * world.lights_count);
	world.objs[0] = cone(0);
	world.objs[0].material.color = color(0.5, 1, 0.1);
	world.objs[0].material.diffuse = 0.7;
	world.objs[0].material.specular = 0.3;
	world.objs[0].cyl_min = -1;
	world.objs[0].cyl_max = 1;
	world.objs[0].cyl_closed = 1;
	shape_set_matrix(world.objs, matrix_x_rotation((M_PI/5)));
	world.lights[0] = point_light(point(0, 1.5, -5), color(1, 1, 1));
	t_camera	cam = camera(1280, 720, M_PI / 3);
	camera_set_transform(&cam, view_transform(point(0, 0, -5), point(0, 0, 1), vector(0, 1, 0)));
	t_canva		image = render(cam, world);
	if (!image.canva)
		return (1);
	(void)image;
	char		*ppm = canva_to_ppm(image);
	write_file("render/test.ppm", ppm);
	free(ppm);
	free(image.canva);
	free(world.objs);
	free(world.lights);
}
