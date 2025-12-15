/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:18:04 by kporceil          #+#    #+#             */
/*   Updated: 2025/09/12 13:40:27 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <math.h>
#include <stdlib.h>
#include "world.h"
#include "camera.h"
#include "color.h"
#include "canvas.h"
#include "tests.h"

static int	setup(void **state)
{
	t_world	*world = malloc(sizeof(t_world));
	if (!world)
		return (-1);

	world->lights_count = 1;
	world->objs_count = 2;
	world->objs = malloc(sizeof(t_shape) * 2);
	world->lights = malloc(sizeof(t_plight));
	if (!world->objs || !world->lights)
	{
		free(world->objs);
		free(world->lights);
		free(world);
		return (-1);
	}
	world->buf_inter = malloc(sizeof(t_inter) * 4);
	if (!world->buf_inter)
	{
		free(world->objs);
		free(world->lights);
		free(world);
		return (-1);
	}
	world->objs[0] = sphere(0);
	world->objs[1] = sphere(1);
	world->objs[0].material.diffuse = 0.7;
	world->objs[0].material.specular = 0.2;
	world->objs[0].material.color = color(0.8, 1, 0.6);
	world->ambient = color(0.1, 0.1, 0.1);
	shape_set_matrix(world->objs + 1, matrix_scaling(0.5, 0.5, 0.5));
	world->lights[0].intensity = color(1, 1, 1);
	world->lights[0].pos = point(-10, 10, -10);
	*state = world;
	return (0);
}

static int	teardown(void **state)
{
	t_world	*world = *state;

	free(world->buf_inter);
	free(world->lights);
	free(world->objs);
	free(world);
	return (0);
}

static void	camera_render_test(void **state)
{
	t_world		*world = (t_world *)*state;
	t_camera	cam = camera(11, 11, M_PI/2, point(0, 0, -5)) ;
	camera_set_transform(&cam, view_transform_from_to(point(0, 0, -5), point(0, 0, 0), vector(0, 1, 0)));
	t_canva		image = render(cam, *world, 1);

	if (!image.canva)
		fail_msg("Malloc fail");
	assert_color_equal(image.canva[5 + 5 * image.width], color(0.38066, 0.47583, 0.2855));
	free(image.canva);
}

int	test_camera_render(void)
{
	const struct CMUnitTest	camera_render_tests[] = {
		cmocka_unit_test_setup_teardown(camera_render_test, setup, teardown),
	};
	return (cmocka_run_group_tests(camera_render_tests, NULL, NULL));
}
