/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:43:22 by lcesbron          #+#    #+#             */
/*   Updated: 2025/09/29 14:28:42 by lcesbron         ###   ########lyon.fr   */
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

static void miss_ray_cylinder_1_test(__unused void **state)
{
	t_shape	cyl = cylinder(1);
	t_tuple	direction = normalize(vector(0, 1, 0));
	t_ray	r = ray(point(1, 0, 0), direction);
	t_intersections xs = (t_intersections){.inters = NULL, .size = 0};

	ray_intersect(&cyl, r, &xs);
	assert_int_equal(xs.size, 0);
}

static void miss_ray_cylinder_2_test(__unused void **state)
{
	t_shape	cyl = cylinder(1);
	t_tuple	direction = normalize(vector(0, 1, 0));
	t_ray	r = ray(point(0, 0, 0), direction);
	t_intersections xs = (t_intersections){.inters = NULL, .size = 0};

	ray_intersect(&cyl, r, &xs);
	assert_int_equal(xs.size, 0);
}

static void miss_ray_cylinder_3_test(__unused void **state)
{
	t_shape	cyl = cylinder(1);
	t_tuple	direction = normalize(vector(1, 1, 1));
	t_ray	r = ray(point(0, 0, -5), direction);
	t_intersections xs = (t_intersections){.inters = NULL, .size = 0};

	ray_intersect(&cyl, r, &xs);
	assert_int_equal(xs.size, 0);
}

static void hit_ray_cylinder_1_test(__unused void **state)
{
	t_shape	cyl = cylinder(1);
	t_tuple	direction = normalize(vector(0, 0, 1));
	t_ray	r = ray(point(1, 0, -5), direction);
	t_intersections xs;
	
	xs.inters = malloc(sizeof(t_inter) * 2);
	xs.size = 0;
	ray_intersect(&cyl, r, &xs);
	assert_int_equal(xs.size, 2);
	assert_double_equal(xs.inters[0].point, 5.0, EPSILON);
	assert_double_equal(xs.inters[1].point, 5.0, EPSILON);
	free(xs.inters);
}

static void hit_ray_cylinder_2_test(__unused void **state)
{
	t_shape	cyl = cylinder(1);
	t_tuple	direction = normalize(vector(0, 0, 1));
	t_ray	r = ray(point(0, 0, -5), direction);
	t_intersections xs;
	
	xs.inters = malloc(sizeof(t_inter) * 2);
	xs.size = 0;
	ray_intersect(&cyl, r, &xs);
	assert_int_equal(xs.size, 2);
	assert_double_equal(xs.inters[0].point, 4.0, EPSILON);
	assert_double_equal(xs.inters[1].point, 6.0, EPSILON);
	free(xs.inters);
}

static void hit_ray_cylinder_3_test(__unused void **state)
{
	t_shape	cyl = cylinder(1);
	t_tuple	direction = normalize(vector(0.1, 1, 1));
	t_ray	r = ray(point(0.5, 0, -5), direction);
	t_intersections xs;
	
	xs.inters = malloc(sizeof(t_inter) * 2);
	xs.size = 0;
	ray_intersect(&cyl, r, &xs);
	assert_int_equal(xs.size, 2);
	assert_double_equal(xs.inters[0].point, 6.80798, EPSILON);
	assert_double_equal(xs.inters[1].point, 7.08872, EPSILON);
	free(xs.inters);
}
int	test_cylinder_intersect(void)
{
	const struct CMUnitTest	plane_intersect_tests[] = {
		cmocka_unit_test(miss_ray_cylinder_1_test),
		cmocka_unit_test(miss_ray_cylinder_2_test),
		cmocka_unit_test(miss_ray_cylinder_3_test),
		cmocka_unit_test(hit_ray_cylinder_1_test),
		cmocka_unit_test(hit_ray_cylinder_2_test),
		cmocka_unit_test(hit_ray_cylinder_3_test),
	};
	return (cmocka_run_group_tests(plane_intersect_tests, NULL, NULL));
}
