/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   larger_determinant_tests.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 01:07:39 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/27 01:15:31 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "matrix.h"

static void	matrix3x3_determinant_test(void **state)
{
	t_matrix	m = matrix_create(3);

	(void)state;
	m.matrix[0][0] = 1, m.matrix[0][1] = 2, m.matrix[0][2] = 6;
	m.matrix[1][0] = -5, m.matrix[1][1] = 8, m.matrix[1][2] = -4;
	m.matrix[2][0] = 2, m.matrix[2][1] = 6, m.matrix[2][2] = 4;
	assert_double_equal(matrix_cofactor(m, 0, 0), 56, 0.0001);
	assert_double_equal(matrix_cofactor(m, 0, 1), 12, 0.0001);
	assert_double_equal(matrix_cofactor(m, 0, 2), -46, 0.0001);
	assert_double_equal(matrix_determinant(m), -196, 0.0001);
}

static void	matrix4x4_determinant_test(void **state)
{
	t_matrix	m = matrix_create(4);

	(void)state;
	m.matrix[0][0] = -2, m.matrix[0][1] = -8, m.matrix[0][2] = 3, m.matrix[0][3] = 5;
	m.matrix[1][0] = -3, m.matrix[1][1] = 1, m.matrix[1][2] = 7, m.matrix[1][3] = 3;
	m.matrix[2][0] = 1, m.matrix[2][1] = 2, m.matrix[2][2] = -9, m.matrix[2][3] = 6;
	m.matrix[3][0] = -6, m.matrix[3][1] = 7, m.matrix[3][2] = 7, m.matrix[3][3] = -9;
	assert_double_equal(matrix_cofactor(m, 0, 0), 690, 0.0001);
	assert_double_equal(matrix_cofactor(m, 0, 1), 447, 0.0001);
	assert_double_equal(matrix_cofactor(m, 0, 2), 210, 0.0001);
	assert_double_equal(matrix_cofactor(m, 0, 3), 51, 0.0001);
	assert_double_equal(matrix_determinant(m), -4071, 0.0001);
}

int	test_larger_determinant(void)
{
	const struct CMUnitTest	larger_determinant_tests[] = {
		cmocka_unit_test(matrix3x3_determinant_test),
		cmocka_unit_test(matrix4x4_determinant_test),
	};
	return (cmocka_run_group_tests(larger_determinant_tests, NULL, NULL));
}
