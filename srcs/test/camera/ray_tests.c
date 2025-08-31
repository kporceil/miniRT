/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 13:38:33 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/31 13:53:10 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <math.h>
#include "camera.h"
#include "ray.h"
#include "tests.h"

static void	camera_ray_test1(void **state)
{
	t_camera	cam = camera(201, 101, M_PI / 2);
	t_ray		r = ray_for_pixel(cam, 100, 50);

	(void)state;
	assert_tuple_equal(r.origin, point(0, 0, 0));
	assert_tuple_equal(r.direction, vector(0, 0, -1));
}

static void	camera_ray_test2(void **state)
{
	t_camera	cam = camera(201, 101, M_PI / 2);
	t_ray		r = ray_for_pixel(cam, 0, 0);

	(void)state;
	assert_tuple_equal(r.origin, point(0, 0, 0));
	assert_tuple_equal(r.direction, vector(0.66519, 0.33259, -0.66851));
}

static void	camera_ray_test3(void **state)
{
	t_camera	cam = camera(201, 101, M_PI / 2);
	camera_set_transform(&cam, matrix_mult(matrix_y_rotation(M_PI/4), matrix_translation(0, -2, 5)));
	t_ray		r = ray_for_pixel(cam, 100, 50);

	(void)state;
	assert_tuple_equal(r.origin, point(0, 2, -5));
	assert_tuple_equal(r.direction, vector(sqrt(2)/2, 0, -(sqrt(2)/2)));
}

int	test_camera_ray(void)
{
	const struct CMUnitTest	camera_ray_tests[] = {
		cmocka_unit_test(camera_ray_test1),
		cmocka_unit_test(camera_ray_test2),
		cmocka_unit_test(camera_ray_test3),
	};
	return (cmocka_run_group_tests(camera_ray_tests, NULL, NULL));
}
