/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cofactor_tests.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 00:44:23 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/27 00:53:31 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "matrix.h"

static void	matrix_cofactor_test(void **state)
{
	t_matrix	m = matrix_create(3);

	(void)state;
	m.matrix[0][0] = 3, m.matrix[0][1] = 5, m.matrix[0][2] = 0;
	m.matrix[1][0] = 2, m.matrix[1][1] = -1, m.matrix[1][2] = -7;
	m.matrix[2][0] = 6, m.matrix[2][1] = -1, m.matrix[2][2] = 5;
	assert_double_equal(matrix_cofactor(m, 0, 0), -12, 0.0001);
	assert_double_equal(matrix_cofactor(m, 1, 0), -25, 0.0001);
}

int	test_matrix_cofactor(void)
{
	const struct CMUnitTest	matrix_cofactor_tests[] = {
		cmocka_unit_test(matrix_cofactor_test),
	};
	return (cmocka_run_group_tests(matrix_cofactor_tests, NULL, NULL));
}
