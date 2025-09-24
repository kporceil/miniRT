/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinant_tests.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 20:52:45 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/26 20:55:46 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "matrix.h"

static void	matrix2x2_determinant_test(void **state)
{
	t_matrix	m = matrix_create(2);

	(void)state;
	m.matrix[0][0] = 1, m.matrix[0][1] = 5, m.matrix[1][0] = -3, m.matrix[1][1] = 2;
	assert_double_equal(matrix_determinant(m), 17, 0.0001);
}

int	test_matrix_determinant(void)
{
	const struct CMUnitTest	determinant_tests[] = {
		cmocka_unit_test(matrix2x2_determinant_test),
	};
	return (cmocka_run_group_tests(determinant_tests, NULL, NULL));
}
