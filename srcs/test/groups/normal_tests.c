/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:46:17 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/26 18:20:38 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include "shape.h"
#include "tests.h"
#include "ray.h"
#include "tuples.h"
#include "light.h"
#include "groups.h"

#ifndef EPSILON
# define EPSILON 0.0001
#endif

static void	normal_point_world_to_object_1_test(__unused void **state)
{
	t_shape	g1 = group(1, 1);
	t_tuple	p;

	shape_set_matrix(&g1, matrix_y_rotation(M_PI/2));
	group_add_shape(&g1, group(2, 1));
	shape_set_matrix(g1.child, matrix_scaling(2, 2, 2));
	group_add_shape(g1.child, sphere(3));
	shape_set_matrix(g1.child->child, matrix_translation(5, 0, 0));
	p = world_to_object(g1.child->child, point(-2, 0, -10));
	assert_tuple_equal(p, point(0, 0, -1));
	free(g1.child->child);
	free(g1.child);
}

static void	normal_vector_object_to_world_1_test(__unused void **state)
{
	t_shape	g1 = group(1, 1);
	t_tuple	n;

	shape_set_matrix(&g1, matrix_y_rotation(M_PI/2));
	group_add_shape(&g1, group(2, 1));
	shape_set_matrix(g1.child, matrix_scaling(1, 2, 3));
	group_add_shape(g1.child, sphere(2));
	shape_set_matrix(g1.child->child, matrix_translation(5, 0, 0));
	n = normal_to_world(g1.child->child, vector(sqrt(3)/3, sqrt(3)/3, sqrt(3)/3));
	assert_tuple_equal(n, vector(0.2857, 0.4286, -0.8571));
}

static void	normal_of_child_1_test(__unused void **state)
{
	t_shape	g1 = group(1, 1);
	t_tuple	n;

	shape_set_matrix(&g1, matrix_y_rotation(M_PI/2));
	group_add_shape(&g1, group(2, 1));
	shape_set_matrix(g1.child, matrix_scaling(1, 2, 3));
	group_add_shape(g1.child, sphere(2));
	shape_set_matrix(g1.child->child, matrix_translation(5, 0, 0));
	n = normal_at(*g1.child->child, point(1.7321, 1.1547, -5.5774), NULL);

	assert_tuple_equal(n, vector(0.2857, 0.4286, -0.8571));
}

int	test_group_normal(void)
{
	const struct CMUnitTest	group_normal_tests[] = {
		cmocka_unit_test(normal_point_world_to_object_1_test),
		cmocka_unit_test(normal_vector_object_to_world_1_test),
		cmocka_unit_test(normal_of_child_1_test),
	};
	return (cmocka_run_group_tests(group_normal_tests, NULL, NULL));
}
