/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_cap_cone_intersect_tests.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:43:22 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/06 09:58:27 by lcesbron         ###   ########lyon.fr   */
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

static void end_cap_intersect_cone_1_test(__unused void **state)
{
	t_shape	co = cone(1);
	t_tuple	direction = normalize(vector(0, 1, 0));
	t_ray	r = ray(point(0, 0, -5), direction);
	t_intersections xs = (t_intersections){.inters = NULL, .size = 0};

	co.cyl_min = -0.5;
	co.cyl_max = 0.5;
	co.cyl_closed = 1;
	xs.inters = malloc(sizeof(t_inter) * 0);
	ray_intersect(&co, r, &xs);
	assert_int_equal(xs.size, 0);
	free(xs.inters);
}

static void end_cap_intersect_cone_2_test(__unused void **state)
{
	t_shape	co = cone(1);
	t_tuple	direction = normalize(vector(0, 1, 1));
	t_ray	r = ray(point(0, 0, -0.25), direction);
	t_intersections xs = (t_intersections){.inters = NULL, .size = 0};

	co.cyl_min = -0.5;
	co.cyl_max = 0.5;
	co.cyl_closed = 1;
	xs.inters = malloc(sizeof(t_inter) * 2);
	ray_intersect(&co, r, &xs);
	assert_int_equal(xs.size, 2);
	free(xs.inters);
}

static void end_cap_intersect_cone_3_test(__unused void **state)
{
	t_shape	co = cone(1);
	t_tuple	direction = normalize(vector(0, 1, 0));
	t_ray	r = ray(point(0, 0, -0.25), direction);
	t_intersections xs = (t_intersections){.inters = NULL, .size = 0};

	co.cyl_min = -0.5;
	co.cyl_max = 0.5;
	co.cyl_closed = 1;
	xs.inters = malloc(sizeof(t_inter) * 4);
	ray_intersect(&co, r, &xs);
	assert_int_equal(xs.size, 4);
	free(xs.inters);
}

int	test_end_cap_cone_intersect(void)
{
	const struct CMUnitTest	cone_end_cap_intersect_tests[] = {
		cmocka_unit_test(end_cap_intersect_cone_1_test),
		cmocka_unit_test(end_cap_intersect_cone_2_test),
		cmocka_unit_test(end_cap_intersect_cone_3_test),
	};
	return (cmocka_run_group_tests(cone_end_cap_intersect_tests, NULL, NULL));
}
