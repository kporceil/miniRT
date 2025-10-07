/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:43:22 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/02 17:49:54 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include "shape.h"
#include "tests.h"
#include "ray.h"
#include "tuples.h"

#ifndef EPSILON
# define EPSILON 0.0001
#endif

static void hit_ray_cone_1_test(__unused void **state)
{
	t_shape	c = cone(1);
	t_tuple	direction = normalize(vector(0, 0, 1));
	t_ray	r = ray(point(0, 0, -5), direction);
	t_intersections xs = (t_intersections){.inters = NULL, .size = 0};

	xs.inters = malloc(sizeof(t_inter) * 2);
	ray_intersect(&c, r, &xs);
	assert_int_equal(xs.size, 2);
	assert_double_equal(xs.inters[0].point, 5, 0.0001);
	assert_double_equal(xs.inters[1].point, 5, 0.0001);
	free(xs.inters);
}

static void hit_ray_cone_2_test(__unused void **state)
{
	t_shape	c = cone(1);
	t_tuple	direction = normalize(vector(1, 1, 1));
	t_ray	r = ray(point(0, 0, -5), direction);
	t_intersections xs = (t_intersections){.inters = NULL, .size = 0};

	xs.inters = malloc(sizeof(t_inter) * 2);
	ray_intersect(&c, r, &xs);
	assert_int_equal(xs.size, 2);
	assert_double_equal(xs.inters[0].point, 8.66025, 0.0001);
	assert_double_equal(xs.inters[1].point, 8.66025, 0.0001);
	free(xs.inters);
}

static void hit_ray_cone_3_test(__unused void **state)
{
	t_shape	c = cone(1);
	t_tuple	direction = normalize(vector(-0.5, -1, 1));
	t_ray	r = ray(point(1, 1, -5), direction);
	t_intersections xs = (t_intersections){.inters = NULL, .size = 0};

	xs.inters = malloc(sizeof(t_inter) * 2);
	ray_intersect(&c, r, &xs);
	assert_int_equal(xs.size, 2);
	assert_double_equal(xs.inters[0].point, 4.55006, 0.0001);
	assert_double_equal(xs.inters[1].point, 49.44994, 0.0001);
	free(xs.inters);
}

static void parallel_ray_cone_test(__unused void **state)
{
	t_shape	c = cone(1);
	t_tuple	direction = normalize(vector(0, 1, 1));
	t_ray	r = ray(point(0, 0, -1), direction);
	t_intersections xs = (t_intersections){.inters = NULL, .size = 0};

	xs.inters = malloc(sizeof(t_inter) * 1);
	ray_intersect(&c, r, &xs);
	assert_int_equal(xs.size, 1);
	assert_double_equal(xs.inters[0].point, 0.35355, 0.0001);
	free(xs.inters);
}

int	test_cone_intersect(void)
{
	const struct CMUnitTest	cone_intersect_tests[] = {
		cmocka_unit_test(hit_ray_cone_1_test),
		cmocka_unit_test(hit_ray_cone_2_test),
		cmocka_unit_test(hit_ray_cone_3_test),
		cmocka_unit_test(parallel_ray_cone_test),
	};
	return (cmocka_run_group_tests(cone_intersect_tests, NULL, NULL));
}
