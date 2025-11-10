/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:08:40 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/09 19:02:20 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "tests.h"
#include "patterns.h"
#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

static void	plane_mapping_test(__unused void **state)
{
	t_tuple	p[] = {
		point(0.25, 0, 0.5),
		point(0.25, 0, -0.25),
		point(0.25, 0.5, -0.25),
		point(1.25, 0, 0.5),
		point(0.25, 0, -1.75),
		point(1, 0, -1),
		point(0, 0, 0),
	};
	double	e_u[] = {0.25, 0.25, 0.25, 0.25, 0.25, 0, 0};
	double	e_v[] = {0.5, 0.75, 0.75, 0.5, 0.25, 0, 0};
	for (size_t i = 0; i < 7; ++i) {
		double	u, v;
		planar_map(p[i], &u, &v);
		assert_double_equal(e_u[i], u, 0.0001);
		assert_double_equal(e_v[i], v, 0.0001);
	}
}

static void	cylinder_mapping_test(__unused void **state)
{
	t_tuple	p[] = {
		point(0, 0, -1),
		point(0, 0.5, -1),
		point(0, 1, -1),
		point(0.70711, 0.5, -0.70711),
		point(1, 0.5, 0),
		point(0.70711, 0.5, 0.70711),
		point(0, -0.25, 1),
		point(-0.70711, 0.5, 0.70711),
		point(-1, 1.25, 0),
		point(-0.70711, 0.5, -0.70711),
	};
	double	e_u[] = { 0, 0, 0, 0.125, 0.25, 0.375, 0.5, 0.625, 0.75, 0.875 };
	double	e_v[] = { 0, 0.5, 0, 0.5, 0.5, 0.5, 0.75, 0.5, 0.25, 0.5};
	for (size_t i = 0; i < 10; ++i) {
		double	u, v;
		cylindrical_map(p[i], &u, &v);
		assert_double_equal(e_u[i], u, 0.0001);
		assert_double_equal(e_v[i], v, 0.0001);
	}
}

static void	sphere_mapping_test(__unused void **state)
{
	t_tuple	p[] = {
		point(0, 0, -1),
		point(1, 0, 0),
		point(0, 0, 1),
		point(-1, 0, 0),
		point(0, 1, 0),
		point(0, -1, 0),
		point(sqrt(2)/2, sqrt(2)/2, 0),
	};
	double	e_u[] = { 0.0, 0.25, 0.5, 0.75, 0.5, 0.5, 0.25 };
	double	e_v[] = { 0.5, 0.5, 0.5, 0.5, 1.0, 0.0, 0.75 };
	double	u;
	double	v;
	for (size_t i = 0; i < 7; ++i) {
		spherical_map(p[i], &u, &v);
		assert_double_equal(e_u[i], u, 0.0001);
		assert_double_equal(e_v[i], v, 0.0001);
	}
}

static void	cube_face_test(__unused void **state)
{
	int	face[] = { LEFTF, RIGHTF, FRONTF, BACKF, UPF, DOWNF };
	t_tuple	p[] = {
		point(-1, 0.5, -0.25),
		point(1.1, -0.75, 0.8),
		point(0.1, 0.6, 0.9),
		point(-0.7, 0, -2),
		point(0.5, 1, 0.9),
		point(-0.2, -1.3, 1.1),
	};
	for (size_t i = 0; i < 6; ++i) {
		assert_int_equal(face[i], face_from_point(p[i]));
	}
}

static void	cube_front_test(__unused void **state)
{
	t_tuple	p[] = {
		point(-0.5, 0.5, 1),
		point(0.5, -0.5, 1),
	};
	double	e_u[] = {0.25, 0.75};
	double	e_v[] = {0.75, 0.25};
	for (size_t i = 0; i < 2; ++i) {
		double	u, v;
		cubic_map_front(p[i], &u, &v);
		assert_double_equal(e_u[i], u, 0.0001);
		assert_double_equal(e_v[i], v, 0.0001);
	}
}

static void	cube_back_test(__unused void **state)
{
	t_tuple	p[] = {
		point(0.5, 0.5, 1),
		point(-0.5, -0.5, 1),
	};
	double	e_u[] = {0.25, 0.75};
	double	e_v[] = {0.75, 0.25};
	for (size_t i = 0; i < 2; ++i) {
		double	u, v;
		cubic_map_back(p[i], &u, &v);
		assert_double_equal(e_u[i], u, 0.0001);
		assert_double_equal(e_v[i], v, 0.0001);
	}
}

static void	cube_left_test(__unused void **state)
{
	t_tuple	p[] = {
		point(-1, 0.5, -0.5),
		point(-1, -0.5, 0.5),
	};
	double	e_u[] = {0.25, 0.75};
	double	e_v[] = {0.75, 0.25};
	for (size_t i = 0; i < 2; ++i) {
		double	u, v;
		cubic_map_left(p[i], &u, &v);
		assert_double_equal(e_u[i], u, 0.0001);
		assert_double_equal(e_v[i], v, 0.0001);
	}
}

