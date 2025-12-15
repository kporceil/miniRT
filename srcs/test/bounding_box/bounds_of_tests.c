/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounds_of_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:13:12 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/01 19:04:07 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <math.h>
#include "tests.h"
#include "bounding_box.h"

static void	bounding_box_bounds_of_sphere_1_test(__unused void **state)
{
	t_bounding_box	b;

	b = bb_bounds_of(sphere(1));
	assert_tuple_equal(b.min, point(-1, -1, -1));
	assert_tuple_equal(b.max, point(1, 1, 1));
}

static void	bounding_box_bounds_of_plane_1_test(__unused void **state)
{
	t_bounding_box	b;

	b = bb_bounds_of(plane(1));
	assert_tuple_equal(b.min, point(-INFINITY, 0, -INFINITY));
	assert_tuple_equal(b.max, point(INFINITY, 0, INFINITY));
}

static void	bounding_box_bounds_of_cube_1_test(__unused void **state)
{
	t_bounding_box	b;

	b = bb_bounds_of(cube(1));
	assert_tuple_equal(b.min, point(-1, -1, -1));
	assert_tuple_equal(b.max, point(1, 1, 1));
}

static void	bounding_box_bounds_of_uncapped_cylinder_1_test(__unused void **state)
{
	t_bounding_box	b;

	b = bb_bounds_of(cylinder(1));
	assert_tuple_equal(b.min, point(-1, -INFINITY, -1));
	assert_tuple_equal(b.max, point(1, INFINITY, 1));
}

static void	bounding_box_bounds_of_capped_cylinder_1_test(__unused void **state)
{
	t_bounding_box	b;
	t_shape			cyl = cylinder(1);

	cyl.cyl_min = -5;
	cyl.cyl_max = 3;
	b = bb_bounds_of(cyl);
	assert_tuple_equal(b.min, point(-1, -5, -1));
	assert_tuple_equal(b.max, point(1, 3, 1));
}

static void	bounding_box_bounds_of_uncapped_cone_1_test(__unused void **state)
{
	t_bounding_box	b;

	b = bb_bounds_of(cone(1));
	assert_tuple_equal(b.min, point(-INFINITY, -INFINITY, -INFINITY));
	assert_tuple_equal(b.max, point(INFINITY, INFINITY, INFINITY));
}

static void	bounding_box_bounds_of_capped_cone_1_test(__unused void **state)
{
	t_bounding_box	b;
	t_shape			cyl = cone(1);

	cyl.cyl_min = -5;
	cyl.cyl_max = 3;
	b = bb_bounds_of(cyl);
	assert_tuple_equal(b.min, point(-5, -5, -5));
	assert_tuple_equal(b.max, point(5, 3, 5));
}

static void	bounding_box_bounds_of_triangle_1_test(__unused void **state)
{
	t_shape	tri = triangle(1, point(-3, 7, 2), point(6, 2, -4), point(2, -1, -1));
	t_bounding_box	b = bb_bounds_of(tri);

	assert_tuple_equal(b.min, point(-3, -1, -4));
	assert_tuple_equal(b.max, point(6, 7, 2));
}

int	test_bounding_box_bounds_of(void)
{
	const struct CMUnitTest	bounding_box_bounds_of_tests[] = {
		cmocka_unit_test(bounding_box_bounds_of_sphere_1_test),
		cmocka_unit_test(bounding_box_bounds_of_plane_1_test),
		cmocka_unit_test(bounding_box_bounds_of_cube_1_test),
		cmocka_unit_test(bounding_box_bounds_of_uncapped_cylinder_1_test),
		cmocka_unit_test(bounding_box_bounds_of_capped_cylinder_1_test),
		cmocka_unit_test(bounding_box_bounds_of_uncapped_cone_1_test),
		cmocka_unit_test(bounding_box_bounds_of_capped_cone_1_test),
		cmocka_unit_test(bounding_box_bounds_of_triangle_1_test),
	};
	return (cmocka_run_group_tests(bounding_box_bounds_of_tests, NULL, NULL));
}
