/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_checkers_tests.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:33:54 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/09 18:16:37 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "patterns.h"
#include "color.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

static void	uv_checker_test(__unused void **state)
{
	t_uvpat	checker = uv_checkers(2, 2, color(0, 0, 0), color(1, 1, 1));
	double	u[] = { 0.0, 0.5, 0.0, 0.5, 1.0 };
	double	v[] = { 0.0, 0.0, 0.5, 0.5, 1.0 };
	t_color	expected[] = { color(0, 0, 0), color(1, 1, 1), color(1, 1, 1), color(0, 0, 0), color(0, 0, 0) };
	for (size_t i = 0; i < 5; ++i) {
		assert_color_equal(expected[i], uv_pattern_at(checker, u[i], v[i]));
	}
}

static void	texturemap_test(__unused void **state)
{
	t_uvpat	checker = uv_checkers(16, 8, color(0, 0, 0), color(1, 1, 1));
	t_pattern	pattern = texture_map(checker, spherical_map);
	t_tuple		p[] = {
		point(0.4315, 0.4670, 0.7719),
		point(-0.9654, 0.2552, -0.0534),
		point(0.1039, 0.7090, 0.6975),
		point(-0.4986, -0.7856, -0.3663),
		point(-0.0317, -0.9395, 0.3411),
		point(0.4809, -0.7721, 0.4154),
		point(0.0285, -0.9612, -0.2745),
		point(-0.5734, -0.2162, -0.7903),
		point(0.7688, -0.1470, 0.6223),
		point(-0.7652, 0.2175, 0.6060),
	};
	t_color		expected[] = { color(1, 1, 1), color(0, 0, 0), color(1, 1, 1), color(0, 0, 0), color(0, 0, 0), color(0, 0, 0), color(0, 0, 0), color(1, 1, 1), color(0, 0, 0), color(0, 0, 0) };
	for (size_t i = 0; i < 10; ++i) {
		assert_color_equal(expected[i], pattern_at(pattern, p[i]));
	}
}

static void	align_check_test(__unused void **state)
{
	t_color	colors[5] = {color(1, 1, 1), color(1, 0, 0), color(1, 1, 0), color(0, 1, 0), color(0, 1, 1)};
	t_uvpat	pattern = uv_align_check(colors);
	t_color	e_col[] = {
		color(1, 1, 1),
		color(1, 0, 0),
		color(1, 1, 0),
		color(0, 1, 0),
		color(0, 1, 1),
	};
	double	u[] = { 0.5, 0.1, 0.9, 0.1, 0.9 };
	double	v[] = { 0.5, 0.9, 0.9, 0.1, 0.1 };
	for (size_t i = 0; i < 5; ++i) {
		assert_color_equal(e_col[i], uv_pattern_at(pattern, u[i], v[i]));
	}
}

int test_uv_checker_pattern(void)
{
	const struct CMUnitTest	uv_checker_tests[] = {
		cmocka_unit_test(uv_checker_test),
		cmocka_unit_test(texturemap_test),
		cmocka_unit_test(align_check_test),
	};
	return (cmocka_run_group_tests(uv_checker_tests, NULL, NULL));
}
