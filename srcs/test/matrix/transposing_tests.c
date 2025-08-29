/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transposing_tests.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 19:42:33 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/26 19:57:33 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "matrix.h"
#include "tests.h"

static void	matrix4x4_transposing_test(void **state)
{
	t_matrix	m1 = matrix_create(4);
	t_matrix	m2 = matrix_create(4);

	(void)state;
	m1.matrix[0][0] = 0, m2.matrix[0][0] = 0;
	m1.matrix[0][1] = 9, m2.matrix[0][1] = 9;
	m1.matrix[0][2] = 3, m2.matrix[0][2] = 1;
	m1.matrix[0][3] = 0, m2.matrix[0][3] = 0;
	m1.matrix[1][0] = 9, m2.matrix[1][0] = 9;
	m1.matrix[1][1] = 8, m2.matrix[1][1] = 8;
	m1.matrix[1][2] = 0, m2.matrix[1][2] = 8;
	m1.matrix[1][3] = 8, m2.matrix[1][3] = 0;
	m1.matrix[2][0] = 1, m2.matrix[2][0] = 3;
	m1.matrix[2][1] = 8, m2.matrix[2][1] = 0;
	m1.matrix[2][2] = 5, m2.matrix[2][2] = 5;
	m1.matrix[2][3] = 3, m2.matrix[2][3] = 5;
	m1.matrix[3][0] = 0, m2.matrix[3][0] = 0;
	m1.matrix[3][1] = 0, m2.matrix[3][1] = 8;
	m1.matrix[3][2] = 5, m2.matrix[3][2] = 3;
	m1.matrix[3][3] = 8, m2.matrix[3][3] = 8;
	assert_matrix_equal(matrix_transpose(m1), m2);
}

static void	matrix3x3_transposing_test(void **state)
{
	t_matrix	m1 = matrix_create(3);
	t_matrix	m2 = matrix_create(3);

	(void)state;
	m1.matrix[0][0] = 0, m2.matrix[0][0] = 0;
	m1.matrix[0][1] = 9, m2.matrix[0][1] = 9;
	m1.matrix[0][2] = 3, m2.matrix[0][2] = 1;
	m1.matrix[1][0] = 9, m2.matrix[1][0] = 9;
	m1.matrix[1][1] = 8, m2.matrix[1][1] = 8;
	m1.matrix[1][2] = 0, m2.matrix[1][2] = 8;
	m1.matrix[2][0] = 1, m2.matrix[2][0] = 3;
	m1.matrix[2][1] = 8, m2.matrix[2][1] = 0;
	m1.matrix[2][2] = 5, m2.matrix[2][2] = 5;
	assert_matrix_equal(matrix_transpose(m1), m2);
}

static void	matrix2x2_transposing_test(void **state)
{
	t_matrix	m1 = matrix_create(2);
	t_matrix	m2 = matrix_create(2);

	(void)state;
	m1.matrix[0][0] = 0, m2.matrix[0][0] = 0;
	m1.matrix[0][1] = 9, m2.matrix[0][1] = 9;
	m1.matrix[1][0] = 9, m2.matrix[1][0] = 9;
	m1.matrix[1][1] = 8, m2.matrix[1][1] = 8;
	assert_matrix_equal(matrix_transpose(m1), m2);
}

static void	identity_matrix_transposing_test(void **state)
{
	t_matrix	m1 = identity_matrix(4);

	(void)state;
	assert_matrix_equal(matrix_transpose(m1), m1);
}

int	test_matrix_transposing(void)
{
	const struct CMUnitTest	matrix_transposing_tests[] = {
		cmocka_unit_test(matrix4x4_transposing_test),
		cmocka_unit_test(matrix3x3_transposing_test),
		cmocka_unit_test(matrix2x2_transposing_test),
		cmocka_unit_test(identity_matrix_transposing_test),
	};
	return (cmocka_run_group_tests(matrix_transposing_tests, NULL, NULL));
}
