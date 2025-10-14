/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_cap_intersect_tests.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:43:22 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/02 14:06:16 by lcesbron         ###   ########lyon.fr   */
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

static void end_cap_intersect_cylinder_1_test(__unused void **state)
{
	t_shape	cyl = cylinder(1);
	t_tuple	direction = normalize(vector(0, -1, 0));
	t_ray	r = ray(point(0, 3, 0), direction);
	t_intersections xs = (t_intersections){.inters = NULL, .size = 0};

	cyl.cyl_min = 1;
	cyl.cyl_max = 2;
	cyl.cyl_closed = 1;
	xs.inters = malloc(sizeof(t_inter) * 2);
	ray_intersect(&cyl, r, &xs);
	assert_int_equal(xs.size, 2);
	free(xs.inters);
}

static void end_cap_intersect_cylinder_2_test(__unused void **state)
{
	t_shape	cyl = cylinder(1);
	t_tuple	direction = normalize(vector(0, -1, 2));
	t_ray	r = ray(point(0, 3, -2), direction);
	t_intersections xs = (t_intersections){.inters = NULL, .size = 0};

	cyl.cyl_min = 1;
	cyl.cyl_max = 2;
	cyl.cyl_closed = 1;
	xs.inters = malloc(sizeof(t_inter) * 2);
	ray_intersect(&cyl, r, &xs);
	assert_int_equal(xs.size, 2);
	free(xs.inters);
}

static void end_cap_intersect_cylinder_3_test(__unused void **state)
{
	t_shape	cyl = cylinder(1);
	t_tuple	direction = normalize(vector(0, -1, 1));
	t_ray	r = ray(point(0, 4, -2), direction);
	t_intersections xs = (t_intersections){.inters = NULL, .size = 0};

	cyl.cyl_min = 1;
	cyl.cyl_max = 2;
	cyl.cyl_closed = 1;
	xs.inters = malloc(sizeof(t_inter) * 2);
	ray_intersect(&cyl, r, &xs);
	assert_int_equal(xs.size, 2);
	free(xs.inters);
}

static void end_cap_intersect_cylinder_4_test(__unused void **state)
{
	t_shape	cyl = cylinder(1);
	t_tuple	direction = normalize(vector(0, 1, 2));
	t_ray	r = ray(point(0, 0, -2), direction);
	t_intersections xs = (t_intersections){.inters = NULL, .size = 0};

	cyl.cyl_min = 1;
	cyl.cyl_max = 2;
	cyl.cyl_closed = 1;
	xs.inters = malloc(sizeof(t_inter) * 2);
	ray_intersect(&cyl, r, &xs);
	assert_int_equal(xs.size, 2);
	free(xs.inters);
}

static void end_cap_intersect_cylinder_5_test(__unused void **state)
{
	t_shape	cyl = cylinder(1);
	t_tuple	direction = normalize(vector(0, 1, 1));
	t_ray	r = ray(point(0, -1, -2), direction);
	t_intersections xs = (t_intersections){.inters = NULL, .size = 0};

	cyl.cyl_min = 1;
	cyl.cyl_max = 2;
	cyl.cyl_closed = 1;
	xs.inters = malloc(sizeof(t_inter) * 2);
	ray_intersect(&cyl, r, &xs);
	assert_int_equal(xs.size, 2);
	free(xs.inters);
}

int	test_end_cap_cylinder_intersect(void)
{
	const struct CMUnitTest	cylinder_end_cap_intersect_tests[] = {
		cmocka_unit_test(end_cap_intersect_cylinder_1_test),
		cmocka_unit_test(end_cap_intersect_cylinder_2_test),
		cmocka_unit_test(end_cap_intersect_cylinder_3_test),
		cmocka_unit_test(end_cap_intersect_cylinder_4_test),
		cmocka_unit_test(end_cap_intersect_cylinder_5_test),
	};
	return (cmocka_run_group_tests(cylinder_end_cap_intersect_tests, NULL, NULL));
}
