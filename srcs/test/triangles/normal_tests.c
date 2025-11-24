/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:26:31 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/10 18:55:02 by lcesbron         ###   ########lyon.fr   */
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
#include "light.h"

static void	normal_triangle_1_test(__unused void **state)
{
	t_tuple	p1 = point(0, 1, 0);
	t_tuple	p2 = point(-1, 0, 0);
	t_tuple	p3 = point(1, 0, 0);
	t_shape	tri = triangle(1, p1, p2, p3);
	t_tuple	n1 = normal_at(tri, point(0, 0.5, 0));
	t_tuple	n2 = normal_at(tri, point(-0.5, 0.75, 0));
	t_tuple	n3 = normal_at(tri, point(0.5, 0.25, 0));

	assert_tuple_equal(n1, tri.tri_normal);
	assert_tuple_equal(n2, tri.tri_normal);
	assert_tuple_equal(n3, tri.tri_normal);
}

int	test_triangle_normal(void)
{
	const struct CMUnitTest	triangle_normal_tests[] = {
		cmocka_unit_test(normal_triangle_1_test),
	};
	return (cmocka_run_group_tests(triangle_normal_tests, NULL, NULL));
}
