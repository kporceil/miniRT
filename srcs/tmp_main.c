/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 22:04:06 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/13 14:10:44 by lcesbron         ###   ########lyon.fr   */
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
#include "display_mlx.h"
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
	world.objs_count = 6;
	world.objs = malloc(sizeof(t_shape) * world.objs_count);
	world.lights = malloc(sizeof(t_plight) * world.lights_count);
	world.objs[0] = sphere(0);
	world.objs[0].material.pat = pattern(GRADIENT, color(0.1, 0.5, 1), color(0.1, 1, 0.5));
	pattern_set_transform(&world.objs[0].material.pat, matrix_mult(matrix_translation(-1, 0, 0), matrix_scaling(2, 2, 2)));
	world.objs[0].material.color = color(0.1, 1, 0.5);
	world.objs[0].material.diffuse = 0.7;
	world.objs[0].material.specular = 0.3;
	shape_set_matrix(world.objs, matrix_translation(-0.5, 1, 0.5));
	world.objs[1] = sphere(1);
	world.objs[1].material.pat = pattern(RING, color(0.5, 1, 0.1), color(1, 0.5, 0.1));
	pattern_set_transform(&world.objs[1].material.pat, matrix_mult(matrix_mult(matrix_x_rotation(M_PI/2), matrix_z_rotation(M_PI/1.2)), matrix_scaling(0.1, 0.1, 0.1)));
	world.objs[1].material.color = color(0.5, 1, 0.1);
	world.objs[1].material.diffuse = 0.7;
	world.objs[1].material.specular = 0.3;
	shape_set_matrix(world.objs + 1, matrix_mult(matrix_translation(1.2, 0.7, -0.5), matrix_scaling(0.7, 0.7, 0.7)));
	world.objs[2] = sphere(2);
	world.objs[2].material.color = color(1, 0.8, 0.1);
	world.objs[2].material.diffuse = 0.7;
	world.objs[2].material.specular = 0.3;
	shape_set_matrix(world.objs + 2, matrix_mult(matrix_translation(-1.5, 0.33, -0.75), matrix_scaling(0.33, 0.33, 0.33)));
	world.objs[3] = plane(3);
	world.objs[3].material.pat = pattern(CHECKER, color(0, 0, 0), color(1, 1, 1));
	world.objs[3].material.reflective = 0.4;
	world.objs[3].material.color = color(0, 0, 0);
	world.objs[4] = plane(4);
	world.objs[4].material.color = color(0, 0, 0);
	world.objs[4].material.ambient = 0.6;
	world.objs[4].material.reflective = 1;
	shape_set_matrix(world.objs + 4, matrix_mult(matrix_translation(0, 0, 12), matrix_mult(matrix_y_rotation(-(M_PI/12)), matrix_z_rotation(M_PI/2))));
	world.objs[5] = plane(5);
	world.objs[5].material.color = color(0, 0, 0);
	world.objs[5].material.reflective = 1;
	world.objs[5].material.ambient = 0.6;
	shape_set_matrix(world.objs + 5, matrix_mult(matrix_translation(-3, 0, 0), matrix_mult(matrix_y_rotation(M_PI/12), matrix_z_rotation(M_PI/2))));
	world.lights[0] = point_light(point(-2, 10, -5), color(1, 1, 1));
	t_camera	cam = camera(1920, 1080, M_PI / 2);
	camera_set_transform(&cam, view_transform(point(0, 1, -7), point(0, 1, 0), vector(0, 1, 0)));
	display_mlx(cam, world);
//	t_canva		image = render(cam, world);
//	if (!image.canva)
		//return (1);
	//(void)image;
	//char		*ppm = canva_to_ppm(image);
	//display_mlx(image);
	//write_file("render/test.ppm", ppm);
	//free(ppm);
	//free(image.canva);
	free(world.objs);
	free(world.lights);
}
