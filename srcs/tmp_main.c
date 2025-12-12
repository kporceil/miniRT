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

#include <stdio.h>

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
	world.lights[0] = point_light(point(10, 0, 0), color(1, 1, 1));
	p = obj_parser("assets/big_teapot.obj");
	g = parsed_to_group(&p);
	printf("la commande 65\n");
	divide(&g, 100);
	world.objs[0] = g;
	t_camera	cam = camera(WIDTH, HEIGHT, 70 * (M_PI / 180), point(7, 0, 0));
	world.buf_inter = malloc(sizeof(t_inter) * count_possible_intersections(&world));
	printf("la commande 66\n");
	t_canva		image = render(cam, world, 1);
	if (!image.canva)
		return (1);
	gettimeofday(&tv_b, NULL);
	display_mlx(image, &cam, world, 1000 * (tv_a.tv_sec - tv_b.tv_sec)
			+ (tv_a.tv_usec - tv_b.tv_usec) / 1000);
	gettimeofday(&tv_a, NULL);
	free(image.canva);
	free_world(&world);
}
