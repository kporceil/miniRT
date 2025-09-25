/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring_pattern_tests.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 00:28:24 by kporceil          #+#    #+#             */
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

static void	ring_pattern_test(__unused void **state)
{
	t_pattern	pat = pattern(RING, color(1, 1, 1), color(0, 0, 0));
	
	assert_color_equal(color(1, 1, 1), pattern_at(pat, point(0, 0, 0)));
	assert_color_equal(color(0, 0, 0), pattern_at(pat, point(1, 0, 0)));
	assert_color_equal(color(0, 0, 0), pattern_at(pat, point(0, 0, 1)));
	assert_color_equal(color(0, 0, 0), pattern_at(pat, point(0.708, 0, 0.708)));
}

int	test_ring_pattern(void)
{
	const struct CMUnitTest	ring_pattern_tests[] = {
		cmocka_unit_test(ring_pattern_test),
	};
	return (cmocka_run_group_tests(ring_pattern_tests, NULL, NULL));
}
