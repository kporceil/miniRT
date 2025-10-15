/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_intersect_tests.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:39:20 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/08 13:20:20 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "ray.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

static void	cube_intersect_test(__unused void **state)
{
	t_shape	c = cube(0);
	t_tuple	p[] = { point(5, 0.5, 0),
					point(-5, 0.5, 0),
					point(0.5, 5, 0),
					point(0.5, -5, 0),
					point(0.5, 0, 5),
					point(0.5, 0, -5),
					point(0, 0.5, 0) };
	t_tuple	dir[] = {   vector(-1, 0, 0),
						vector(1, 0, 0),
						vector(0, -1, 0),
						vector(0, 1, 0),
						vector(0, 0, -1),
						vector(0, 0, 1),
						vector(0, 0, 1) };
	double	t1[] = {4, 4, 4, 4, 4, 4, -1};
	double	t2[] = {6, 6, 6, 6, 6, 6, 1};
	for (size_t i = 0; i < 7; ++i) {
		t_ray r	= ray(p[i], dir[i]);
		t_intersections	xs = (t_intersections){malloc(sizeof(t_inter) * 2), 0};
		ray_intersect(&c, r, &xs);
		assert_int_equal(xs.size, 2);
		assert_double_equal(xs.inters[0].point, t1[i], 0.0001);
		assert_double_equal(xs.inters[1].point, t2[i], 0.0001);
		free(xs.inters);
	}
}

static void	no_intersect_test(__unused void **state)
{
	t_shape	c = cube(0);
	t_tuple	p[] = { point(-2, 0, 0),
					point(0, -2, 0),
					point(0, 0, -2),
					point(2, 0, 2),
					point(0, 2, 2),
					point(2, 2, 0) };
	t_tuple	dir[] = {   vector(0.2673, 0.5345, 0.8018),
						vector(0.8018, 0.2673, 0.5345),
						vector(0.5345, 0.8018, 0.2673),
						vector(0, 0, -1),
						vector(0, -1, 0),
						vector(-1, 0, 0) };
	for (size_t i = 0; i < 6; ++i) {
		t_ray	r = ray(p[i], dir[i]);
		t_intersections	xs = (t_intersections){NULL, 0};
		ray_intersect(&c, r, &xs);
		assert_int_equal(0, xs.size);
	}
}

int	test_cube_intersect(void)
{
	const struct CMUnitTest	cube_intersect_tests[] = {
		cmocka_unit_test(cube_intersect_test),
		cmocka_unit_test(no_intersect_test),
	};
	return (cmocka_run_group_tests(cube_intersect_tests, NULL, NULL));
}
