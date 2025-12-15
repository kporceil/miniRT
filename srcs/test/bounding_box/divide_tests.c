/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:28:27 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/10 15:51:37 by lcesbron         ###   ########lyon.fr   */
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

static void	bounding_box_divide_1_test(__unused void **state)
{
	t_shape	s = sphere(1);

	divide(&s, 1);
	assert_int_equal(s.type, SPHERE);
}

static void	bounding_box_divide_2_test(__unused void **state)
{
	t_shape	s1 = sphere(1);
	t_shape	s2 = sphere(2);
	t_shape	s3 = sphere(3);
	t_shape	g;

	shape_set_matrix(&s1, matrix_translation(-3, -3, 0));
	shape_set_matrix(&s2, matrix_translation(-3, 3, 0));
	shape_set_matrix(&s3, matrix_scaling(4, 4, 4));
	g = group(4, 3);
	group_add_shape(&g, s1);
	group_add_shape(&g, s2);
	group_add_shape(&g, s3);
	divide(&g, 1);
	assert_int_equal(g.child[0].id, 3);
	assert_int_equal(g.child[1].type, GROUP);
	assert_int_equal(g.child[1].nb_members, 2);
	assert_int_equal(g.child[1].child[0].type, GROUP);
	assert_int_equal(g.child[1].child[1].type, GROUP);
	assert_int_equal(g.child[1].child[0].child->id, 1);
	assert_int_equal(g.child[1].child[1].child->id, 2);
}

int	test_bounding_box_divide(void)
{
	const struct CMUnitTest	bounding_box_divide_tests[] = {
		cmocka_unit_test(bounding_box_divide_1_test),
		cmocka_unit_test(bounding_box_divide_2_test),
	};
	return (cmocka_run_group_tests(bounding_box_divide_tests, NULL, NULL));
}
