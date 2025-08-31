/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 13:02:02 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/31 13:31:09 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <math.h>
#include "camera.h"
#include "matrix.h"
#include "tests.h"

static void	camera_create_test(void **state)
{
	t_camera	cam = camera(160, 120, M_PI / 2);

	(void)state;
	assert_int_equal(160, cam.hsize);
	assert_int_equal(120, cam.vsize);
	assert_double_equal(M_PI / 2, cam.fov, 0.0001);
	assert_matrix_equal(identity_matrix(4), cam.transform);
}

static void	camera_create_test2(void **state)
{
	t_camera	cam = camera(200, 125, M_PI / 2);

	(void)state;
	assert_int_equal(200, cam.hsize);
	assert_int_equal(125, cam.vsize);
	assert_double_equal(M_PI / 2, cam.fov, 0.0001);
	assert_double_equal(0.01, cam.pixel_size, 0.0001);
	assert_matrix_equal(identity_matrix(4), cam.transform);
}

static void	camera_create_test3(void **state)
{
	t_camera	cam = camera(125, 200, M_PI / 2);

	(void)state;
	assert_int_equal(125, cam.hsize);
	assert_int_equal(200, cam.vsize);
	assert_double_equal(M_PI / 2, cam.fov, 0.0001);
	assert_double_equal(0.01, cam.pixel_size, 0.0001);
	assert_matrix_equal(identity_matrix(4), cam.transform);
}

int	test_camera_create(void)
{
	const struct CMUnitTest	camera_create_tests[] = {
		cmocka_unit_test(camera_create_test),
		cmocka_unit_test(camera_create_test2),
		cmocka_unit_test(camera_create_test3),
	};
	return (cmocka_run_group_tests(camera_create_tests, NULL, NULL));
}
