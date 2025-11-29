/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 22:04:06 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/26 15:29:06 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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
	t_obj_parsing	p;
	struct timeval	tv_a = (struct timeval){0};
	struct timeval	tv_b = (struct timeval){0};

	world.lights_count = 1;
	world.objs_count = 1;
	world.objs = malloc(sizeof(t_shape) * world.objs_count);
	world.lights = malloc(sizeof(t_plight) * world.lights_count);
	printf("begin parsing\n");
	p = obj_parser("./assets/jsp.obj");
	world.objs[0] = parsed_to_group(&p);
	free_obj_parsing(&p);
	printf("finish parsing\n");
	world.lights[0] = point_light(point(50, 50, 15), color(1, 1, 1));
	t_camera	cam = camera(WIDTH, HEIGHT, M_PI / 2, point(20, 20, 0));
	camera_set_transform(&cam, view_transform(cam.pos, cam.look_at, cam.up));
	t_canva		image = render(cam, world, 1);
	if (!image.canva)
		return (1);
	gettimeofday(&tv_b, NULL);
	display_mlx(image, &cam, world, 1000 * (tv_a.tv_sec - tv_b.tv_sec)
			+ (tv_a.tv_usec - tv_b.tv_usec) / 1000);
	gettimeofday(&tv_a, NULL);
	//char		*ppm = canva_to_ppm(image);
	//write_file("render/test.ppm", ppm);
	//free(ppm);
	free(image.canva);
	free_world(&world);
}
