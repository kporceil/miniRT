/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:26:31 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/26 16:08:56 by lcesbron         ###   ########lyon.fr   */
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

static void	create_smooth_triangle_1_test(__unused void **state)
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

	assert_tuple_equal(p[0], tri.tri_p1);
	assert_tuple_equal(p[1], tri.tri_p2);
	assert_tuple_equal(p[2], tri.tri_p3);
	assert_tuple_equal(n[0], tri.tri_n1);
	assert_tuple_equal(n[1], tri.tri_n2);
	assert_tuple_equal(n[2], tri.tri_n3);
	assert_tuple_equal(vector(-1, -1, 0), tri.tri_e1);
	assert_tuple_equal(vector(1, -1, 0), tri.tri_e2);
}

int	test_smooth_triangle_create(void)
{
	const struct CMUnitTest	smooth_triangle_create_tests[] = {
		cmocka_unit_test(create_smooth_triangle_1_test),
	};
	return (cmocka_run_group_tests(smooth_triangle_create_tests, NULL, NULL));
}
