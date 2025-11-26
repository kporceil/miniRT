/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:36:49 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/29 14:13:12 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "light.h"
#include "material.h"
#include "tests.h"

static void	eye_between_light_surface_test(void **state)
{
	t_tuple	eyev = vector(0, 0, -1);
	t_tuple	normalv = vector (0, 0, -1);
	t_plight	light = point_light(point (0, 0, -10), color(1, 1, 1));
	t_lighting	lighting_data = {.ambient = color(0.1, 0.1, 0.1), .m = material(), .light = light, .p = point(0, 0, 0), .eyev = eyev, .normalv = normalv, .in_shadow = false};
	t_color		result = lighting(lighting_data);

	(void)state;
	assert_color_equal(result, color(1.9, 1.9, 1.9));
}

static void	eye_45_degree_between_light_surface_test(void **state)
{
	t_tuple	eyev = vector(0, sqrt(2)/2, -sqrt(2)/2);
	t_tuple	normalv = vector (0, 0, -1);
	t_plight	light = point_light(point (0, 0, -10), color(1, 1, 1));
	t_lighting	lighting_data = {.ambient = color(0.1, 0.1, 0.1), .m = material(), .light = light, .p = point(0, 0, 0), .eyev = eyev, .normalv = normalv, .in_shadow = false};
	t_color		result = lighting(lighting_data);

	(void)state;
	assert_color_equal(result, color(1, 1, 1));
}

static void	eye_behind_light_45_degree_surface_test(void **state)
{
	t_tuple	eyev = vector(0, 0, -1);
	t_tuple	normalv = vector (0, 0, -1);
	t_plight	light = point_light(point (0, 10, -10), color(1, 1, 1));
	t_lighting	lighting_data = {.ambient = color(0.1, 0.1, 0.1), .m = material(), .light = light, .p = point(0, 0, 0), .eyev = eyev, .normalv = normalv, .in_shadow = false};
	t_color		result = lighting(lighting_data);

	(void)state;
	assert_color_equal(result, color(0.7364, 0.7364, 0.7364));
}

static void	eye_in_the_path_of_light_test(void **state)
{
	t_tuple	eyev = vector(0, -sqrt(2)/2, -sqrt(2)/2);
	t_tuple	normalv = vector (0, 0, -1);
	t_plight	light = point_light(point (0, 10, -10), color(1, 1, 1));
	t_lighting	lighting_data = {.ambient = color(0.1, 0.1, 0.1), .m = material(), .light = light, .p = point(0, 0, 0), .eyev = eyev, .normalv = normalv, .in_shadow = false};
	t_color		result = lighting(lighting_data);

	(void)state;
	assert_color_equal(result, color(1.6364, 1.6364, 1.6364));
}

static void	eye_behind_surface_test(void **state)
{
	t_tuple	eyev = vector(0, 0, -1);
	t_tuple	normalv = vector (0, 0, -1);
	t_plight	light = point_light(point (0, 0, 10), color(1, 1, 1));
	t_lighting	lighting_data = {.ambient = color(0.1, 0.1, 0.1), .m = material(), .light = light, .p = point(0, 0, 0), .eyev = eyev, .normalv = normalv, .in_shadow = false};
	t_color		result = lighting(lighting_data);

	(void)state;
	assert_color_equal(result, color(0.1, 0.1, 0.1));
}

int	test_phong(void)
{
	const struct CMUnitTest	phong_tests[] = {
		cmocka_unit_test(eye_between_light_surface_test),
		cmocka_unit_test(eye_45_degree_between_light_surface_test),
		cmocka_unit_test(eye_behind_light_45_degree_surface_test),
		cmocka_unit_test(eye_in_the_path_of_light_test),
		cmocka_unit_test(eye_behind_surface_test),
	};
	return (cmocka_run_group_tests(phong_tests, NULL, NULL));
}
