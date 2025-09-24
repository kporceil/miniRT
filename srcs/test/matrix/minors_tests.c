/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minors_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 00:31:23 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/27 00:40:52 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "matrix.h"

static void	matrix3x3_minors_tests(void **state)
{
	t_matrix	m1 =  matrix_create(3);

	(void)state;
	m1.matrix[0][0] = 3, m1.matrix[0][1] = 5, m1.matrix[0][2] = 0;
	m1.matrix[1][0] = 2, m1.matrix[1][1] = -1, m1.matrix[1][2] = -7;
	m1.matrix[2][0] = 6, m1.matrix[2][1] = -1, m1.matrix[2][2] = 5;
	assert_double_equal(matrix_minor(m1, 1, 0), 25, 0.0001);
}

int	test_matrix_minors(void)
{
	const struct CMUnitTest	matrix_minors_tests[] = {
		cmocka_unit_test(matrix3x3_minors_tests),
	};
	return (cmocka_run_group_tests(matrix_minors_tests, NULL, NULL));
}
