/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:41:16 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/21 19:08:24 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "tuples.h"
#include "tests.h"

#define EPSILON 0.00001

static void	point_creation_test(void **state)
{
	t_tuple	p;

	(void)state;
	p = point(4, -4, 3);
	assert_double_equal(p.w, 1, EPSILON);
}

static void	vector_creation_test(void **state)
{
	t_tuple	v;

	(void)state;
	v = vector(4, -4, 3);
	assert_double_equal(v.w, 0, EPSILON);
}

int	test_tuple_creation(void)
{
	const struct CMUnitTest	create_tests[] = {
		cmocka_unit_test(point_creation_test),
		cmocka_unit_test(vector_creation_test),
	};
	return (cmocka_run_group_tests(create_tests, NULL, NULL));
}
