/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:06:47 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/26 16:15:58 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "matrix.h"

static void	matrix4x4_creation_test(void **state)
{
	t_matrix	m = matrix_create(4);

	(void)state;
	m.matrix[0][0] = 1;
	m.matrix[0][1] = 2;
	m.matrix[0][2] = 3;
	m.matrix[0][3] = 4;
	m.matrix[1][0] = 5.5;
	m.matrix[1][1] = 6.5;
	m.matrix[1][2] = 7.5;
	m.matrix[1][3] = 8.5;
	m.matrix[2][0] = 9;
	m.matrix[2][1] = 10;
	m.matrix[2][2] = 11;
	m.matrix[2][3] = 12;
	m.matrix[3][0] = 13.5;
	m.matrix[3][1] = 14.5;
	m.matrix[3][2] = 15.5;
	m.matrix[3][3] = 16.5;

	assert_double_equal(m.matrix[0][0], 1, 0.0001);
	assert_double_equal(m.matrix[0][3], 4, 0.0001);
	assert_double_equal(m.matrix[1][0], 5.5, 0.0001);
	assert_double_equal(m.matrix[1][2], 7.5, 0.0001);
	assert_double_equal(m.matrix[2][2], 11, 0.0001);
	assert_double_equal(m.matrix[3][0], 13.5, 0.0001);
	assert_double_equal(m.matrix[3][2], 15.5, 0.0001);
}

static void	matrix2x2_creation_test(void **state)
{
	t_matrix	m = matrix_create(2);

	(void)state;
	m.matrix[0][0] = -3;
	m.matrix[0][1] = 5;
	m.matrix[1][0] = 1;
	m.matrix[1][1] = -2;

	assert_double_equal(m.matrix[0][0], -3, 0.0001);
	assert_double_equal(m.matrix[0][1], 5, 0.0001);
	assert_double_equal(m.matrix[1][0], 1, 0.0001);
	assert_double_equal(m.matrix[1][1], -2, 0.0001);
}

static void	matrix3x3_creation_test(void **state)
{
	t_matrix	m = matrix_create(3);

	(void)state;
	m.matrix[0][0] = -3;
	m.matrix[0][1] = 5;
	m.matrix[0][2] = 0;
	m.matrix[1][0] = 1;
	m.matrix[1][1] = -2;
	m.matrix[1][2] = -7;
	m.matrix[2][0] = 0;
	m.matrix[2][1] = 1;
	m.matrix[2][2] = 1;

	assert_double_equal(m.matrix[0][0], -3, 0.0001);
	assert_double_equal(m.matrix[1][1], -2, 0.0001);
	assert_double_equal(m.matrix[2][2], 1, 0.0001);
}

int	test_matrix_create(void)
{
	const struct CMUnitTest	matrix_create_tests[] = {
		cmocka_unit_test(matrix2x2_creation_test),
		cmocka_unit_test(matrix3x3_creation_test),
		cmocka_unit_test(matrix4x4_creation_test),
	};
	return (cmocka_run_group_tests(matrix_create_tests, NULL, NULL));
}
