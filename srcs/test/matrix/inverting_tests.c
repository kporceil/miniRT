/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverting_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 01:37:26 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/27 02:44:22 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "matrix.h"
#include "tests.h"

static void	is_matrix_invertible_test(void **state)
{
	t_matrix	m1 = matrix_create(4);
	t_matrix	m2 = matrix_create(4);

	(void)state;
	m1.matrix[0][0] = 6, m1.matrix[0][1] = 4, m1.matrix[0][2] = 4, m1.matrix[0][3] = 4;
	m1.matrix[1][0] = 5, m1.matrix[1][1] = 5, m1.matrix[1][2] = 7, m1.matrix[1][3] = 6;
	m1.matrix[2][0] = 4, m1.matrix[2][1] = -9, m1.matrix[2][2] = 3, m1.matrix[2][3] = -7;
	m1.matrix[3][0] = 9, m1.matrix[3][1] = 1, m1.matrix[3][2] = 7, m1.matrix[3][3] = -6;
	m2.matrix[0][0] = -4, m2.matrix[0][1] = 2, m2.matrix[0][2] = -2, m2.matrix[0][3] = -3;
	m2.matrix[1][0] = 9, m2.matrix[1][1] = 6, m2.matrix[1][2] = 2, m2.matrix[1][3] = 6;
	m2.matrix[2][0] = 0, m2.matrix[2][1] = -5, m2.matrix[2][2] = 1, m2.matrix[2][3] = -5;
	m2.matrix[3][0] = 0, m2.matrix[3][1] = 0, m2.matrix[3][2] = 0, m2.matrix[3][3] = 0;
	assert_true(is_matrix_invertible(m1));
	assert_false(is_matrix_invertible(m2));
}

static void	matrix_invert_test1(void **state)
{
	t_matrix	m = matrix_create(4);
	t_matrix	expected_result = matrix_create(4);
	t_matrix	result;

	(void)state;
	m.matrix[0][0] = -5, m.matrix[0][1] = 2, m.matrix[0][2] = 6, m.matrix[0][3] = -8;
	m.matrix[1][0] = 1, m.matrix[1][1] = -5, m.matrix[1][2] = 1, m.matrix[1][3] = 8;
	m.matrix[2][0] = 7, m.matrix[2][1] = 7, m.matrix[2][2] = -6, m.matrix[2][3] = -7;
	m.matrix[3][0] = 1, m.matrix[3][1] = -3, m.matrix[3][2] = 7, m.matrix[3][3] = 4;
	expected_result.matrix[0][0] = 0.21805, expected_result.matrix[0][1] = 0.45113, expected_result.matrix[0][2] = 0.24060, expected_result.matrix[0][3] = -0.04511;
	expected_result.matrix[1][0] = -0.80827, expected_result.matrix[1][1] = -1.45677, expected_result.matrix[1][2] = -0.44361, expected_result.matrix[1][3] = 0.52068;
	expected_result.matrix[2][0] = -0.07895, expected_result.matrix[2][1] = -0.22368, expected_result.matrix[2][2] = -0.05263, expected_result.matrix[2][3] = 0.19737;
	expected_result.matrix[3][0] = -0.52256, expected_result.matrix[3][1] = -0.81391, expected_result.matrix[3][2] = -0.30075, expected_result.matrix[3][3] = 0.30639;
	result = matrix_invert(m);
	assert_double_equal(matrix_determinant(m), 532, 0.0001);
	assert_double_equal(matrix_cofactor(m, 2, 3), -160, 0.0001);
	assert_double_equal(result.matrix[3][2], -160/532, 0.0001);
	assert_double_equal(matrix_cofactor(m, 3, 2), 105, 0.0001);
	assert_double_equal(result.matrix[2][3], 105/532, 0.0001);
	assert_matrix_equal(result, expected_result);
}

