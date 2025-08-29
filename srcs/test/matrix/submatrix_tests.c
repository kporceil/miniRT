/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   submatrix_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 21:00:57 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/26 21:27:12 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "matrix.h"
#include "tests.h"

static void	matrix3x3_submatrix_test(void **state)
{
	t_matrix	m1 = matrix_create(3);
	t_matrix	expected = matrix_create(2);

	(void)state;
	m1.matrix[0][0] = 1, m1.matrix[0][1] = 5, m1.matrix[0][2] = 0;
	m1.matrix[1][0] = -3, m1.matrix[1][1] = 2, m1.matrix[0][2] = 7;
	m1.matrix[2][0] = 0, m1.matrix[2][1] = 6, m1.matrix[2][2] = -3;
	expected.matrix[0][0] = -3, expected.matrix[0][1] = 2;
	expected.matrix[1][0] = 0, expected.matrix[1][1] = 6;
	assert_matrix_equal(submatrix(m1, 0, 2), expected);
}

static void	matrix4x4_submatrix_test(void **state)
{
	t_matrix	m1 = matrix_create(4);
	t_matrix	expected = matrix_create(3);

	(void)state;
	m1.matrix[0][0] = -6, m1.matrix[0][1] = 1, m1.matrix[0][2] = 1, m1.matrix[0][3] = 6;
	m1.matrix[1][0] = -8, m1.matrix[1][1] = 5, m1.matrix[1][2] = 8, m1.matrix[1][3] = 6;
	m1.matrix[2][0] = -1, m1.matrix[2][1] = 0, m1.matrix[2][2] = 8, m1.matrix[2][3] = 2;
	m1.matrix[3][0] = -7, m1.matrix[3][1] = 1, m1.matrix[3][2] = -1, m1.matrix[3][3] = 1;
	expected.matrix[0][0] = -6, expected.matrix[0][1] = 1, expected.matrix[0][2] = 6;
	expected.matrix[1][0] = -8, expected.matrix[1][1] = 8, expected.matrix[1][2] = 6;
	expected.matrix[2][0] = -7, expected.matrix[2][1] = -1, expected.matrix[2][2] = 1;
	assert_matrix_equal(submatrix(m1, 2, 1), expected);
}

int	test_submatrix(void)
{
	const struct CMUnitTest	submatrix_tests[] = {
		cmocka_unit_test(matrix3x3_submatrix_test),
		cmocka_unit_test(matrix4x4_submatrix_test),
	};
	return (cmocka_run_group_tests(submatrix_tests, NULL, NULL));
}
