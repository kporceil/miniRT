/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:26:31 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/17 13:22:37 by lcesbron         ###   ########lyon.fr   */
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
#include "light.h"

#ifndef EPSILON
# define EPSILON 0.0001
#endif

static void	intersect_triangle_1_test(__unused void **state)
{
	t_tuple	p1 = point(0, 1, 0);
	t_tuple	p2 = point(-1, 0, 0);
	t_tuple	p3 = point(1, 0, 0);
	t_shape	tri = triangle(1, p1, p2, p3);
	t_ray	r = ray(point(0, -1, -2), vector(0, 1, 0));
	t_intersections	xs = (t_intersections){0};

	xs.inters = malloc(sizeof(t_inter) * 0);
	ray_intersect(&tri, r, &xs);
	assert_int_equal(xs.size, 0);
	free(xs.inters);
}

static void	intersect_triangle_2_test(__unused void **state)
{
	t_tuple	p1 = point(0, 1, 0);
	t_tuple	p2 = point(-1, 0, 0);
	t_tuple	p3 = point(1, 0, 0);
	t_shape	tri = triangle(1, p1, p2, p3);
	t_ray	r = ray(point(1, 1, -2), vector(0, 0, 1));
	t_intersections	xs = (t_intersections){0};

	xs.inters = malloc(sizeof(t_inter) * 0);
	ray_intersect(&tri, r, &xs);
	assert_int_equal(xs.size, 0);
	free(xs.inters);
}

static void	intersect_triangle_3_test(__unused void **state)
{
	t_tuple	p1 = point(0, 1, 0);
	t_tuple	p2 = point(-1, 0, 0);
	t_tuple	p3 = point(1, 0, 0);
	t_shape	tri = triangle(1, p1, p2, p3);
	t_ray	r = ray(point(-1, 1, -2), vector(0, 0, 1));
	t_intersections	xs = (t_intersections){0};

	xs.inters = malloc(sizeof(t_inter) * 0);
	ray_intersect(&tri, r, &xs);
	assert_int_equal(xs.size, 0);
	free(xs.inters);
}

static void	intersect_triangle_4_test(__unused void **state)
{
	t_tuple	p1 = point(0, 1, 0);
	t_tuple	p2 = point(-1, 0, 0);
	t_tuple	p3 = point(1, 0, 0);
	t_shape	tri = triangle(1, p1, p2, p3);
	t_ray	r = ray(point(0, -1, -2), vector(0, 0, 1));
	t_intersections	xs = (t_intersections){0};

	xs.inters = malloc(sizeof(t_inter) * 0);
	ray_intersect(&tri, r, &xs);
	assert_int_equal(xs.size, 0);
	free(xs.inters);
}

static void	intersect_triangle_5_test(__unused void **state)
{
	t_tuple	p1 = point(0, 1, 0);
	t_tuple	p2 = point(-1, 0, 0);
	t_tuple	p3 = point(1, 0, 0);
	t_shape	tri = triangle(1, p1, p2, p3);
	t_ray	r = ray(point(0, 0.5, -2), vector(0, 0, 1));
	t_intersections	xs = (t_intersections){0};

	xs.inters = malloc(sizeof(t_inter) * 1);
	ray_intersect(&tri, r, &xs);
	assert_int_equal(xs.size, 1);
	assert_double_equal(xs.inters[0].point, 2, EPSILON);
	free(xs.inters);
}

int	test_triangle_intersect(void)
{
	const struct CMUnitTest	triangle_intersect_tests[] = {
		cmocka_unit_test(intersect_triangle_1_test),
		cmocka_unit_test(intersect_triangle_2_test),
		cmocka_unit_test(intersect_triangle_3_test),
		cmocka_unit_test(intersect_triangle_4_test),
		cmocka_unit_test(intersect_triangle_5_test),
	};
	return (cmocka_run_group_tests(triangle_intersect_tests, NULL, NULL));
}
