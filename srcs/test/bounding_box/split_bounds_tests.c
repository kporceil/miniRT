/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_bounds_tests.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:18:38 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/02 18:24:43 by lcesbron         ###   ########lyon.fr   */
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

static void	bounding_box_split_bounds_1_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(-1, -4, -5), point(9, 6, 5));
	t_bounding_box	left;
	t_bounding_box	right;

	bb_split_bounds(b1, &left, &right);
	assert_tuple_equal(left.min, point(-1, -4, -5));
	assert_tuple_equal(left.max, point(4, 6, 5));
	assert_tuple_equal(right.min, point(4, -4, -5));
	assert_tuple_equal(right.max, point(9, 6, 5));
}

static void	bounding_box_split_bounds_2_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(-1, -2, -3), point(9, 5.5, 3));
	t_bounding_box	left;
	t_bounding_box	right;

	bb_split_bounds(b1, &left, &right);

	assert_tuple_equal(left.min,  point(-1, -2, -3));
	assert_tuple_equal(left.max,  point(4, 5.5, 3));
	assert_tuple_equal(right.min, point(4, -2, -3));
	assert_tuple_equal(right.max, point(9, 5.5, 3));
}

static void	bounding_box_split_bounds_3_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(-1, -2, -3), point(5, 8, 3));
	t_bounding_box	left;
	t_bounding_box	right;

	bb_split_bounds(b1, &left, &right);

	assert_tuple_equal(left.min,  point(-1, -2, -3));
	assert_tuple_equal(left.max,  point(5, 3, 3));
	assert_tuple_equal(right.min, point(-1, 3, -3));
	assert_tuple_equal(right.max, point(5, 8, 3));
}

static void	bounding_box_split_bounds_4_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(-1, -2, -3), point(5, 3, 7));
	t_bounding_box	left;
	t_bounding_box	right;

	bb_split_bounds(b1, &left, &right);

	assert_tuple_equal(left.min,  point(-1, -2, -3));
	assert_tuple_equal(left.max,  point(5, 3, 2));
	assert_tuple_equal(right.min, point(-1, -2, 2));
	assert_tuple_equal(right.max, point(5, 3, 7));
}

int	test_bounding_box_split_bounds(void)
{
	const struct CMUnitTest	bounding_box_split_bounds_tests[] = {
		cmocka_unit_test(bounding_box_split_bounds_1_test),
		cmocka_unit_test(bounding_box_split_bounds_2_test),
		cmocka_unit_test(bounding_box_split_bounds_3_test),
		cmocka_unit_test(bounding_box_split_bounds_4_test),
	};
	return (cmocka_run_group_tests(bounding_box_split_bounds_tests, NULL, NULL));
}
