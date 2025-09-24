/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparison_tests.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:51:03 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/26 17:27:49 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "matrix.h"

static void	matrix4x4_good_comparison_test(void **state)
{
	t_matrix	m1 = matrix_create(4);
	t_matrix	m2 = matrix_create(4);

	(void)state;
	m2.matrix[0][0] = 1, m1.matrix[0][0] = 1;
	m2.matrix[0][1] = 2, m1.matrix[0][1] = 2;
	m2.matrix[0][2] = 3, m1.matrix[0][2] = 3;
	m2.matrix[0][3] = 4, m1.matrix[0][3] = 4;
	m2.matrix[1][0] = 5, m1.matrix[1][0] = 5;
	m2.matrix[1][1] = 6, m1.matrix[1][1] = 6;
	m2.matrix[1][2] = 7, m1.matrix[1][2] = 7;
	m2.matrix[1][3] = 8, m1.matrix[1][3] = 8;
	m2.matrix[2][0] = 9, m1.matrix[2][0] = 9;
	m2.matrix[2][1] = 8, m1.matrix[2][1] = 8;
	m2.matrix[2][2] = 7, m1.matrix[2][2] = 7;
	m2.matrix[2][3] = 6, m1.matrix[2][3] = 6;
	m2.matrix[3][0] = 5, m1.matrix[3][0] = 5;
	m2.matrix[3][1] = 4, m1.matrix[3][1] = 4;
	m2.matrix[3][2] = 3, m1.matrix[3][2] = 3;
	m2.matrix[3][3] = 2, m1.matrix[3][3] = 2;
	assert_int_equal(matrix_compare(m1, m2), 0);
}

static void	matrix4x4_bad_comparison_test(void **state)
{
	t_matrix	m1 = matrix_create(4);
	t_matrix	m2 = matrix_create(4);

	(void)state;
	m2.matrix[0][0] = 1, m1.matrix[0][0] = 1;
	m2.matrix[0][1] = 2, m1.matrix[0][1] = 2;
	m2.matrix[0][2] = 3, m1.matrix[0][2] = 3;
	m2.matrix[0][3] = 4, m1.matrix[0][3] = 4;
	m2.matrix[1][0] = 5, m1.matrix[1][0] = 5;
	m2.matrix[1][1] = 10, m1.matrix[1][1] = 6;
	m2.matrix[1][2] = 7, m1.matrix[1][2] = 7;
	m2.matrix[1][3] = 8, m1.matrix[1][3] = 8;
	m2.matrix[2][0] = 9, m1.matrix[2][0] = 9;
	m2.matrix[2][1] = 8, m1.matrix[2][1] = 8;
	m2.matrix[2][2] = 7, m1.matrix[2][2] = 7;
	m2.matrix[2][3] = 6, m1.matrix[2][3] = 6;
	m2.matrix[3][0] = 5, m1.matrix[3][0] = 5;
	m2.matrix[3][1] = 4, m1.matrix[3][1] = 4;
	m2.matrix[3][2] = 3, m1.matrix[3][2] = 3;
	m2.matrix[3][3] = 2, m1.matrix[3][3] = 2;
	assert_int_equal(matrix_compare(m1, m2), -1);
}

static void	matrix3x3_good_comparison_test(void **state)
{
	t_matrix	m1 = matrix_create(3);
	t_matrix	m2 = matrix_create(3);

	(void)state;
	m2.matrix[0][0] = 1, m1.matrix[0][0] = 1;
	m2.matrix[0][1] = 2, m1.matrix[0][1] = 2;
	m2.matrix[0][2] = 3, m1.matrix[0][2] = 3;
	m2.matrix[1][0] = 5, m1.matrix[1][0] = 5;
	m2.matrix[1][1] = 6, m1.matrix[1][1] = 6;
	m2.matrix[1][2] = 7, m1.matrix[1][2] = 7;
	m2.matrix[2][0] = 9, m1.matrix[2][0] = 9;
	m2.matrix[2][1] = 8, m1.matrix[2][1] = 8;
	m2.matrix[2][2] = 7, m1.matrix[2][2] = 7;
	assert_int_equal(matrix_compare(m1, m2), 0);
}

static void	matrix3x3_bad_comparison_test(void **state)
{
	t_matrix	m1 = matrix_create(3);
	t_matrix	m2 = matrix_create(3);

	(void)state;
	m2.matrix[0][0] = 1, m1.matrix[0][0] = 1;
	m2.matrix[0][1] = 2, m1.matrix[0][1] = 2;
	m2.matrix[0][2] = 3, m1.matrix[0][2] = 3;
	m2.matrix[1][0] = 5, m1.matrix[1][0] = 5;
	m2.matrix[1][1] = -2, m1.matrix[1][1] = 6;
	m2.matrix[1][2] = 7, m1.matrix[1][2] = 7;
	m2.matrix[2][0] = 9, m1.matrix[2][0] = 9;
	m2.matrix[2][1] = 8, m1.matrix[2][1] = 8;
	m2.matrix[2][2] = 7, m1.matrix[2][2] = 7;
	assert_int_equal(matrix_compare(m1, m2), -1);
}

static void	matrix2x2_good_comparison_test(void **state)
{
	t_matrix	m1 = matrix_create(2);
	t_matrix	m2 = matrix_create(2);

	(void)state;
	m2.matrix[0][0] = 1, m1.matrix[0][0] = 1;
	m2.matrix[0][1] = 2, m1.matrix[0][1] = 2;
	m2.matrix[1][0] = 5, m1.matrix[1][0] = 5;
	m2.matrix[1][1] = 6, m1.matrix[1][1] = 6;
	assert_int_equal(matrix_compare(m1, m2), 0);
}

static void	matrix2x2_bad_comparison_test(void **state)
{
	t_matrix	m1 = matrix_create(2);
	t_matrix	m2 = matrix_create(2);

	(void)state;
	m2.matrix[0][0] = 1, m1.matrix[0][0] = 1;
	m2.matrix[0][1] = 5, m1.matrix[0][1] = 2;
	m2.matrix[1][0] = 5, m1.matrix[1][0] = 5;
	m2.matrix[1][1] = 6, m1.matrix[1][1] = 6;
	assert_int_equal(matrix_compare(m1, m2), -1);
}

static void	different_size_matrix_comparison_test(void **state)
{
	t_matrix	m1 = matrix_create(4);
	t_matrix	m2 = matrix_create(2);

	(void)state;
	assert_int_equal(matrix_compare(m1, m2), -1);
}

int	test_matrix_comparison(void)
{
	const struct CMUnitTest	matrix_comparison_tests[] = {
		cmocka_unit_test(matrix2x2_good_comparison_test),
		cmocka_unit_test(matrix2x2_bad_comparison_test),
		cmocka_unit_test(matrix3x3_good_comparison_test),
		cmocka_unit_test(matrix3x3_bad_comparison_test),
		cmocka_unit_test(matrix4x4_good_comparison_test),
		cmocka_unit_test(matrix4x4_bad_comparison_test),
		cmocka_unit_test(different_size_matrix_comparison_test),
	};
	return (cmocka_run_group_tests(matrix_comparison_tests, NULL, NULL));
}
