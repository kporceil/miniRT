/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contains_point_tests.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 09:31:26 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/02 09:41:53 by lcesbron         ###   ########lyon.fr   */
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

static void	bounding_box_contains_point_1_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(5, -2, 0), point(11, 4, 7));
	t_tuple			p = point(5, -2, 0);

	assert_true(bb_contains_point(b1, p));
}

static void	bounding_box_contains_point_2_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(5, -2, 0), point(11, 4, 7));
	t_tuple			p = point(11, 4, 7);

	assert_true(bb_contains_point(b1, p));
}

static void	bounding_box_contains_point_3_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(5, -2, 0), point(11, 4, 7));
	t_tuple			p = point(8, 1, 3);

	assert_true(bb_contains_point(b1, p));
}

static void	bounding_box_contains_point_4_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(5, -2, 0), point(11, 4, 7));
	t_tuple			p = point(3, 0, 3);

	assert_false(bb_contains_point(b1, p));
}

static void	bounding_box_contains_point_5_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(5, -2, 0), point(11, 4, 7));
	t_tuple			p = point(8, -4, 3);

	assert_false(bb_contains_point(b1, p));
}

static void	bounding_box_contains_point_6_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(5, -2, 0), point(11, 4, 7));
	t_tuple			p = point(8, 1, -1);

	assert_false(bb_contains_point(b1, p));
}

static void	bounding_box_contains_point_7_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(5, -2, 0), point(11, 4, 7));
	t_tuple			p = point(13, 1, 3);

	assert_false(bb_contains_point(b1, p));
}

static void	bounding_box_contains_point_8_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(5, -2, 0), point(11, 4, 7));
	t_tuple			p = point(8, 5, 3);

	assert_false(bb_contains_point(b1, p));
}

static void	bounding_box_contains_point_9_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(5, -2, 0), point(11, 4, 7));
	t_tuple			p = point(8, 1, 8);

	assert_false(bb_contains_point(b1, p));
}

int	test_bounding_box_contains_point(void)
{
	const struct CMUnitTest	bounding_box_contains_point_tests[] = {
		cmocka_unit_test(bounding_box_contains_point_1_test),
		cmocka_unit_test(bounding_box_contains_point_2_test),
		cmocka_unit_test(bounding_box_contains_point_3_test),
		cmocka_unit_test(bounding_box_contains_point_4_test),
		cmocka_unit_test(bounding_box_contains_point_5_test),
		cmocka_unit_test(bounding_box_contains_point_6_test),
		cmocka_unit_test(bounding_box_contains_point_7_test),
		cmocka_unit_test(bounding_box_contains_point_8_test),
		cmocka_unit_test(bounding_box_contains_point_9_test),
	};
	return (cmocka_run_group_tests(bounding_box_contains_point_tests, NULL, NULL));
}
