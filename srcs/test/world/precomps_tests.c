/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precomps_tests.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 22:24:38 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/30 22:47:19 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "shape.h"
#include "ray.h"
#include "tests.h"

static void	shading_precomps_test(void **state)
{
	t_shape	s = sphere(0);
	t_precomp	comps = precompute((t_inter){&s, 4}, (t_ray){point(0, 0, -5), vector(0, 0, 1)});

	(void)state;
	assert_double_equal(comps.t, 4, 0.0001);
	assert_int_equal(comps.obj, &s);
	assert_tuple_equal(comps.point, point(0, 0, -1));
	assert_tuple_equal(comps.eyev, vector(0, 0, -1));
	assert_tuple_equal(comps.normalv, vector(0, 0, -1));
	assert_false(comps.inside);
}

static void	inside_obj_shading_precomps_test(void **state)
{
	t_shape	s = sphere(0);
	t_precomp	comps = precompute((t_inter){&s, 1}, (t_ray){point(0, 0, 0), vector(0, 0, 1)});

	(void)state;
	assert_double_equal(comps.t, 1, 0.0001);
	assert_int_equal(comps.obj, &s);
	assert_tuple_equal(comps.point, point(0, 0, 1));
	assert_tuple_equal(comps.eyev, vector(0, 0, -1));
	assert_tuple_equal(comps.normalv, vector(0, 0, -1));
	assert_true(comps.inside);
}

int	test_shading_precomputation(void)
{
	const struct CMUnitTest	shading_precomps_tests[] = {
		cmocka_unit_test(shading_precomps_test),
		cmocka_unit_test(inside_obj_shading_precomps_test),
	};
	return (cmocka_run_group_tests(shading_precomps_tests, NULL, NULL));
}
