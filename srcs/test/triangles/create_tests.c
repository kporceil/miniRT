/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:26:31 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/10 17:33:38 by lcesbron         ###   ########lyon.fr   */
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

static void	create_triangle_1_test(__unused void **state)
{
	t_tuple	p1 = point(0, 1, 0);
	t_tuple	p2 = point(-1, 0, 0);
	t_tuple	p3 = point(1, 0, 0);
	t_shape	tri = triangle(1, p1, p2, p3);

	assert_tuple_equal(p1, tri.tri_p1);
	assert_tuple_equal(p2, tri.tri_p2);
	assert_tuple_equal(p3, tri.tri_p3);
	assert_tuple_equal(vector(-1, -1, 0), tri.tri_e1);
	assert_tuple_equal(vector(1, -1, 0), tri.tri_e2);
	assert_tuple_equal(vector(0, 0, -1), tri.tri_normal);
}

int	test_triangle_create(void)
{
	const struct CMUnitTest	triangle_create_tests[] = {
		cmocka_unit_test(create_triangle_1_test),
	};
	return (cmocka_run_group_tests(triangle_create_tests, NULL, NULL));
}
