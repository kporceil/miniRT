/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:27:39 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/30 23:46:02 by kporceil         ###   ########lyon.fr   */
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
	t_inter		inters[2] = {intersections[0].object[0], intersections[0].object[1]};

	(void)state;
	assert_int_equal(inters, inter_hit(inters, 2));
}

static void	negative_positive_t_hit_test(void **state)
{
	t_sphere	s = sphere(0);
	t_intersect intersections[1] = {ray_intersect(&s, ray(point(0, 0, 0), vector(0, 0, 1)))};
	t_inter		inters[2] = {intersections[0].object[0], intersections[0].object[1]};

	(void)state;
	assert_int_equal(inters + 1, inter_hit(inters, 2));
}

static void	negative_t_hit_test(void **state)
{
	t_sphere	s = sphere(0);
	t_intersect intersections[1] = {ray_intersect(&s, ray(point(0, 0, 2), vector(0, 0, 1)))};
	t_inter		inters[2] = {intersections[0].object[0], intersections[0].object[1]};

	(void)state;
	assert_int_equal(NULL, inter_hit(inters, 2));
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
	t_inter		inters[4] = {intersections[0].object[0], intersections[0].object[1], intersections[1].object[0], intersections[1].object[1]};
	assert_int_equal(inters + 3, inter_hit(inters, 4));
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
