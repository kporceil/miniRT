/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient_pattern_tests.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 00:38:02 by kporceil          #+#    #+#             */
/*   Updated: 2025/09/26 00:42:43 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "patterns.h"
#include "tests.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

static void	gradient_pattern_test(__unused void **state)
{
	t_pattern	pat = pattern(GRADIENT, color(1, 1, 1), color(0, 0, 0));

	assert_color_equal(color(1, 1, 1), pattern_at(pat, point(0, 0, 0)));
	assert_color_equal(color(0.75, 0.75, 0.75), pattern_at(pat, point(0.25, 0, 0)));
	assert_color_equal(color(0.5, 0.5, 0.5), pattern_at(pat, point(0.5, 0, 0)));
	assert_color_equal(color(0.25, 0.25, 0.25), pattern_at(pat, point(0.75, 0, 0)));
}

int	test_gradient_pattern(void)
{
	const struct CMUnitTest	gradient_pattern_tests[] = {
		cmocka_unit_test(gradient_pattern_test),
	};
	return (cmocka_run_group_tests(gradient_pattern_tests, NULL, NULL));
}
