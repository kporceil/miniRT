/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:46:17 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/01 18:30:52 by lcesbron         ###   ########lyon.fr   */
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

static void	create_cylinder_1_test(__unused void **state)
{
	t_shape	cyl = cylinder(1);

	assert_double_equal(cyl.cyl_min, -INFINITY, EPSILON);
	assert_double_equal(cyl.cyl_max, INFINITY, EPSILON);
}

static void	closed_cylinder_1_test(__unused void **state)
{
	t_shape	cyl = cylinder(1);

	assert_int_equal(cyl.cyl_closed, 0);
}

int	test_cylinder_create(void)
{
	const struct CMUnitTest	cylinder_create_tests[] = {
		cmocka_unit_test(create_cylinder_1_test),
		cmocka_unit_test(closed_cylinder_1_test),
	};
	return (cmocka_run_group_tests(cylinder_create_tests, NULL, NULL));
}
