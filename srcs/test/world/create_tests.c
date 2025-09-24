/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:38:48 by kporceil          #+#    #+#             */
/*   Updated: 2025/09/12 13:40:27 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include "light.h"
#include "tests.h"
#include "world.h"
#include "shape.h"
#include "ray.h"

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
	world->objs[0] = sphere(0);
	world->objs[1] = sphere(1);
	world->objs[0].material.diffuse = 0.7;
	world->objs[0].material.specular = 0.2;
	world->objs[0].material.color = color(0.8, 1, 0.6);
	shape_set_matrix(world->objs + 1, matrix_scaling(0.5, 0.5, 0.5));
	world->lights[0].intensity = color(1, 1, 1);
	world->lights[0].pos = point(-10, 10, -10);
	*state = world;
	return (0);
}

static int	teardown(void **state)
{
	t_world	*world = *state;

	free(world->lights);
	free(world->objs);
	free(world);
	return (0);
}

static void	create_world_test(void **state)
{
	t_world	world = world_create();

	(void)state;
	assert_int_equal(world.lights, NULL);
	assert_int_equal(world.lights_count, NULL);
	assert_int_equal(world.objs, NULL);
	assert_int_equal(world.objs_count, NULL);
}

static void	world_setup_test(void **state)
{
	t_world	*world = *state;

	assert_int_equal(world->objs_count, 2);
	assert_int_equal(world->lights_count, 1);
	assert_double_equal(world->objs[0].material.diffuse, 0.7, 0.0001);
	assert_double_equal(world->objs[0].material.specular, 0.2, 0.0001);
	assert_color_equal(world->objs[0].material.color, color(0.8, 1.0, 0.6));
	assert_matrix_equal(world->objs[1].transformation, matrix_scaling(0.5, 0.5, 0.5));
	assert_tuple_equal(world->lights[0].pos, point(-10, 10, -10));
	assert_color_equal(world->lights[0].intensity, color(1, 1, 1));
}

int	test_create_world(void)
{
	const struct CMUnitTest	create_world_tests[] = {
		cmocka_unit_test(create_world_test),
		cmocka_unit_test_setup_teardown(world_setup_test, setup, teardown),
	};
	return (cmocka_run_group_tests(create_world_tests, NULL, NULL));
}
