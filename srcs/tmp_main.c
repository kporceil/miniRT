/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 22:04:06 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/06 14:01:52 by lcesbron         ###   ########lyon.fr   */
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

static t_shape	hex_corner(size_t id)
{
	t_shape	ret;

	ret = sphere(id);
	shape_set_matrix(&ret, matrix_mult(matrix_mult(matrix_translation(0, 0, -1), matrix_scaling(0.25, 0.25, 0.25)), matrix_y_rotation(-M_PI/6)));
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

//static t_shape	pyramid(size_t id)
//{
//	t_shape	pyr = group(id, 4);
//
//	group_add_shape(&pyr, triangle(id + 1, point(-0.5, 0, -0.5), point(0.5, 0, -0.5), point(0, 0, 0.5)));
//	group_add_shape(&pyr, triangle(id + 1, point(0, 1, 0), point(0.5, 0, -0.5), point(0, 0, 0.5)));
//	group_add_shape(&pyr, triangle(id + 1, point(-0.5, 0, -0.5), point(0, 1, 0), point(0, 0, 0.5)));
//	group_add_shape(&pyr, triangle(id + 1, point(-0.5, 0, -0.5), point(0.5, 0, -0.5), point(0, 1, 0)));
//	return (pyr);
//}

int	main(void)
{
	t_world	world = world_create();
	(void)hexagon;
	struct timeval	tv_a = (struct timeval){0};
	struct timeval	tv_b = (struct timeval){0};

	world.lights_count = 1;
	world.objs_count = 2;
	world.objs = malloc(sizeof(t_shape) * world.objs_count);
	world.lights = malloc(sizeof(t_plight) * world.lights_count);
	world.buf_inter = malloc(sizeof(t_inter) * world.objs_count * 2);
	//world.objs[0] = sphere(0);
//	world.objs[0].material.pat = pattern(GRADIENT, color(0.1, 0.5, 1), color(0.1, 1, 0.5));
//	pattern_set_transform(&world.objs[0].material.pat, matrix_mult(matrix_translation(-1, 0, 0), matrix_scaling(2, 2, 2)));
	//world.objs[0].material.transparency = 1;
	//world.objs[0].material.refractive_index = 1.5;
	//world.objs[0].material.color = color(0.1, 1, 0.5);
	//world.objs[0].material.diffuse = 0.0;
	//world.objs[0].material.ambient = 0.0;
	//world.objs[0].material.specular = 0.0;
	//shape_set_matrix(world.objs, matrix_translation(-0.5, 1, 0.5));
	//world.objs[1] = sphere(1);
	//world.objs[1].material.color = color(0.5, 1, 0.1);
	//world.objs[1].material.diffuse = 0.7;
	//world.objs[1].material.specular = 0.3;
	//shape_set_matrix(world.objs + 1, matrix_mult(matrix_translation(1.2, 0.7, -0.5), matrix_scaling(0.7, 0.7, 0.7)));
	//world.objs[2] = sphere(2);
	//world.objs[2].material.color = color(1, 0.8, 0.1);
	//world.objs[2].material.diffuse = 0.7;
	//world.objs[2].material.specular = 0.3;
	//shape_set_matrix(world.objs + 2, matrix_mult(matrix_translation(-1.5, 0.33, -0.75), matrix_scaling(0.33, 0.33, 0.33)));
	//world.objs[0] = plane(0);
	//world.objs[0].material.pat = pattern(CHECKER, color(0, 0, 0), color(1, 1, 1));
	//world.objs[0].material.color = color(0, 0, 0);
	//shape_set_matrix(world.objs, matrix_mult(matrix_translation(0, 0, 3), matrix_x_rotation(M_PI/2)));
	world.objs[0] = cube(0);
	//world.objs[0].cyl_closed = true;
	//world.objs[0].cyl_max = 1;
	//world.objs[0].cyl_min = -1;
	//t_color	red = color(1, 0, 0);
	//t_color	yellow = color(1, 1, 0);
	//t_color	brown = color(1, 0.5, 0);
	//t_color	green = color(0, 1, 0);
	//t_color	cyan = color(0, 1, 1);
	//t_color	blue = color(0, 0, 1);
	//t_color	purple = color(1, 0, 1);
	//t_color	white = color(1, 1, 1);
	t_uvpat	left = uv_image(ppm_to_canva("assets/lancellottichapel/negx.ppm"));
	t_uvpat	front = uv_image(ppm_to_canva("assets/lancellottichapel/posz.ppm"));
	t_uvpat	right = uv_image(ppm_to_canva("assets/lancellottichapel/posx.ppm"));
	t_uvpat	back = uv_image(ppm_to_canva("assets/lancellottichapel/negz.ppm"));
	t_uvpat	up = uv_image(ppm_to_canva("assets/lancellottichapel/posy.ppm"));
	t_uvpat	down = uv_image(ppm_to_canva("assets/lancellottichapel/negy.ppm"));
	t_pattern       pat = cube_pattern((t_uvpat [6]){front, back, right, left, up, down});
	world.objs[0].material.color = color(0, 0, 0);
	world.objs[0].material.pat = pat;
	//world.objs[0].material.pat = pattern(CHECKER, color(0.8, 0.8, 0.8), color(0.1, 0.4, 0.2));
	world.objs[0].material.ambient = 1;
	world.objs[0].material.diffuse = 0;
	world.objs[0].material.specular = 0;
	//pattern_set_transform(&world.objs[0].material.pat, matrix_scaling(0.2, 0.2, 0.2));
	shape_set_matrix(world.objs + 0, matrix_scaling(100, 100, 100));
	world.objs[1] = sphere(1);
	world.objs[1].material.color = color(0.4, 0.4, 0.4);
	world.objs[1].material.reflective = 0.7;
	//world.objs[2] = sphere(2);
	//world.objs[2].material.color = color(0, 0, 0);
	//world.objs[2].material.transparency = 1;
	//world.objs[2].material.reflective = 1;
	//world.objs[2].material.refractive_index = 1;
	//world.objs[2].material.specular = 0;
	//shape_set_matrix(world.objs + 2, matrix_mult(matrix_translation(10, 10, -3), matrix_scaling(0.5, 0.5, 0.5)));
	//world.objs[4] = plane(4);
	//world.objs[4].material.color = color(0.7, 0.4, 0.3);
	//world.objs[4].material.ambient = 0.6;
	//shape_set_matrix(world.objs + 4, matrix_mult(matrix_translation(0, 0, 12), matrix_mult(matrix_y_rotation(-(M_PI/12)), matrix_z_rotation(M_PI/2))));
	//world.objs[5] = plane(5);
	//world.objs[5].material.color = color(0.2, 0.6, 0.4);
	//world.objs[5].material.ambient = 0.6;
	//shape_set_matrix(world.objs + 5, matrix_mult(matrix_translation(-3, 0, 0), matrix_mult(matrix_y_rotation(M_PI/12), matrix_z_rotation(M_PI/2))));
	world.lights[0] = point_light(point(-2, 10, -5), color(1, 1, 1));
	t_camera	cam = camera(1920, 1080, M_PI / 2, point(0, 2, 1));
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
