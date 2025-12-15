/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 22:04:06 by kporceil          #+#    #+#             */
/*   Updated: 2025/12/10 15:51:14 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scenes_parsing.h"
#include "bounding_box.h"
#include "color.h"
#include "matrix.h"
#include "groups.h"
#include "patterns.h"
#include "scenes_parsing.h"
#include "shape.h"
#include "tuples.h"
#include "canvas.h"
#include "libft.h"
#include "light.h"
#include "obj_parser.h"
#include "world.h"
#include "camera.h"
#include "display_mlx.h"
#include "visual_settings.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>

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
	struct timeval	tv_a = (struct timeval){0};
	struct timeval	tv_b = (struct timeval){0};
	t_obj_parsing	p;
	t_shape	g;

	world.lights_count = 1;
	world.objs_count = 1;
	world.objs = malloc(sizeof(t_shape) * world.objs_count);
	world.lights = malloc(sizeof(t_plight) * world.lights_count);
	world.lights[0] = point_light(point(50, 0, 0), color(1, 1, 1));
	world.ambient = color(0.3, 0.3, 0.3);
	p = obj_parser("assets/Satellite.obj");
	g = parsed_to_group(&p);

	shape_set_matrix(&g, matrix_y_rotation(M_PI_2));
	divide(&g, 10);
	t_camera	cam = camera(WIDTH, HEIGHT, 70 * (M_PI / 180), point(30, 5, 0));
	cam.look_at = vector(0, 5, 0);
	camera_set_transform(&cam, view_transform(cam.pos, cam.look_at, cam.up));

	world.objs[0] = g;
	world.buf_inter = malloc(sizeof(t_inter) * count_possible_intersections(&world));

	gettimeofday(&tv_a, NULL);
	t_canva	image = render(cam, world, 1);
	gettimeofday(&tv_b, NULL);

	if (!image.canva)
		return (1);

	display_mlx(image, &cam, world, 1000 * (tv_b.tv_sec - tv_a.tv_sec)
			+ (tv_b.tv_usec - tv_a.tv_usec) / 1000);
	free(image.canva);
	free_world(&world);
}
