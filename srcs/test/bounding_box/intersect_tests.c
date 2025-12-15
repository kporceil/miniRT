/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:28:20 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/04 12:02:50 by lcesbron         ###   ########lyon.fr   */
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
#include "groups.h"
#include "ray.h"

#ifndef EPSILON
# define EPSILON 0.0001
#endif

static void	bounding_box_intersect_perfect_cube_1_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(-1, -1, -1), point(1, 1, 1));
	t_tuple			direction = normalize(vector(-1, 0, 0));
	t_ray			r = ray(point(5, 0.5, 0), direction);

	assert_true(bb_intersect(b1, r));
}

static void	bounding_box_intersect_perfect_cube_2_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(-1, -1, -1), point(1, 1, 1));
	t_tuple			direction = normalize(vector(1, 0, 0));
	t_ray			r = ray(point(-5, 0.5, 0), direction);

	assert_true(bb_intersect(b1, r));
}

static void	bounding_box_intersect_perfect_cube_3_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(-1, -1, -1), point(1, 1, 1));
	t_tuple			direction = normalize(vector(0, -1, 0));
	t_ray			r = ray(point(0.5, 5, 0), direction);

	assert_true(bb_intersect(b1, r));
}

static void	bounding_box_intersect_perfect_cube_4_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(-1, -1, -1), point(1, 1, 1));
	t_tuple			direction = normalize(vector(0, 1, 0));
	t_ray			r = ray(point(0.5, -5, 0), direction);

	assert_true(bb_intersect(b1, r));
}

static void	bounding_box_intersect_perfect_cube_5_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(-1, -1, -1), point(1, 1, 1));
	t_tuple			direction = normalize(vector(0, 0, -1));
	t_ray			r = ray(point(0.5, 0, 5), direction);

	assert_true(bb_intersect(b1, r));
}

static void	bounding_box_intersect_perfect_cube_6_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(-1, -1, -1), point(1, 1, 1));
	t_tuple			direction = normalize(vector(0, 0, 1));
	t_ray			r = ray(point(0.5, 0, -5), direction);

	assert_true(bb_intersect(b1, r));
}

static void	bounding_box_intersect_perfect_cube_7_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(-1, -1, -1), point(1, 1, 1));
	t_tuple			direction = normalize(vector(0, 0, 1));
	t_ray			r = ray(point(0, 0.5, 0), direction);

	assert_true(bb_intersect(b1, r));
}

static void	bounding_box_intersect_perfect_cube_8_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(-1, -1, -1), point(1, 1, 1));
	t_tuple			direction = normalize(vector(2, 4, 6));
	t_ray			r = ray(point(-2, 0, 0), direction);

	assert_false(bb_intersect(b1, r));
}

static void	bounding_box_intersect_perfect_cube_9_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(-1, -1, -1), point(1, 1, 1));
	t_tuple			direction = normalize(vector(6, 2, 4));
	t_ray			r = ray(point(0, -2, 0), direction);

	assert_false(bb_intersect(b1, r));
}

static void	bounding_box_intersect_perfect_cube_10_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(-1, -1, -1), point(1, 1, 1));
	t_tuple			direction = normalize(vector(4, 6, 2));
	t_ray			r = ray(point(0, 0, -2), direction);

	assert_false(bb_intersect(b1, r));
}

static void	bounding_box_intersect_perfect_cube_11_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(-1, -1, -1), point(1, 1, 1));
	t_tuple			direction = normalize(vector(0, 0, -1));
	t_ray			r = ray(point(2, 0, 2), direction);

	assert_false(bb_intersect(b1, r));
}

static void	bounding_box_intersect_perfect_cube_12_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(-1, -1, -1), point(1, 1, 1));
	t_tuple			direction = normalize(vector(0, -1, 0));
	t_ray			r = ray(point(0, 2, 2), direction);

	assert_false(bb_intersect(b1, r));
}

static void	bounding_box_intersect_perfect_cube_13_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(-1, -1, -1), point(1, 1, 1));
	t_tuple			direction = normalize(vector(-1, 0, 0));
	t_ray			r = ray(point(2, 2, 0), direction);

	assert_false(bb_intersect(b1, r));
}

static void	bounding_box_intersect_unperfect_cube_1_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(5, -2, 0), point(11, 4, 7));
	t_tuple			direction = normalize(vector(-1, 0, 0));
	t_ray			r = ray(point(15, 1, 2), direction);

	assert_true(bb_intersect(b1, r));
}

static void	bounding_box_intersect_unperfect_cube_2_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(5, -2, 0), point(11, 4, 7));
	t_tuple			direction = normalize(vector(1, 0, 0));
	t_ray			r = ray(point(-5, -1, 4), direction);

	assert_true(bb_intersect(b1, r));
}

static void	bounding_box_intersect_unperfect_cube_3_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(5, -2, 0), point(11, 4, 7));
	t_tuple			direction = normalize(vector(0, -1, 0));
	t_ray			r = ray(point(7, 6, 5), direction);

	assert_true(bb_intersect(b1, r));
}

static void	bounding_box_intersect_unperfect_cube_4_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(5, -2, 0), point(11, 4, 7));
	t_tuple			direction = normalize(vector(0, 1, 0));
	t_ray			r = ray(point(9, -5, 6), direction);

	assert_true(bb_intersect(b1, r));
}

