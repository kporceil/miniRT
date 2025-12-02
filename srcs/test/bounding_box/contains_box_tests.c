/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contains_box_tests.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 09:43:02 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/02 10:10:05 by lcesbron         ###   ########lyon.fr   */
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

static void	bounding_box_contains_box_1_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(5, -2, 0), point(11, 4, 7));
	t_bounding_box	b2 = bounding_box(true, point(5, -2, 0), point(11, 4, 7));

	assert_true(bb_contains_box(b1, b2));
}

static void	bounding_box_contains_box_2_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(5, -2, 0), point(11, 4, 7));
	t_bounding_box	b2 = bounding_box(true, point(6, -1, 1), point(10, 3, 6));

	assert_true(bb_contains_box(b1, b2));
}

static void	bounding_box_contains_box_3_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(5, -2, 0), point(11, 4, 7));
	t_bounding_box	b2 = bounding_box(true, point(4, -3, -1), point(10, 3, 6));

	assert_false(bb_contains_box(b1, b2));
}

static void	bounding_box_contains_box_4_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(5, -2, 0), point(11, 4, 7));
	t_bounding_box	b2 = bounding_box(true, point(6, -1, 1), point(12, 5, 8));

	assert_false(bb_contains_box(b1, b2));
}

int	test_bounding_box_contains_box(void)
{
	const struct CMUnitTest	bounding_box_contains_box_tests[] = {
		cmocka_unit_test(bounding_box_contains_box_1_test),
		cmocka_unit_test(bounding_box_contains_box_2_test),
		cmocka_unit_test(bounding_box_contains_box_3_test),
		cmocka_unit_test(bounding_box_contains_box_4_test),
	};
	return (cmocka_run_group_tests(bounding_box_contains_box_tests, NULL, NULL));
}
