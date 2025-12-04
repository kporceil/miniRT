/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:43:22 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/26 18:20:35 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include <math.h>
#include "shape.h"
#include "tests.h"
#include "ray.h"
#include "tuples.h"
#include "light.h"

#ifndef EPSILON
# define EPSILON 0.0001
#endif

static void	normal_cone_1_test(__unused void **state)
{
	t_shape	co = cone(1);
	t_tuple	n = normal_at(co, point(0, 0, 0), NULL);

	assert_tuple_equal(n, normalize(vector(0, 0, 0)));
}

static void	normal_cone_2_test(__unused void **state)
{
	t_shape	co = cone(1);
	t_tuple	n = normal_at(co, point(1, 1, 1), NULL);

	assert_tuple_equal(n, normalize(vector(1, -sqrt(2), 1)));
}

static void	normal_cone_3_test(__unused void **state)
{
	t_shape	co = cone(1);
	t_tuple	n = normal_at(co, point(-1, -1, 0), NULL);

	assert_tuple_equal(n, normalize(vector(-1, 1, 0)));
}

int	test_cone_normal(void)
{
	const struct CMUnitTest	cone_normal_tests[] = {
		cmocka_unit_test(normal_cone_1_test),
		cmocka_unit_test(normal_cone_2_test),
		cmocka_unit_test(normal_cone_3_test),
	};
	return (cmocka_run_group_tests(cone_normal_tests, NULL, NULL));
}
