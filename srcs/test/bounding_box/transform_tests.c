/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:40:28 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/02 10:34:00 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <math.h>
#include "tests.h"
#include "bounding_box.h"

#ifndef EPSILON
# define EPSILON 0.0001
#endif

static void	bounding_box_transform_1_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(-1, -1, -1), point(1, 1, 1));
	t_matrix		m = matrix_mult(matrix_x_rotation(M_PI/4), matrix_y_rotation(M_PI/4));
	t_bounding_box	b2 = bb_transform(b1, m);

	assert_tuple_equal(b2.min, point(-1.4142, -1.7071, -1.7071));
	assert_tuple_equal(b2.max, point(1.4142, 1.7071, 1.7071));
}

int	test_bounding_box_transform(void)
{
	const struct CMUnitTest	bounding_box_transform_tests[] = {
		cmocka_unit_test(bounding_box_transform_1_test),
	};
	return (cmocka_run_group_tests(bounding_box_transform_tests, NULL, NULL));
}
