/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_pattern_tests.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 00:49:42 by kporceil          #+#    #+#             */
/*   Updated: 2025/09/26 00:56:25 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "patterns.h"
#include "tests.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

static void	checker_pattern_x_test(__unused void **state)
{
	t_pattern	pat = pattern(CHECKER, color(1, 1, 1), color(0, 0, 0));

	assert_color_equal(color(1, 1, 1), pattern_at(pat, point(0, 0, 0)));
	assert_color_equal(color(1, 1, 1), pattern_at(pat, point(0.99, 0, 0)));
	assert_color_equal(color(0, 0, 0), pattern_at(pat, point(1.01, 0, 0)));
}

static void	checker_pattern_y_test(__unused void **state)
{
	t_pattern	pat = pattern(CHECKER, color(1, 1, 1), color(0, 0, 0));

	assert_color_equal(color(1, 1, 1), pattern_at(pat, point(0, 0, 0)));
	assert_color_equal(color(1, 1, 1), pattern_at(pat, point(0, 0.99, 0)));
	assert_color_equal(color(0, 0, 0), pattern_at(pat, point(0, 1.01, 0)));
}

static void	checker_pattern_z_test(__unused void **state)
{
	t_pattern	pat = pattern(CHECKER, color(1, 1, 1), color(0, 0, 0));

	assert_color_equal(color(1, 1, 1), pattern_at(pat, point(0, 0, 0)));
	assert_color_equal(color(1, 1, 1), pattern_at(pat, point(0, 0, 0.99)));
	assert_color_equal(color(0, 0, 0), pattern_at(pat, point(0, 0, 1.01)));
}

int	test_checker_pattern(void)
{
	const struct CMUnitTest	checker_pattern_tests[] = {
		cmocka_unit_test(checker_pattern_x_test),
		cmocka_unit_test(checker_pattern_y_test),
		cmocka_unit_test(checker_pattern_z_test),
	};
	return (cmocka_run_group_tests(checker_pattern_tests, NULL, NULL));
}
