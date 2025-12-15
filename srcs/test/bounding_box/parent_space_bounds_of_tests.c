/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_space_bounds_of_tests.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:35:17 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/02 11:00:27 by lcesbron         ###   ########lyon.fr   */
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

static void	bounding_box_parent_space_bounds_of_1_test(__unused void **state)
{
	t_shape			s = sphere(1);
	t_bounding_box	b1;

	shape_set_matrix(&s, matrix_mult(matrix_translation(1, -3, 5), matrix_scaling(0.5, 2, 4)));
	b1 = bb_parent_space_bounds_of(&s);
	assert_tuple_equal(b1.min, point(0.5, -5, 1));
	assert_tuple_equal(b1.max, point(1.5, -1, 9));
}

int	test_bounding_box_parent_space_bounds_of(void)
{
	const struct CMUnitTest	bounding_box_parent_space_bounds_of_tests[] = {
		cmocka_unit_test(bounding_box_parent_space_bounds_of_1_test),
	};
	return (cmocka_run_group_tests(bounding_box_parent_space_bounds_of_tests, NULL, NULL));
}
