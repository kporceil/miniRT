/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:48:11 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/26 19:23:52 by kporceil         ###   ########lyon.fr   */
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

static void	matrix4x4_mult_test(void **state)
{
	t_matrix	m1 = matrix_create(4);
	t_matrix	m2 = matrix_create(4);
	t_matrix	expected_result = matrix_create(4);

	(void)state;
	expected_result.matrix[0][0] = 20, m1.matrix[0][0] = 1, m2.matrix[0][0] = -2;
	expected_result.matrix[0][1] = 22, m1.matrix[0][1] = 2, m2.matrix[0][1] = 1;
	expected_result.matrix[0][2] = 50, m1.matrix[0][2] = 3, m2.matrix[0][2] = 2;
	expected_result.matrix[0][3] = 48, m1.matrix[0][3] = 4, m2.matrix[0][3] = 3;
	expected_result.matrix[1][0] = 44, m1.matrix[1][0] = 5, m2.matrix[1][0] = 3;
	expected_result.matrix[1][1] = 54, m1.matrix[1][1] = 6, m2.matrix[1][1] = 2;
	expected_result.matrix[1][2] = 114, m1.matrix[1][2] = 7, m2.matrix[1][2] = 1;
	expected_result.matrix[1][3] = 108, m1.matrix[1][3] = 8, m2.matrix[1][3] = -1;
	expected_result.matrix[2][0] = 40, m1.matrix[2][0] = 9, m2.matrix[2][0] = 4;
	expected_result.matrix[2][1] = 58, m1.matrix[2][1] = 8, m2.matrix[2][1] = 3;
	expected_result.matrix[2][2] = 110, m1.matrix[2][2] = 7, m2.matrix[2][2] = 6;
	expected_result.matrix[2][3] = 102, m1.matrix[2][3] = 6, m2.matrix[2][3] = 5;
	expected_result.matrix[3][0] = 16, m1.matrix[3][0] = 5, m2.matrix[3][0] = 1;
	expected_result.matrix[3][1] = 26, m1.matrix[3][1] = 4, m2.matrix[3][1] = 2;
	expected_result.matrix[3][2] = 46, m1.matrix[3][2] = 3, m2.matrix[3][2] = 7;
	expected_result.matrix[3][3] = 42, m1.matrix[3][3] = 2, m2.matrix[3][3] = 8;
	assert_matrix_equal(matrix_mult(m1, m2), expected_result);
}

static void	matrix4x4_identity_matrix_mult_test(void **state)
{
	t_matrix	m1 = matrix_create(4);
	t_matrix	m2 = identity_matrix(4);
	t_matrix	expected_result = matrix_create(4);

	(void)state;
	expected_result.matrix[0][0] = 1, m1.matrix[0][0] = 1;
	expected_result.matrix[0][1] = 2, m1.matrix[0][1] = 2;
	expected_result.matrix[0][2] = 3, m1.matrix[0][2] = 3;
	expected_result.matrix[0][3] = 4, m1.matrix[0][3] = 4;
	expected_result.matrix[1][0] = 5, m1.matrix[1][0] = 5;
	expected_result.matrix[1][1] = 6, m1.matrix[1][1] = 6;
	expected_result.matrix[1][2] = 7, m1.matrix[1][2] = 7;
	expected_result.matrix[1][3] = 8, m1.matrix[1][3] = 8;
	expected_result.matrix[2][0] = 9, m1.matrix[2][0] = 9;
	expected_result.matrix[2][1] = 8, m1.matrix[2][1] = 8;
	expected_result.matrix[2][2] = 7, m1.matrix[2][2] = 7;
	expected_result.matrix[2][3] = 6, m1.matrix[2][3] = 6;
	expected_result.matrix[3][0] = 5, m1.matrix[3][0] = 5;
	expected_result.matrix[3][1] = 4, m1.matrix[3][1] = 4;
	expected_result.matrix[3][2] = 3, m1.matrix[3][2] = 3;
	expected_result.matrix[3][3] = 2, m1.matrix[3][3] = 2;
	assert_matrix_equal(matrix_mult(m1, m2), expected_result);
}

static void	matrix_tuple_mult_test(void **state)
{
	t_matrix	m1 = matrix_create(4);
	t_tuple		p = point(1, 2, 3);
	
	(void)state;
	m1.matrix[0][0] = 1;
	m1.matrix[0][1] = 2;
	m1.matrix[0][2] = 3;
	m1.matrix[0][3] = 4;
	m1.matrix[1][0] = 2;
	m1.matrix[1][1] = 4;
	m1.matrix[1][2] = 4;
	m1.matrix[1][3] = 2;
	m1.matrix[2][0] = 8;
	m1.matrix[2][1] = 6;
	m1.matrix[2][2] = 4;
	m1.matrix[2][3] = 1;
	m1.matrix[3][0] = 0;
	m1.matrix[3][1] = 0;
	m1.matrix[3][2] = 0;
	m1.matrix[3][3] = 1;
	assert_tuple_equal(matrix_tuple_mult(m1, p), ((t_tuple){18, 24, 33, 1}));
}

int	test_matrix_mult(void)
{
	const struct CMUnitTest	matrix_mult_tests[] = {
		cmocka_unit_test(matrix4x4_mult_test),
		cmocka_unit_test(matrix_tuple_mult_test),
		cmocka_unit_test(matrix4x4_identity_matrix_mult_test),
	};
	return (cmocka_run_group_tests(matrix_mult_tests, NULL, NULL));
}
