/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_under_point_tests.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:35:31 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/26 16:55:07 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "tests.h"
#include "refract.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

static t_shape	glass_sphere(size_t id)
{
	t_shape	s = sphere(id);

	s.material.refractive_index = 1.5;
	s.material.transparency = 1;
	return (s);
}

static void	compute_under_point_test(__unused void **state)
{
	t_ray	r = ray(point(0, 0, -5), vector(0, 0, 1));
	t_shape	s = glass_sphere(0);
	shape_set_matrix(&s, matrix_translation(0, 0, 1));
	t_inter	i = (t_inter){.s = &s, .point = 5};
	t_intersections	xs = (t_intersections){&i, 1};
	t_precomp		comps = precompute(i, r, &xs);

	assert_double_greater(comps.under_point.z, 0.00005);
	assert_double_greater(comps.under_point.z, comps.point.z);
}

int	test_compute_under_point(void)
{
	const struct CMUnitTest	compute_under_point_tests[] = {
		cmocka_unit_test(compute_under_point_test),
	};
	return (cmocka_run_group_tests(compute_under_point_tests, NULL, NULL));
}
