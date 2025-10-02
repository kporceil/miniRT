/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:46:17 by lcesbron          #+#    #+#             */
/*   Updated: 2025/09/30 12:56:55 by lcesbron         ###   ########lyon.fr   */
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

	assert_double_equal(cyl.cyl_min, -DBL_MAX, EPSILON);
	assert_double_equal(cyl.cyl_max, DBL_MAX, EPSILON);
}

int	test_cylinder_create(void)
{
	const struct CMUnitTest	cylinder_create_tests[] = {
		cmocka_unit_test(create_cylinder_1_test),
	};
	return (cmocka_run_group_tests(cylinder_create_tests, NULL, NULL));
}
