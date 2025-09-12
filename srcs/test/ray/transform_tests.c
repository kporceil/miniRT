/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 23:27:11 by kporceil          #+#    #+#             */
/*   Updated: 2025/09/12 13:40:27 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "ray.h"
#include "matrix.h"
#include "tests.h"

static void	ray_translation_test(void **state)
{
	t_ray	r = ray(point(1, 2, 3), vector(0, 1, 0));
	t_matrix	m = matrix_translation(3, 4, 5);
	t_ray	r2 = ray_transform(&r, &m);

	(void)state;
	assert_tuple_equal(r2.origin, point(4, 6, 8));
	assert_tuple_equal(r2.dir, r.dir);
}

static void	ray_scaling_test(void **state)
{
	t_ray	r = ray(point(1, 2, 3), vector(0, 1, 0));
	t_matrix	m = matrix_scaling(2, 3, 4);
	t_ray	r2 = ray_transform(&r, &m);

	(void)state;
	assert_tuple_equal(r2.origin, point(2, 6, 12));
	assert_tuple_equal(r2.dir, vector(0, 3, 0));
}

static void	ray_scaled_intersect_test(void **state)
{
	t_ray		r = ray(point(0, 0, -5), vector(0, 0, 1));
	t_shape	s = sphere(0);
	t_intersect	inter;
	
	(void)state;
	shape_set_matrix(&s, matrix_scaling(2, 2, 2));
	inter = ray_sphere_intersect(&s, ray_transform(&r, &s.inverted));
	assert_int_equal(inter.count, 2);
	assert_double_equal(inter.object[0].point, 3, 0.0001);
	assert_double_equal(inter.object[1].point, 7, 0.0001);
}

static void	ray_translate_intersect_test(void **state)
{
	t_ray		r = ray(point(0, 0, -5), vector(0, 0, 1));
	t_shape	s = sphere(0);
	t_intersect	inter;
	
	(void)state;
	shape_set_matrix(&s, matrix_translation(5, 0, 0));
	inter = ray_sphere_intersect(&s, ray_transform(&r, &s.inverted));
	assert_int_equal(inter.count, 0);
}

int	test_ray_transformation(void)
{
	const struct CMUnitTest	ray_transformation_tests[] = {
		cmocka_unit_test(ray_translation_test),
		cmocka_unit_test(ray_scaling_test),
		cmocka_unit_test(ray_scaled_intersect_test),
		cmocka_unit_test(ray_translate_intersect_test),
	};
	return (cmocka_run_group_tests(ray_transformation_tests, NULL, NULL));
}
