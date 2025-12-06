/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precomp_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:26:31 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/27 18:03:11 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include <float.h>
#include "shape.h"
#include "tests.h"
#include "ray.h"
#include "light.h"
#include "tuples.h"

#ifndef EPSILON
# define EPSILON 0.0001
#endif

static void	smooth_triangle_precomp_1_test(__unused void **state)
{
	t_tuple	p[3];
	t_tuple	n[3];
	p[0] = point(0, 1, 0);
	p[1] = point(-1, 0, 0);
	p[2] = point(1, 0, 0);
	n[0] = point(0, 1, 0);
	n[1] = point(-1, 0, 0);
	n[2] = point(1, 0, 0);
	t_shape	tri = smooth_triangle(1, p, n);
	t_inter	i = (t_inter){.s = &tri, .point = 1, .u = 0.45, .v = 0.25};
	t_ray	r = ray(point(-0.2, 0.3, -2), vector(0, 0, 1));
	t_intersections	xs = (t_intersections){&i, 1};

	t_precomp	precomp = precompute(i, r, &xs);
	assert_tuple_equal(precomp.normalv, vector(-0.5547, 0.83205, 0));
}

int	test_smooth_triangle_precomp(void)
{
	const struct CMUnitTest	smooth_triangle_precomp_tests[] = {
		cmocka_unit_test(smooth_triangle_precomp_1_test),
	};
	return (cmocka_run_group_tests(smooth_triangle_precomp_tests, NULL, NULL));
}
