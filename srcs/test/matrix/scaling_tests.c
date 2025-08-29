/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:47:53 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/27 14:58:48 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "matrix.h"
#include "tests.h"

static void	scaling_matrix_point_test(void **state)
{
	(void)state;
	assert_tuple_equal(matrix_tuple_mult(matrix_scaling(2, 3, 4), point(-4, 6, 8)), point(-8, 18, 32));
}

static void	scaling_matrix_vector_test(void **state)
{
	(void)state;
	assert_tuple_equal(matrix_tuple_mult(matrix_scaling(2, 3, 4), vector(-4, 6, 8)), vector(-8, 18, 32));
}

static void	scaling_invert_matrix_vector_test(void **state)
{
	(void)state;
	assert_tuple_equal(matrix_tuple_mult(matrix_invert(matrix_scaling(2, 3, 4)), vector(-4, 6, 8)), vector(-2, 2, 2));
}

static void	reflect_by_matrix_scaling_test(void **state)
{
	(void)state;
	assert_tuple_equal(matrix_tuple_mult(matrix_scaling(-1, 1, 1), point(2, 3, 4)), point(-2, 3, 4));
}

int	test_scaling_matrix(void)
{
	const struct CMUnitTest	scaling_matrix_tests[] = {
		cmocka_unit_test(scaling_matrix_point_test),
		cmocka_unit_test(scaling_matrix_vector_test),
		cmocka_unit_test(scaling_invert_matrix_vector_test),
		cmocka_unit_test(reflect_by_matrix_scaling_test),
	};
	return (cmocka_run_group_tests(scaling_matrix_tests, NULL, NULL));
}
