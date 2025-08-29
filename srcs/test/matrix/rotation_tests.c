/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_tests.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:33:19 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/27 15:44:36 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "matrix.h"
#include "tests.h"

static void	x_axis_rotation_test(void **state)
{
	(void)state;
	assert_tuple_equal(matrix_tuple_mult(matrix_x_rotation(M_PI / 4), point(0, 1, 0)), point(0, sqrt(2) / 2, sqrt(2) / 2));
	assert_tuple_equal(matrix_tuple_mult(matrix_x_rotation(M_PI / 2), point(0, 1, 0)), point(0, 0, 1));
}

static void	x_axis_inverse_rotation_test(void **state)
{
	(void)state;
	assert_tuple_equal(matrix_tuple_mult(matrix_invert(matrix_x_rotation(M_PI / 4)), point(0, 1, 0)), point(0, sqrt(2) / 2, -(sqrt(2) / 2)));
}

static void	y_axis_rotation_test(void **state)
{
	(void)state;
	assert_tuple_equal(matrix_tuple_mult(matrix_y_rotation(M_PI / 4), point(0, 0, 1)), point(sqrt(2) / 2, 0, sqrt(2) / 2));
	assert_tuple_equal(matrix_tuple_mult(matrix_y_rotation(M_PI / 2), point(0, 0, 1)), point(1, 0, 0));
}

static void	z_axis_rotation_test(void **state)
{
	(void)state;
	assert_tuple_equal(matrix_tuple_mult(matrix_z_rotation(M_PI / 4), point(0, 1, 0)), point(-(sqrt(2) / 2), sqrt(2) / 2, 0));
	assert_tuple_equal(matrix_tuple_mult(matrix_z_rotation(M_PI / 2), point(0, 1, 0)), point(-1, 0, 0));
}

int	test_rotation_matrix(void)
{
	const struct CMUnitTest	rotation_matrix_tests[] = {
		cmocka_unit_test(x_axis_rotation_test),
		cmocka_unit_test(x_axis_inverse_rotation_test),
		cmocka_unit_test(y_axis_rotation_test),
		cmocka_unit_test(z_axis_rotation_test),
	};
	return (cmocka_run_group_tests(rotation_matrix_tests, NULL, NULL));
}
