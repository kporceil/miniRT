/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chaining_tests.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:20:15 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/27 18:35:27 by kporceil         ###   ########lyon.fr   */
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

static void	chaining_matrix_test(void **state)
{
	(void)state;
	assert_tuple_equal(
			matrix_tuple_mult(matrix_translation(10, 5, 7), matrix_tuple_mult(matrix_scaling(5, 5, 5), matrix_tuple_mult(matrix_x_rotation(M_PI / 2), point(1, 0, 1)))),
			matrix_tuple_mult(matrix_mult(matrix_mult(matrix_translation(10, 5, 7), matrix_scaling(5, 5, 5)), matrix_x_rotation(M_PI / 2)), point(1, 0, 1)));
}

int	test_chaining_matrix(void)
{
	const struct CMUnitTest	matrix_chaining_tests[] = {
		cmocka_unit_test(chaining_matrix_test),
	};
	return (cmocka_run_group_tests(matrix_chaining_tests, NULL, NULL));
}
