/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truncated_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:46:17 by lcesbron          #+#    #+#             */
/*   Updated: 2025/09/30 13:38:17 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include <float.h>
#include "tests.h"
#include "shape.h"
#include "tests.h"
#include "ray.h"
#include "tuples.h"

#ifndef EPSILON
# define EPSILON 0.0001
#endif

static void	truncate_cylinder_1_test(__unused void **state)
{
	t_shape			cyl = cylinder(1);
	t_tuple			direction = normalize(vector(0.1, 1, 0));
	t_ray			r = ray(point(0, 1.5, 0), direction);
	t_intersections	xs = (t_intersections){0};

	cyl.cyl_min = 1;
	cyl.cyl_max = 2;
	xs.inters = malloc(sizeof(t_inter) * 0);
	ray_intersect(&cyl, r, &xs);
	assert_int_equal(xs.size, 0);
	free(xs.inters);
}

static void	truncate_cylinder_2_test(__unused void **state)
{
	t_shape			cyl = cylinder(1);
	t_tuple			direction = normalize(vector(0, 0, 1));
	t_ray			r = ray(point(0, 3, -5), direction);
	t_intersections	xs = (t_intersections){0};

	cyl.cyl_min = 1;
	cyl.cyl_max = 2;
	xs.inters = malloc(sizeof(t_inter) * 0);
	ray_intersect(&cyl, r, &xs);
	assert_int_equal(xs.size, 0);
	free(xs.inters);
}

static void	truncate_cylinder_3_test(__unused void **state)
{
	t_shape			cyl = cylinder(1);
	t_tuple			direction = normalize(vector(0, 0, 1));
	t_ray			r = ray(point(0, 0, -5), direction);
	t_intersections	xs = (t_intersections){0};

	cyl.cyl_min = 1;
	cyl.cyl_max = 2;
	xs.inters = malloc(sizeof(t_inter) * 0);
	ray_intersect(&cyl, r, &xs);
	assert_int_equal(xs.size, 0);
	free(xs.inters);
}

static void	truncate_cylinder_4_test(__unused void **state)
{
	t_shape			cyl = cylinder(1);
	t_tuple			direction = normalize(vector(0, 0, 1));
	t_ray			r = ray(point(0, 2, -5), direction);
	t_intersections	xs = (t_intersections){0};

	cyl.cyl_min = 1;
	cyl.cyl_max = 2;
	xs.inters = malloc(sizeof(t_inter) * 0);
	ray_intersect(&cyl, r, &xs);
	assert_int_equal(xs.size, 0);
	free(xs.inters);
}

static void	truncate_cylinder_5_test(__unused void **state)
{
	t_shape			cyl = cylinder(1);
	t_tuple			direction = normalize(vector(0, 0, 1));
	t_ray			r = ray(point(0, 1, -5), direction);
	t_intersections	xs = (t_intersections){0};

	cyl.cyl_min = 1;
	cyl.cyl_max = 2;
	xs.inters = malloc(sizeof(t_inter) * 0);
	ray_intersect(&cyl, r, &xs);
	assert_int_equal(xs.size, 0);
	free(xs.inters);
}

static void	truncate_cylinder_6_test(__unused void **state)
{
	t_shape			cyl = cylinder(1);
	t_tuple			direction = normalize(vector(0, 0, 1));
	t_ray			r = ray(point(0, 1.5, -2), direction);
	t_intersections	xs = (t_intersections){0};

	cyl.cyl_min = 1;
	cyl.cyl_max = 2;
	xs.inters = malloc(sizeof(t_inter) * 2);
	ray_intersect(&cyl, r, &xs);
	assert_int_equal(xs.size, 2);
	free(xs.inters);
}

int	test_cylinder_truncate(void)
{
	const struct CMUnitTest	cylinder_truncate_tests[] = {
		cmocka_unit_test(truncate_cylinder_1_test),
		cmocka_unit_test(truncate_cylinder_2_test),
		cmocka_unit_test(truncate_cylinder_3_test),
		cmocka_unit_test(truncate_cylinder_4_test),
		cmocka_unit_test(truncate_cylinder_5_test),
		cmocka_unit_test(truncate_cylinder_6_test),
	};
	return (cmocka_run_group_tests(cylinder_truncate_tests, NULL, NULL));
}
