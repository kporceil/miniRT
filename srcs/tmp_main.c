/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 22:04:06 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/20 20:20:03 by lcesbron         ###   ########lyon.fr   */
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

static t_shape	hex_corner(size_t id)
{
	t_shape	ret;

	ret = sphere(id);
	shape_set_matrix(&ret, matrix_mult(matrix_translation(0, 0, -1), matrix_scaling(0.25, 0.25, 0.25)));
	return (ret);
}

static t_shape	hex_edge(size_t id)
{
	t_shape	edge = cylinder(id);

	edge.cyl_min = 0;
	edge.cyl_max = 1;
	shape_set_matrix(&edge, matrix_mult(matrix_mult(matrix_mult(matrix_translation(0, 0, -1), matrix_y_rotation(-M_PI/6)), matrix_z_rotation(-M_PI/2)), matrix_scaling(0.25, 1, 0.25)));
	//shape_set_matrix(&edge, matrix_mult(matrix_mult(matrix_mult(matrix_scaling(0.25, 1, 0.25), matrix_z_rotation(-M_PI/2)), matrix_y_rotation(-M_PI/6)), matrix_translation(0, 0, -1)));
	return (edge);
}

static t_shape	hex_side(size_t id)
{
	t_shape	side = group(id, 2);

	group_add_shape(&side, hex_corner(id + 1));
	group_add_shape(&side, hex_edge(id + 2));
	return (side);
}

static t_shape	hexagon(size_t id)
{
	unsigned char	n = 0;
	t_shape			hex = group(id, 6);

	while (n <= 5)
	{
		group_add_shape(&hex, hex_side(n * 3));
		group_set_matrix(hex.child + (hex.nb_members - 1), matrix_y_rotation((n * M_PI) / 3));
		++n;
	}
	//group_set_matrix(&hex, matrix_translation(0, 0, -0.5));
	return (hex);
}

int	main(void)
{
	t_world	world = world_create();
	(void)hexagon;

	world.lights_count = 1;
	world.objs_count = 1;
	world.objs = malloc(sizeof(t_shape) * world.objs_count);
	world.lights = malloc(sizeof(t_plight) * world.lights_count);
	world.objs[0] = hexagon(300);
	//group_add_shape(world.objs, sphere(2));
	//double pi = M_PI;
	group_set_matrix(world.objs, matrix_x_rotation(M_PI/2));
	//group_set_matrix(world.objs, matrix_translation(1, 0, 0));
	//shape_set_matrix(world.objs->child, matrix_translation(0, 0, 5));
	//group_add_shape(world.objs, sphere(2));
	//shape_set_matrix(world.objs->child, matrix_scaling(1, 2, 1));
	//group_add_shape(world.objs, cylinder(3));
	//world.objs->child[1].cyl_min = 0;
	//world.objs->child[1].cyl_max = 1;
	//shape_set_matrix(world.objs->child + 1, matrix_mult(matrix_translation(1, 0, 0), matrix_z_rotation(-M_PI/2)));
	//group_set_matrix(world.objs, matrix_scaling(1.5, 1.5, 1.5));
	world.lights[0] = point_light(point(0, 10, 0), color(1, 1, 1));
	t_camera	cam = camera(1000, 1000, M_PI / 2);
	camera_set_transform(&cam, view_transform(point(2, 2, 0), point(0, 0, 0), vector(0, 1, 0)));
	t_canva		image = render(cam, world);
	if (!image.canva)
		return (1);
	display_mlx(image, cam, world);
	//char		*ppm = canva_to_ppm(image);
	//write_file("render/test.ppm", ppm);
	//free(ppm);
	free(image.canva);
	free(world.objs);
	free(world.lights);
}
