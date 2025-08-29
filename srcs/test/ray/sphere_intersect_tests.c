/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect_tests.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:52:49 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/27 22:20:46 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "ray.h"
#include "spheres.h"

static void	ray_sphere_intersect_test1(void **state)
{
	t_sphere	s = sphere(0);
	t_intersect	intersect = ray_intersect(&s, ray(point(0, 0, -5), vector(0, 0, 1)));

	(void)state;
	assert_int_equal(intersect.count, 2);
	assert_int_equal(intersect.object[0].s, &s);
	assert_int_equal(intersect.object[1].s, &s);
	assert_double_equal(intersect.object[0].point, 4.0, 0.0001);
	assert_double_equal(intersect.object[1].point, 6.0, 0.0001);
}

static void	ray_sphere_tangent_intersect_test(void **state)
{
	t_sphere	s = sphere(0);
	t_intersect	intersect = ray_intersect(&s, ray(point(0, 1, -5), vector(0, 0, 1)));

	(void)state;
	assert_int_equal(intersect.count, 2);
	assert_int_equal(intersect.object[0].s, &s);
	assert_int_equal(intersect.object[1].s, &s);
	assert_double_equal(intersect.object[0].point, 5.0, 0.0001);
	assert_double_equal(intersect.object[1].point, 5.0, 0.0001);
}

static void	ray_sphere_no_intersect_test(void **state)
{
	t_sphere	s = sphere(0);
	t_intersect	intersect = ray_intersect(&s, ray(point(0, 2, -5), vector(0, 0, 1)));

	(void)state;
	assert_int_equal(intersect.count, 0);
}

static void	ray_inside_sphere_intersect_test(void **state)
{
	t_sphere	s = sphere(0);
	t_intersect	intersect = ray_intersect(&s, ray(point(0, 0, 0), vector(0, 0, 1)));

	(void)state;
	assert_int_equal(intersect.count, 2);
	assert_int_equal(intersect.object[0].s, &s);
	assert_int_equal(intersect.object[1].s, &s);
	assert_double_equal(intersect.object[0].point, -1.0, 0.0001);
	assert_double_equal(intersect.object[1].point, 1.0, 0.0001);
}

static void	ray_sphere_intersect_test2(void **state)
{
	t_sphere	s = sphere(0);
	t_intersect	intersect = ray_intersect(&s, ray(point(0, 0, 5), vector(0, 0, 1)));

	(void)state;
	assert_int_equal(intersect.count, 2);
	assert_int_equal(intersect.object[0].s, &s);
	assert_int_equal(intersect.object[1].s, &s);
	assert_double_equal(intersect.object[0].point, -6.0, 0.0001);
	assert_double_equal(intersect.object[1].point, -4.0, 0.0001);
}

int	test_ray_sphere_intersect(void)
{
	const struct CMUnitTest	ray_sphere_intersect_tests[] = {
		cmocka_unit_test(ray_sphere_intersect_test1),
		cmocka_unit_test(ray_sphere_tangent_intersect_test),
		cmocka_unit_test(ray_sphere_no_intersect_test),
		cmocka_unit_test(ray_inside_sphere_intersect_test),
		cmocka_unit_test(ray_sphere_intersect_test2),
	};
	return (cmocka_run_group_tests(ray_sphere_intersect_tests, NULL, NULL));
}
