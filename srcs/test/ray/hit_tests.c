/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:27:39 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/28 21:28:17 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "ray.h"

static void	positive_t_hit_test(void **state)
{
	t_sphere	s = sphere(0);
	t_intersect intersections[1] = {ray_intersect(&s, ray(point(0, 0, -2), vector(0, 0, 1)))};

	(void)state;
	assert_int_equal(intersections[0].object, inter_hit(intersections, 1));
}

static void	negative_positive_t_hit_test(void **state)
{
	t_sphere	s = sphere(0);
	t_intersect intersections[1] = {ray_intersect(&s, ray(point(0, 0, 0), vector(0, 0, 1)))};

	(void)state;
	assert_int_equal(intersections[0].object + 1, inter_hit(intersections, 1));
}

static void	negative_t_hit_test(void **state)
{
	t_sphere	s = sphere(0);
	t_intersect intersections[1] = {ray_intersect(&s, ray(point(0, 0, 2), vector(0, 0, 1)))};

	(void)state;
	assert_int_equal(NULL, inter_hit(intersections, 1));
}

static void	positive_t_hit_test2(void **state)
{
	t_sphere	s = sphere(0);
	t_intersect intersections[2] = {ray_intersect(&s, ray(point(0, 0, 6), vector(0, 0, 1))), ray_intersect(&s, ray(point(0, 0, 0), vector(0, 0, 1)))};

	(void)state;
	intersections[0].object[0].point = 5;
	intersections[0].object[1].point = 7;
	intersections[1].object[0].point = -3;
	intersections[1].object[1].point = 2;
	assert_int_equal(intersections[1].object + 1, inter_hit(intersections, 2));
}

int	test_ray_hit(void)
{
	const struct CMUnitTest	ray_hit_tests[] = {
		cmocka_unit_test(positive_t_hit_test),
		cmocka_unit_test(negative_positive_t_hit_test),
		cmocka_unit_test(negative_t_hit_test),
		cmocka_unit_test(positive_t_hit_test2),
	};
	return (cmocka_run_group_tests(ray_hit_tests, NULL, NULL));
}
