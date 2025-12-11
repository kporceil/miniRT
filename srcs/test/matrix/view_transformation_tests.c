/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transformation_tests.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 12:20:22 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/31 12:31:47 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "matrix.h"
#include "tests.h"

static void	view_transformation_test1(void **state)
{
	(void)state;
	assert_matrix_equal(view_transform_from_to(point(0, 0, 0), point(0, 0, -1), vector(0, 1, 0)), identity_matrix(4));
}

static void	view_transformation_test2(void **state)
{
	(void)state;
	assert_matrix_equal(view_transform_from_to(point(0, 0, 0), point(0, 0, 1), vector(0, 1, 0)), matrix_scaling(-1, 1, -1));
}

static void	view_transformation_test3(void **state)
{
	(void)state;
	assert_matrix_equal(view_transform_from_to(point(0, 0, 8), point(0, 0, 0), vector(0, 1, 0)), matrix_translation(0, 0, -8));
}

static void	view_transformation_test4(void **state)
{
	t_matrix	expected = matrix_create(4);

	expected.matrix[0][0] = -0.50709;
	expected.matrix[0][1] = 0.50709;
	expected.matrix[0][2] = 0.67612;
	expected.matrix[0][3] = -2.36643;
	expected.matrix[1][0] = 0.76772;
	expected.matrix[1][1] = 0.60609;
	expected.matrix[1][2] = 0.12122;
	expected.matrix[1][3] = -2.82843;
	expected.matrix[2][0] = -0.35857;
	expected.matrix[2][1] = 0.59761;
	expected.matrix[2][2] = -0.71714;
	expected.matrix[2][3] = 0;
	expected.matrix[3][0] = 0;
	expected.matrix[3][1] = 0;
	expected.matrix[3][2] = 0;
	expected.matrix[3][3] = 1;
	(void)state;
	assert_matrix_equal(view_transform_from_to(point(1, 3, 2), point(4, -2, 8), vector(1, 1, 0)), expected);
}

int	test_view_transformation(void)
{
	const struct CMUnitTest	view_transformations_tests[] = {
		cmocka_unit_test(view_transformation_test1),
		cmocka_unit_test(view_transformation_test2),
		cmocka_unit_test(view_transformation_test3),
		cmocka_unit_test(view_transformation_test4),
	};
	return (cmocka_run_group_tests(view_transformations_tests, NULL, NULL));
}
