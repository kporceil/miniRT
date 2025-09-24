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
#include <stdlib.h>
#include "ray.h"

static void	positive_t_hit_test(void **state)
{
	t_shape	s = sphere(0);
	t_intersections inter = {malloc(sizeof(t_inter) * 2), 0};

	(void)state;
	ray_sphere_intersect(&s, ray(point(0, 0, -2), vector(0, 0, 1)), &inter);
	assert_int_equal(inter.inters, inter_hit(inter.inters, 2));
	free(inter.inters);
}

static void	negative_positive_t_hit_test(void **state)
{
	t_shape	s = sphere(0);
	t_intersections	inter = {malloc(sizeof(t_inter) * 2), 0};

	(void)state;
	ray_sphere_intersect(&s, ray(point(0, 0, 0), vector(0, 0, 1)), &inter);
	assert_int_equal(inter.inters + 1, inter_hit(inter.inters, 2));
	free(inter.inters);
}

static void	negative_t_hit_test(void **state)
{
	t_shape	s = sphere(0);
	t_intersections inter = {malloc(sizeof(t_inter) * 2), 0};

	(void)state;
	ray_sphere_intersect(&s, ray(point(0, 0, 2), vector(0, 0, 1)), &inter);
	assert_int_equal(NULL, inter_hit(inter.inters, 2));
	free(inter.inters);
}

static void	positive_t_hit_test2(void **state)
{
	t_shape	s = sphere(0);
	t_intersections	inter = {malloc(sizeof(t_inter) * 4), 0};
	ray_sphere_intersect(&s, ray(point(0, 0, 6), vector(0, 0, 1)), &inter);
	ray_sphere_intersect(&s, ray(point(0, 0, 0), vector(0, 0, 1)), &inter);

	(void)state;
	inter.inters[0].point = 5;
	inter.inters[1].point = 7;
	inter.inters[2].point = -3;
	inter.inters[3].point = 2;
	assert_int_equal(inter.inters + 3, inter_hit(inter.inters, 4));
	free(inter.inters);
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
