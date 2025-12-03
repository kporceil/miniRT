/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_shadowed_tests.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:18:57 by kporceil          #+#    #+#             */
/*   Updated: 2025/09/12 13:40:27 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include "tests.h"
#include "light.h"
#include "world.h"

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

static void	no_shadowed_test(void **state)
{
	t_world	*w = (t_world *)*state;
	assert_false(is_shadowed(*w, point(0, 10, 0), 0));
}

static void	shadowed_test(void **state)
{
	t_world	*w = (t_world *)*state;
	assert_true(is_shadowed(*w, point(10, -10, 10), 0));
}

static void	object_behind_light_test(void **state)
{
	t_world	*w = (t_world *)*state;
	assert_false(is_shadowed(*w, point(-20, 20, -20), 0));
}

static void	object_behind_point_test(void **state)
{
	t_world	*w = (t_world *)*state;
	assert_false(is_shadowed(*w, point(-2, 2, -2), 0));
}

int	test_is_shadowed(void)
{
	const struct CMUnitTest	is_shadowed_tests[] = {
		cmocka_unit_test_setup_teardown(no_shadowed_test, setup, teardown),
		cmocka_unit_test_setup_teardown(shadowed_test, setup, teardown),
		cmocka_unit_test_setup_teardown(object_behind_light_test, setup, teardown),
		cmocka_unit_test_setup_teardown(object_behind_point_test, setup, teardown),
	};
	return (cmocka_run_group_tests(is_shadowed_tests, NULL, NULL));
}
