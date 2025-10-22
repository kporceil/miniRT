/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_tests.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:46:17 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/15 17:35:13 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include <float.h>
#include "shape.h"
#include "tests.h"
#include "ray.h"
#include "tuples.h"

#ifndef EPSILON
# define EPSILON 0.0001
#endif

static void	transform_group_1_test(__unused void **state)
{
	t_shape	g = group(1, 1);
	t_ray	r = ray(point(10, 0, -10), vector(0, 0, 1));
	t_intersections xs = (t_intersections){0};

	group_set_matrix(&g, matrix_scaling(2, 2, 2));
	group_add_shape(&g, sphere(2));
	shape_set_matrix(g.child, matrix_translation(5, 0, 0));
	xs.inters = malloc(sizeof(t_inter) * 2);
	ray_intersect(&g, r, &xs);
	assert_int_equal(xs.size, 2);
	free(g.child);
	free(xs.inters);
}

static void	transform_group_2_test(__unused void **state)
{
	t_shape	g = group(1, 1);
	t_ray	r = ray(point(10, 0, -10), vector(0, 0, 1));
	t_intersections xs = (t_intersections){0};

	group_add_shape(&g, sphere(2));
	shape_set_matrix(g.child, matrix_translation(5, 0, 0));
	group_set_matrix(&g, matrix_scaling(2, 2, 2));
	xs.inters = malloc(sizeof(t_inter) * 2);
	ray_intersect(&g, r, &xs);
	assert_int_equal(xs.size, 2);
	free(g.child);
	free(xs.inters);
}

int	test_group_transform(void)
{
	const struct CMUnitTest	group_transform_tests[] = {
		cmocka_unit_test(transform_group_1_test),
		cmocka_unit_test(transform_group_2_test),
	};
	return (cmocka_run_group_tests(group_transform_tests, NULL, NULL));
}