static void	matrix_invert_test2(void **state)
{
	t_matrix	m = matrix_create(4);
	t_matrix	expected_result = matrix_create(4);

	(void)state;
	m.matrix[0][0] = 8, m.matrix[0][1] = -5, m.matrix[0][2] = 9, m.matrix[0][3] = 2;
	m.matrix[1][0] = 7, m.matrix[1][1] = 5, m.matrix[1][2] = 6, m.matrix[1][3] = 1;
	m.matrix[2][0] = -6, m.matrix[2][1] = 0, m.matrix[2][2] = 9, m.matrix[2][3] = 6;
	m.matrix[3][0] = -3, m.matrix[3][1] = 0, m.matrix[3][2] = -9, m.matrix[3][3] = -4;
	expected_result.matrix[0][0] = -0.15385, expected_result.matrix[0][1] = -0.15385, expected_result.matrix[0][2] = -0.28205, expected_result.matrix[0][3] = -0.53846;
	expected_result.matrix[1][0] = -0.07692, expected_result.matrix[1][1] = 0.12308, expected_result.matrix[1][2] = 0.02564, expected_result.matrix[1][3] = 0.03077;
	expected_result.matrix[2][0] = 0.35897, expected_result.matrix[2][1] = 0.35897, expected_result.matrix[2][2] = 0.43590, expected_result.matrix[2][3] = 0.92308;
	expected_result.matrix[3][0] = -0.69231, expected_result.matrix[3][1] = -0.69231, expected_result.matrix[3][2] = -0.76923, expected_result.matrix[3][3] = -1.92308;
	assert_matrix_equal(matrix_invert(m), expected_result);
	m.matrix[0][0] = 9, m.matrix[0][1] = 3, m.matrix[0][2] = 0, m.matrix[0][3] = 9;
	m.matrix[1][0] = -5, m.matrix[1][1] = -2, m.matrix[1][2] = -6, m.matrix[1][3] = -3;
	m.matrix[2][0] = -4, m.matrix[2][1] = 9, m.matrix[2][2] = 6, m.matrix[2][3] = 4;
	m.matrix[3][0] = -7, m.matrix[3][1] = 6, m.matrix[3][2] = 6, m.matrix[3][3] = 2;
	expected_result.matrix[0][0] = -0.04074, expected_result.matrix[0][1] = -0.07778, expected_result.matrix[0][2] = 0.14444, expected_result.matrix[0][3] = -0.22222;
	expected_result.matrix[1][0] = -0.07778, expected_result.matrix[1][1] = 0.03333, expected_result.matrix[1][2] = 0.36667, expected_result.matrix[1][3] = -0.33333;
	expected_result.matrix[2][0] = -0.02901, expected_result.matrix[2][1] = -0.14630, expected_result.matrix[2][2] = -0.10926, expected_result.matrix[2][3] = 0.12963;
	expected_result.matrix[3][0] = 0.17778, expected_result.matrix[3][1] = 0.06667, expected_result.matrix[3][2] = -0.26667, expected_result.matrix[3][3] = 0.33333;
	assert_matrix_equal(matrix_invert(m), expected_result);
}

static void	matrix_invert_test3(void **state)
{
	t_matrix	m1 = matrix_create(4);
	t_matrix	m2 = matrix_create(4);

	(void)state;
	m1.matrix[0][0] = 3, m1.matrix[0][1] = -9, m1.matrix[0][2] = 7, m1.matrix[0][3] = 3;
	m1.matrix[1][0] = 3, m1.matrix[1][1] = -8, m1.matrix[1][2] = 2, m1.matrix[1][3] = -9;
	m1.matrix[2][0] = -4, m1.matrix[2][1] = 4, m1.matrix[2][2] = 4, m1.matrix[2][3] = 1;
	m1.matrix[3][0] = -6, m1.matrix[3][1] = 5, m1.matrix[3][2] = -1, m1.matrix[3][3] = 1;
	m2.matrix[0][0] = 8, m2.matrix[0][1] = 2, m2.matrix[0][2] = 2, m2.matrix[0][3] = 2;
	m2.matrix[1][0] = 3, m2.matrix[1][1] = -1, m2.matrix[1][2] = 7, m2.matrix[1][3] = 0;
	m2.matrix[2][0] = 7, m2.matrix[2][1] = 0, m2.matrix[2][2] = 5, m2.matrix[2][3] = 4;
	m2.matrix[3][0] = 6, m2.matrix[3][1] = -2, m2.matrix[3][2] = 0, m2.matrix[3][3] = 5;
	assert_matrix_equal(matrix_mult(matrix_mult(m1, m2), matrix_invert(m2)), m1);
}

int	test_inverting_matrix(void)
{
	const struct CMUnitTest	matrix_inverting_tests[] = {
		cmocka_unit_test(is_matrix_invertible_test),
		cmocka_unit_test(matrix_invert_test1),
		cmocka_unit_test(matrix_invert_test2),
		cmocka_unit_test(matrix_invert_test3),
	};
	return (cmocka_run_group_tests(matrix_inverting_tests, NULL, NULL));
}
