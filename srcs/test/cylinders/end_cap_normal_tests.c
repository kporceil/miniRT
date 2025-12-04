/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_cap_normal_tests.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:43:22 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/26 18:17:04 by lcesbron         ###   ########lyon.fr   */
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

static void	end_cap_normal_cylinder_1_test(__unused void **state)
{
	t_shape	cyl = cylinder(1);
	t_tuple	n;

	cyl.cyl_min = 1;
	cyl.cyl_max = 2;
	cyl.cyl_closed = 1;
	n = normal_at(cyl, point(0, 1, 0), NULL);
	assert_tuple_equal(n, vector(0, -1, 0));
}

static void	end_cap_normal_cylinder_2_test(__unused void **state)
{
	t_shape	cyl = cylinder(1);
	t_tuple	n;

	cyl.cyl_min = 1;
	cyl.cyl_max = 2;
	cyl.cyl_closed = 1;
	n = normal_at(cyl, point(0.5, 1, 0), NULL);
	assert_tuple_equal(n, vector(0, -1, 0));
}

static void	end_cap_normal_cylinder_3_test(__unused void **state)
{
	t_shape	cyl = cylinder(1);
	t_tuple	n;

	cyl.cyl_min = 1;
	cyl.cyl_max = 2;
	cyl.cyl_closed = 1;
	n = normal_at(cyl, point(0, 1, 0.5), NULL);
	assert_tuple_equal(n, vector(0, -1, 0));
}

static void	end_cap_normal_cylinder_4_test(__unused void **state)
{
	t_shape	cyl = cylinder(1);
	t_tuple	n;

	cyl.cyl_min = 1;
	cyl.cyl_max = 2;
	cyl.cyl_closed = 1;
	n = normal_at(cyl, point(0, 2, 0), NULL);
	assert_tuple_equal(n, vector(0, 1, 0));
}

static void	end_cap_normal_cylinder_5_test(__unused void **state)
{
	t_shape	cyl = cylinder(1);
	t_tuple	n;

	cyl.cyl_min = 1;
	cyl.cyl_max = 2;
	cyl.cyl_closed = 1;
	n = normal_at(cyl, point(0.5, 2, 0), NULL);
	assert_tuple_equal(n, vector(0, 1, 0));
}

static void	end_cap_normal_cylinder_6_test(__unused void **state)
{
	t_shape	cyl = cylinder(1);
	t_tuple	n;

	cyl.cyl_min = 1;
	cyl.cyl_max = 2;
	cyl.cyl_closed = 1;
	n = normal_at(cyl, point(0, 2, 0.5), NULL);
	assert_tuple_equal(n, vector(0, 1, 0));
}

int	test_end_cap_cylinder_normal(void)
{
	const struct CMUnitTest	end_cap_cylinder_normal_tests[] = {
		cmocka_unit_test(end_cap_normal_cylinder_1_test),
		cmocka_unit_test(end_cap_normal_cylinder_2_test),
		cmocka_unit_test(end_cap_normal_cylinder_3_test),
		cmocka_unit_test(end_cap_normal_cylinder_4_test),
		cmocka_unit_test(end_cap_normal_cylinder_5_test),
		cmocka_unit_test(end_cap_normal_cylinder_6_test),
	};
	return (cmocka_run_group_tests(end_cap_cylinder_normal_tests, NULL, NULL));
}
