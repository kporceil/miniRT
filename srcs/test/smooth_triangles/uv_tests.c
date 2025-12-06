/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_tests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:26:31 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/26 16:43:49 by lcesbron         ###   ########lyon.fr   */
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
#include "tuples.h"

#ifndef EPSILON
# define EPSILON 0.0001
#endif

static void	uv_1_test(__unused void **state)
{
	t_tuple	p[3];
	t_tuple	n[3];
	t_ray	r = ray(point(-0.2, 0.3, -2), vector(0, 0, 1));
	p[0] = point(0, 1, 0);
	p[1] = point(-1, 0, 0);
	p[2] = point(1, 0, 0);
	n[0] = point(0, 1, 0);
	n[1] = point(-1, 0, 0);
	n[2] = point(1, 0, 0);
	t_shape	tri = smooth_triangle(1, p, n);
	t_intersections xs = (t_intersections){0};

	xs.inters = malloc(sizeof(t_inter) * 1);
	ray_triangle_intersect(&tri, r, &xs);
	assert_double_equal(xs.inters[0].u, 0.45, EPSILON);
	assert_double_equal(xs.inters[0].v, 0.25, EPSILON);
	free(xs.inters);
}

int	test_smooth_triangle_uv(void)
{
	const struct CMUnitTest	smooth_triangle_uv_tests[] = {
		cmocka_unit_test(uv_1_test),
	};
	return (cmocka_run_group_tests(smooth_triangle_uv_tests, NULL, NULL));
}
