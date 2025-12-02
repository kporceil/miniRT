/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_bounds_of_tests.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:54:28 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/02 11:31:25 by lcesbron         ###   ########lyon.fr   */
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
#include "groups.h"

#ifndef EPSILON
# define EPSILON 0.0001
#endif

static void	bounding_box_group_bounds_of_1_test(__unused void **state)
{
	t_shape			s = sphere(1);
	t_shape			cyl = cylinder(2);
	t_shape			g = group(3, 2);
	t_bounding_box	b1;

	shape_set_matrix(&s, matrix_mult(matrix_translation(2, 5, -3), matrix_scaling(2, 2, 2)));
	cyl.cyl_min = -2;
	cyl.cyl_max = -2;
	shape_set_matrix(&cyl, matrix_mult(matrix_translation(-4, -1, 4), matrix_scaling(0.5, 1, 0.5)));
	group_add_shape(&g, s);
	group_add_shape(&g, cyl);
	b1 = bb_bounds_of(g);
	assert_tuple_equal(b1.min, point(-4.5, -3, -5));
	assert_tuple_equal(b1.max, point(4, 7, 4.5));
}

int	test_bounding_box_group_bounds_of(void)
{
	const struct CMUnitTest	bounding_box_group_bounds_of_tests[] = {
		cmocka_unit_test(bounding_box_group_bounds_of_1_test),
	};
	return (cmocka_run_group_tests(bounding_box_group_bounds_of_tests, NULL, NULL));
}