static void	cube_right_test(__unused void **state)
{
	t_tuple	p[] = {
		point(1, 0.5, 0.5),
		point(1, -0.5, -0.5),
	};
	double	e_u[] = {0.25, 0.75};
	double	e_v[] = {0.75, 0.25};
	for (size_t i = 0; i < 2; ++i) {
		double	u, v;
		cubic_map_right(p[i], &u, &v);
		assert_double_equal(e_u[i], u, 0.0001);
		assert_double_equal(e_v[i], v, 0.0001);
	}
}

static void	cube_up_test(__unused void **state)
{
	t_tuple	p[] = {
		point(-0.5, 1, -0.5),
		point(0.5, 1, 0.5),
	};
	double	e_u[] = {0.25, 0.75};
	double	e_v[] = {0.75, 0.25};
	for (size_t i = 0; i < 2; ++i) {
		double	u, v;
		cubic_map_up(p[i], &u, &v);
		assert_double_equal(e_u[i], u, 0.0001);
		assert_double_equal(e_v[i], v, 0.0001);
	}
}

static void	cube_down_test(__unused void **state)
{
	t_tuple	p[] = {
		point(-0.5, -1, 0.5),
		point(0.5, -1, -0.5),
	};
	double	e_u[] = {0.25, 0.75};
	double	e_v[] = {0.75, 0.25};
	for (size_t i = 0; i < 2; ++i) {
		double	u, v;
		cubic_map_down(p[i], &u, &v);
		assert_double_equal(e_u[i], u, 0.0001);
		assert_double_equal(e_v[i], v, 0.0001);
	}
}

static void	cube_test(__unused void **state)
{
	t_color	red = color(1, 0, 0);
	t_color	yellow = color(1, 1, 0);
	t_color	brown = color(1, 0.5, 0);
	t_color	green = color(0, 1, 0);
	t_color	cyan = color(0, 1, 1);
	t_color	blue = color(0, 0, 1);
	t_color	purple = color(1, 0, 1);
	t_color	white = color(1, 1, 1);
	t_uvpat	left = uv_align_check((t_color [5]){yellow, cyan, red, blue, brown});
	t_uvpat	front = uv_align_check((t_color [5]){cyan, red, yellow, brown, green});
	t_uvpat	right = uv_align_check((t_color [5]){red, yellow, purple, green, white});
	t_uvpat	back = uv_align_check((t_color [5]){green, purple, cyan, white, blue});
	t_uvpat	up = uv_align_check((t_color [5]){brown, cyan, purple, red, yellow});
	t_uvpat	down = uv_align_check((t_color [5]){purple, brown, green, blue, white});
	t_pattern	pat = cube_pattern((t_uvpat [6]){front, back, right, left, up, down});
	t_tuple	p[] = {
		point(-1, 0, 0),
		point(-1, 0.9, -0.9),
		point(-1, 0.9, 0.9),
		point(-1, -0.9, -0.9),
		point(-1, -0.9, 0.9),
		point(0, 0, 1),
		point(-0.9, 0.9, 1),
		point(0.9, 0.9, 1),
		point(-0.9, -0.9, 1),
		point(0.9, -0.9, 1),
		point(1, 0, 0),
		point(1, 0.9, 0.9),
		point(1, 0.9, -0.9),
		point(1, -0.9, 0.9),
		point(1, -0.9, -0.9),
		point(0, 0, -1),
		point(0.9, 0.9, -1),
		point(-0.9, 0.9, -1),
		point(0.9, -0.9, -1),
		point(-0.9, -0.9, -1),
		point(0, 1, 0),
		point(-0.9, 1, -0.9),
		point(0.9, 1, -0.9),
		point(-0.9, 1, 0.9),
		point(0.9, 1, 0.9),
		point(0, -1, 0),
		point(-0.9, -1, 0.9),
		point(0.9, -1, 0.9),
		point(-0.9, -1, -0.9),
		point(0.9, -1, -0.9),
	};
	t_color	cols[] = {
		yellow,
		cyan,
		red,
		blue,
		brown,
		cyan,
		red,
		yellow,
		brown,
		green,
		red,
		yellow,
		purple,
		green,
		white,
		green,
		purple,
		cyan,
		white,
		blue,
		brown,
		cyan,
		purple,
		red,
		yellow,
		purple,
		brown,
		green,
		blue,
		white,
	};
	for (size_t i = 0; i < 30; ++i) {
		assert_color_equal(cols[i], pattern_at(pat, p[i]));
	}
}

int	test_mapping(void)
{
	const struct CMUnitTest	mapping_tests[] = {
		cmocka_unit_test(sphere_mapping_test),
		cmocka_unit_test(plane_mapping_test),
		cmocka_unit_test(cylinder_mapping_test),
		cmocka_unit_test(cube_face_test),
		cmocka_unit_test(cube_front_test),
		cmocka_unit_test(cube_back_test),
		cmocka_unit_test(cube_left_test),
		cmocka_unit_test(cube_right_test),
		cmocka_unit_test(cube_up_test),
		cmocka_unit_test(cube_down_test),
		cmocka_unit_test(cube_test),
	};
	return (cmocka_run_group_tests(mapping_tests, NULL, NULL));
}
