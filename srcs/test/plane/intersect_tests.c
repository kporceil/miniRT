/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:43:22 by kporceil          #+#    #+#             */
/*   Updated: 2025/09/12 14:16:47 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "shape.h"
#include "tests.h"
#include "light.h"
#include "ray.h"

static void	parallel_ray_plane_test(__unused void **state)
{
	t_shape	p = plane(0);
	t_ray	r = ray(point(0, 10, 0), vector(0, 0, 1));
	t_intersect	xs = ray_intersect(&p, r);
	
	assert_int_equal(xs.count, 0);
}

static void	coplanar_ray_plane_test(__unused void **state)
{
	t_shape	p = plane(0);
	t_ray	r = ray(point(0, 0, 0), vector(0, 0, 1));
	t_intersect	xs = ray_intersect(&p, r);
	
	assert_int_equal(xs.count, 0);
}

static void	above_ray_plane_test(__unused void **state)
{
	t_shape	p = plane(0);
	t_ray	r = ray(point(0, 1, 0), vector(0, -1, 0));
	t_intersect	xs = ray_intersect(&p, r);
	
	assert_int_equal(xs.count, 1);
	assert_double_equal(xs.object[0].point, 1, 0.0001);
	assert_int_equal(xs.object[0].s, &p);
}

static void	below_ray_plane_test(__unused void **state)
{
	t_shape	p = plane(0);
	t_ray	r = ray(point(0, -1, 0), vector(0, 1, 0));
	t_intersect	xs = ray_intersect(&p, r);
	
	assert_int_equal(xs.count, 1);
	assert_double_equal(xs.object[0].point, 1, 0.0001);
	assert_int_equal(xs.object[0].s, &p);
}

int	test_plane_intersect(void)
{
	const struct CMUnitTest	plane_intersect_tests[] = {
		cmocka_unit_test(parallel_ray_plane_test),
		cmocka_unit_test(coplanar_ray_plane_test),
		cmocka_unit_test(above_ray_plane_test),
		cmocka_unit_test(below_ray_plane_test),
	};
	return (cmocka_run_group_tests(plane_intersect_tests, NULL, NULL));
}
