/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   striped_pattern_tests.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:12:58 by kporceil          #+#    #+#             */
/*   Updated: 2025/09/25 18:11:54 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "light.h"
#include "material.h"
#include "tuples.h"
#include "patterns.h"
#include "tests.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

void	create_test(__unused void **state)
{
	t_pattern	pat = pattern(STRIPED, color(1, 1, 1), color(0, 0, 0));

	assert_int_equal(pat.type, STRIPED);
	assert_color_equal(pat.a, color(1, 1, 1));
	assert_color_equal(pat.b, color(0, 0, 0));
}

void	y_pattern_test(__unused void **state)
{
	t_pattern	pat = pattern(STRIPED, color(1, 1, 1), color(0, 0, 0));

	assert_color_equal(color(1, 1, 1), pattern_at(pat, point(0, 0, 0)));
	assert_color_equal(color(1, 1, 1), pattern_at(pat, point(0, 1, 0)));
	assert_color_equal(color(1, 1, 1), pattern_at(pat, point(0, 2, 0)));
}

void	z_pattern_test(__unused void **state)
{
	t_pattern	pat = pattern(STRIPED, color(1, 1, 1), color(0, 0, 0));

	assert_color_equal(color(1, 1, 1), pattern_at(pat, point(0, 0, 0)));
	assert_color_equal(color(1, 1, 1), pattern_at(pat, point(0, 0, 1)));
	assert_color_equal(color(1, 1, 1), pattern_at(pat, point(0, 0, 2)));
}

void	x_pattern_test(__unused void **state)
{
	t_pattern	pat = pattern(STRIPED, color(1, 1, 1), color(0, 0, 0));

	assert_color_equal(color(1, 1, 1), pattern_at(pat, point(0, 0, 0)));
	assert_color_equal(color(1, 1, 1), pattern_at(pat, point(0.9, 0, 0)));
	assert_color_equal(color(0, 0, 0), pattern_at(pat, point(1, 0, 0)));
	assert_color_equal(color(0, 0, 0), pattern_at(pat, point(-0.1, 0, 0)));
	assert_color_equal(color(0, 0, 0), pattern_at(pat, point(-1, 0, 0)));
	assert_color_equal(color(1, 1, 1), pattern_at(pat, point(-1.1, 0, 0)));
}

void	lighting_pattern_test(__unused void **state)
{
	t_material	m = { .pat = pattern(STRIPED, color(1, 1, 1), color(0, 0, 0)), .ambient = 1, .diffuse = 0, .specular = 0};
	t_lighting	l = { .m = m, .eyev = vector(0, 0, -1), .normalv = vector(0, 0, -1), .light = point_light(point(0, 0, -10), color(1, 1, 1)), .p = point(0.9, 0, 0), .in_shadow = false };
	t_color		c1 = lighting(l);
	l.p.x = 1.1;
	t_color		c2 = lighting(l);

	assert_color_equal(c1, color(1, 1, 1));
	assert_color_equal(c2, color(0, 0, 0));
}

int	test_striped_pattern(void)
{
	const struct CMUnitTest	striped_pattern_tests[] = {
		cmocka_unit_test(create_test),
		cmocka_unit_test(y_pattern_test),
		cmocka_unit_test(z_pattern_test),
		cmocka_unit_test(x_pattern_test),
		cmocka_unit_test(lighting_pattern_test),
	};
	return (cmocka_run_group_tests(striped_pattern_tests, NULL, NULL));
}


