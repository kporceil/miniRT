/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation_tests.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:21:37 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/27 14:27:59 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "matrix.h"
#include "tests.h"
#include "tuples.h"

static void	translate_point_matrix_test(void **state)
{
	(void)state;
	assert_tuple_equal(matrix_tuple_mult(matrix_translation(5, -3, 2), point(-3, 4, 5)), point(2, 1, 7));
}

static void	translate_point_inverse_matrix_test(void **state)
{
	(void)state;
	assert_tuple_equal(matrix_tuple_mult(matrix_invert(matrix_translation(5, -3, 2)), point(-3, 4, 5)), point(-8, 7, 3));
}

static void	translate_vector_matrix_test(void **state)
{
	(void)state;
	assert_tuple_equal(matrix_tuple_mult(matrix_translation(5, -3, 2), vector(-3, 4, 5)), vector(-3, 4, 5));
}

int	test_translation_matrix(void)
{
	const struct CMUnitTest	translation_matrix_tests[] = {
		cmocka_unit_test(translate_point_matrix_test),
		cmocka_unit_test(translate_point_inverse_matrix_test),
		cmocka_unit_test(translate_vector_matrix_test),
	};
	return (cmocka_run_group_tests(translation_matrix_tests, NULL, NULL));
}
