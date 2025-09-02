/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 22:04:06 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/31 15:49:21 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "spheres.h"
#include "tuples.h"
#include "canvas.h"
#include "libft.h"
#include "ray.h"
#include "light.h"
#include "world.h"
#include "camera.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

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
	world.objs_count = 6;
	world.objs = malloc(sizeof(t_sphere) * 6);
	world.lights = malloc(sizeof(t_plight));
	world.objs[0] = sphere(0);
	world.objs[0].material.color = color(1, 0.9, 0.9);
	world.objs[0].material.specular = 0;
	sphere_set_matrix(world.objs, matrix_scaling(10, 0.01, 10));
	world.objs[1] = sphere(1);
	world.objs[1].material = world.objs[0].material;
	sphere_set_matrix(world.objs + 1, matrix_mult(matrix_mult(matrix_mult(matrix_translation(0, 0, 5), matrix_y_rotation(-(M_PI / 4))), matrix_x_rotation(M_PI/2)), matrix_scaling(10, 0.1, 10)));
	world.objs[2] = sphere(2);
	world.objs[2].material = world.objs[0].material;
	sphere_set_matrix(world.objs + 2, matrix_mult(matrix_mult(matrix_mult(matrix_translation(0, 0, 5), matrix_y_rotation(M_PI / 4)), matrix_x_rotation(M_PI/2)), matrix_scaling(10, 0.1, 10)));
	world.objs[3] = sphere(3);
	world.objs[3].material.color = color(0.1, 1, 0.5);
	world.objs[3].material.diffuse = 0.7;
	world.objs[3].material.specular = 0.3;
	sphere_set_matrix(world.objs + 3, matrix_translation(-0.5, 1, 0.5));
	world.objs[4] = sphere(4);
	world.objs[4].material.color = color(0.5, 1, 0.1);
	world.objs[4].material.diffuse = 0.7;
	world.objs[4].material.specular = 0.3;
	sphere_set_matrix(world.objs + 4, matrix_mult(matrix_translation(1.5, 0.5, -0.5), matrix_scaling(0.5, 0.5, 0.5)));
	world.objs[5] = sphere(5);
	world.objs[5].material.color = color(1, 0.8, 0.1);
	world.objs[5].material.diffuse = 0.7;
	world.objs[5].material.specular = 0.3;
	sphere_set_matrix(world.objs + 5, matrix_mult(matrix_translation(-1.5, 0.33, -0.75), matrix_scaling(0.33, 0.33, 0.33)));
	world.lights[0] = point_light(point(-10, 10, -10), color(1, 1, 1));
	t_camera	cam = camera(1920, 1080, M_PI / 3);
	camera_set_transform(&cam, view_transform(point(0, 1.5, -5), point(0, 1, 0), vector(0, 1, 0)));
	t_canva		image = render(cam, world);
	(void)image;
	//char		*ppm = canva_to_ppm(image);
	//write_file("render/first_scenes.ppm", ppm);
}
