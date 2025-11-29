/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unique_identifier_tests.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:58:47 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/28 16:36:31 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "tests.h"
#include "scenes_parsing.h"
#include "world.h"

static void	multi_camera_test(__unused void **state)
{
	t_world	world = world_create();

	assert_int_equal(parse_file("test_assets/multi_camera.rt", &world), -1);
	assert_true(world.had_cam);
}

static void	one_camera_test(__unused void **state)
{
	t_world	world = world_create();

	assert_int_equal(parse_file("test_assets/one_camera.rt", &world), 0);
	assert_true(world.had_cam);
	assert_tuple_equal(world.cam.pos, point(0, 0, 0));
	assert_tuple_equal(world.cam.look_at, point(0, 0, 1));
	assert_double_equal(world.cam.fov, 80 * (M_PI/180), 0.0001);
}

static void	no_camera_test(__unused void **state)
{
	t_world	world = world_create();

	assert_int_equal(parse_file("test_assets/no_camera.rt", &world), -1);
	assert_false(world.had_cam);
}

static void	multi_ambient_test(__unused void **state)
{
	t_world	world = world_create();

	assert_int_equal(parse_file("test_assets/multi_ambient.rt", &world), -1);
	assert_true(world.had_ambient);
	assert_color_equal(color(0.2, 0.2, 0.2), world.ambient);
}

static void	one_ambient_test(__unused void **state)
{
	t_world	world = world_create();

	assert_int_equal(parse_file("test_assets/one_ambient.rt", &world), 0);
	assert_true(world.had_ambient);
	assert_color_equal(color(0.2, 0.1, 0.15), world.ambient);
}

static void	no_ambient_test(__unused void **state)
{
	t_world	world = world_create();

	assert_int_equal(parse_file("test_assets/no_ambient.rt", &world), -1);
	assert_false(world.had_ambient);
}

int	test_unique_identifier(void)
{
	const struct CMUnitTest	unique_identifier_tests[] = {
		cmocka_unit_test(multi_camera_test),
		cmocka_unit_test(one_camera_test),
		cmocka_unit_test(no_camera_test),
		cmocka_unit_test(multi_ambient_test),
		cmocka_unit_test(one_ambient_test),
		cmocka_unit_test(no_ambient_test),
	};
	return (cmocka_run_group_tests(unique_identifier_tests, NULL, NULL));
}
