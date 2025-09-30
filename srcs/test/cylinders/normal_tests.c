/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:43:22 by lcesbron          #+#    #+#             */
/*   Updated: 2025/09/30 11:33:47 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include "shape.h"
#include "tests.h"
#include "ray.h"
#include "tuples.h"
#include "light.h"

#ifndef EPSILON
# define EPSILON 0.0001
#endif

static void	normal_cylinder_1_test(__unused void **state)
{
	t_shape	cyl = cylinder(1);
	t_tuple	n = normal_at(cyl, point(1, 0, 0));

	assert_tuple_equal(n, vector(1, 0, 0));
}

static void	normal_cylinder_2_test(__unused void **state)
{
	t_shape	cyl = cylinder(1);
	t_tuple	n = normal_at(cyl, point(0, 5, -1));

	assert_tuple_equal(n, vector(0, 0, -1));
}

static void	normal_cylinder_3_test(__unused void **state)
{
	t_shape	cyl = cylinder(1);
	t_tuple	n = normal_at(cyl, point(0, -2, 1));

	assert_tuple_equal(n, vector(0, 0, 1));
}

static void	normal_cylinder_4_test(__unused void **state)
{
	t_shape	cyl = cylinder(1);
	t_tuple	n = normal_at(cyl, point(-1, 1, 0));

	assert_tuple_equal(n, vector(-1, 0, 0));
}

int	test_cylinder_normal(void)
{
	const struct CMUnitTest	cylinder_normal_tests[] = {
		cmocka_unit_test(normal_cylinder_1_test),
		cmocka_unit_test(normal_cylinder_2_test),
		cmocka_unit_test(normal_cylinder_3_test),
		cmocka_unit_test(normal_cylinder_4_test),
	};
	return (cmocka_run_group_tests(cylinder_normal_tests, NULL, NULL));
}