static void	bounding_box_intersect_unperfect_cube_5_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(5, -2, 0), point(11, 4, 7));
	t_tuple			direction = normalize(vector(0, 0, -1));
	t_ray			r = ray(point(8, 2, 12), direction);

	assert_true(bb_intersect(b1, r));
}

static void	bounding_box_intersect_unperfect_cube_6_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(5, -2, 0), point(11, 4, 7));
	t_tuple			direction = normalize(vector(0, 0, 1));
	t_ray			r = ray(point(6, 0, -5), direction);

	assert_true(bb_intersect(b1, r));
}

static void	bounding_box_intersect_unperfect_cube_7_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(5, -2, 0), point(11, 4, 7));
	t_tuple			direction = normalize(vector(0, 0, 1));
	t_ray			r = ray(point(8, 1, 3.5), direction);

	assert_true(bb_intersect(b1, r));
}

static void	bounding_box_intersect_unperfect_cube_8_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(5, -2, 0), point(11, 4, 7));
	t_tuple			direction = normalize(vector(2, 4, 6));
	t_ray			r = ray(point(9, -1, -8), direction);

	assert_false(bb_intersect(b1, r));
}

static void	bounding_box_intersect_unperfect_cube_9_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(5, -2, 0), point(11, 4, 7));
	t_tuple			direction = normalize(vector(6, 2, 4));
	t_ray			r = ray(point(8, 3, -4), direction);

	assert_false(bb_intersect(b1, r));
}

static void	bounding_box_intersect_unperfect_cube_10_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(5, -2, 0), point(11, 4, 7));
	t_tuple			direction = normalize(vector(4, 6, 2));
	t_ray			r = ray(point(9, -1, -2), direction);

	assert_false(bb_intersect(b1, r));
}

static void	bounding_box_intersect_unperfect_cube_11_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(5, -2, 0), point(11, 4, 7));
	t_tuple			direction = normalize(vector(0, 0, -1));
	t_ray			r = ray(point(4, 0, 9), direction);

	assert_false(bb_intersect(b1, r));
}

static void	bounding_box_intersect_unperfect_cube_12_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(5, -2, 0), point(11, 4, 7));
	t_tuple			direction = normalize(vector(0, -1, 0));
	t_ray			r = ray(point(8, 6, -1), direction);

	assert_false(bb_intersect(b1, r));
}

static void	bounding_box_intersect_unperfect_cube_13_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(5, -2, 0), point(11, 4, 7));
	t_tuple			direction = normalize(vector(-1, 0, 0));
	t_ray			r = ray(point(12, 5, 4), direction);

	assert_false(bb_intersect(b1, r));
}

int	test_bounding_box_intersect(void)
{
	const struct CMUnitTest	bounding_box_intersect_tests[] = {
		cmocka_unit_test(bounding_box_intersect_perfect_cube_1_test),
		cmocka_unit_test(bounding_box_intersect_perfect_cube_2_test),
		cmocka_unit_test(bounding_box_intersect_perfect_cube_3_test),
		cmocka_unit_test(bounding_box_intersect_perfect_cube_4_test),
		cmocka_unit_test(bounding_box_intersect_perfect_cube_5_test),
		cmocka_unit_test(bounding_box_intersect_perfect_cube_6_test),
		cmocka_unit_test(bounding_box_intersect_perfect_cube_7_test),
		cmocka_unit_test(bounding_box_intersect_perfect_cube_8_test),
		cmocka_unit_test(bounding_box_intersect_perfect_cube_9_test),
		cmocka_unit_test(bounding_box_intersect_perfect_cube_10_test),
		cmocka_unit_test(bounding_box_intersect_perfect_cube_11_test),
		cmocka_unit_test(bounding_box_intersect_perfect_cube_12_test),
		cmocka_unit_test(bounding_box_intersect_perfect_cube_13_test),
		cmocka_unit_test(bounding_box_intersect_unperfect_cube_1_test),
		cmocka_unit_test(bounding_box_intersect_unperfect_cube_2_test),
		cmocka_unit_test(bounding_box_intersect_unperfect_cube_3_test),
		cmocka_unit_test(bounding_box_intersect_unperfect_cube_4_test),
		cmocka_unit_test(bounding_box_intersect_unperfect_cube_5_test),
		cmocka_unit_test(bounding_box_intersect_unperfect_cube_6_test),
		cmocka_unit_test(bounding_box_intersect_unperfect_cube_7_test),
		cmocka_unit_test(bounding_box_intersect_unperfect_cube_8_test),
		cmocka_unit_test(bounding_box_intersect_unperfect_cube_9_test),
		cmocka_unit_test(bounding_box_intersect_unperfect_cube_10_test),
		cmocka_unit_test(bounding_box_intersect_unperfect_cube_11_test),
		cmocka_unit_test(bounding_box_intersect_unperfect_cube_12_test),
		cmocka_unit_test(bounding_box_intersect_unperfect_cube_13_test),
	};
	return (cmocka_run_group_tests(bounding_box_intersect_tests, NULL, NULL));
}
