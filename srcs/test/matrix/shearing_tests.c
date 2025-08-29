/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearing_tests.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:05:51 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/27 17:49:09 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "matrix.h"
#include "tests.h"

static void	x_axis_shearing_matrix_test(void **state)
{
	(void)state;
	assert_tuple_equal(matrix_tuple_mult(matrix_shearing((double[2]){1, 0}, (double[2]){0, 0}, (double[2]){0, 0}), point(2, 3, 4)), point(5, 3, 4));
	assert_tuple_equal(matrix_tuple_mult(matrix_shearing((double[2]){0, 1}, (double[2]){0, 0}, (double[2]){0, 0}), point(2, 3, 4)), point(6, 3, 4));
}

static void	y_axis_shearing_matrix_test(void **state)
{
	(void)state;
	assert_tuple_equal(matrix_tuple_mult(matrix_shearing((double[2]){0, 0}, (double[2]){1, 0}, (double[2]){0, 0}), point(2, 3, 4)), point(2, 5, 4));
	assert_tuple_equal(matrix_tuple_mult(matrix_shearing((double[2]){0, 0}, (double[2]){0, 1}, (double[2]){0, 0}), point(2, 3, 4)), point(2, 7, 4));
}

static void	z_axis_shearing_matrix_test(void **state)
{
	(void)state;
	assert_tuple_equal(matrix_tuple_mult(matrix_shearing((double[2]){0, 0}, (double[2]){0, 0}, (double[2]){1, 0}), point(2, 3, 4)), point(2, 3, 6));
	assert_tuple_equal(matrix_tuple_mult(matrix_shearing((double[2]){0, 0}, (double[2]){0, 0}, (double[2]){0, 1}), point(2, 3, 4)), point(2, 3, 7));
}

int	test_shearing_matrix(void)
{
	const struct CMUnitTest	shearing_matrix_tests[] = {
		cmocka_unit_test(x_axis_shearing_matrix_test),
		cmocka_unit_test(y_axis_shearing_matrix_test),
		cmocka_unit_test(z_axis_shearing_matrix_test),
	};
	return (cmocka_run_group_tests(shearing_matrix_tests, NULL, NULL));
}
