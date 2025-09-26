/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_pattern_tests.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 21:46:14 by kporceil          #+#    #+#             */
/*   Updated: 2025/09/25 23:02:26 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "patterns.h"
#include "tests.h"
#include "shape.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

static void	transformed_pattern_test1(__unused void **state)
{
	t_shape		obj = sphere(0);
	t_pattern	pat = pattern(STRIPED, color(1, 1, 1), color(0, 0, 0));
	shape_set_matrix(&obj, matrix_scaling(2, 2, 2));

	assert_color_equal(pattern_at_object(pat, obj, point(1.5, 0, 0)), color(1, 1, 1));
}

static void	transformed_pattern_test2(__unused void **state)
{
	t_shape		obj = sphere(0);
	t_pattern	pat = pattern(STRIPED, color(1, 1, 1), color(0, 0, 0));
	pattern_set_transform(&pat, matrix_scaling(2, 2, 2));
	
	assert_color_equal(color(1, 1, 1), pattern_at_object(pat, obj, point(1.5, 0 ,0 )));
}

static void	transformed_pattern_test3(__unused void **state)
{
	t_shape		obj = sphere(0);
	t_pattern	pat = pattern(STRIPED, color(1, 1, 1), color(0, 0, 0));
	shape_set_matrix(&obj, matrix_scaling(2, 2, 2));
	pattern_set_transform(&pat, matrix_translation(0.5, 0, 0));

	assert_color_equal(color(1, 1, 1), pattern_at_object(pat, obj, point(2.5, 0, 0)));
}

int	test_transformed_pattern(void)
{
	const struct CMUnitTest	transformed_pattern_tests[] = {
		cmocka_unit_test(transformed_pattern_test1),
		cmocka_unit_test(transformed_pattern_test2),
		cmocka_unit_test(transformed_pattern_test3),
	};
	return (cmocka_run_group_tests(transformed_pattern_tests, NULL, NULL));
}
