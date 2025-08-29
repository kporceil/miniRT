/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magnitude_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:09:17 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/21 16:17:00 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <math.h>
#include "tests.h"
#include "tuples.h"

static void	magnitude_test_1(void **state)
{
	(void)state;
	assert_double_equal(magnitude(vector(1, 0, 0)), 1, 0.0001);
}

static void	magnitude_test_2(void **state)
{
	(void)state;
	assert_double_equal(magnitude(vector(0, 1, 0)), 1, 0.0001);
}

static void	magnitude_test_3(void **state)
{
	(void)state;
	assert_double_equal(magnitude(vector(0, 0, 1)), 1, 0.0001);
}

static void	magnitude_test_4(void **state)
{
	(void)state;
	assert_double_equal(magnitude(vector(1, 2, 3)), sqrt(14), 0.0001);
}

static void	magnitude_test_5(void **state)
{
	(void)state;
	assert_double_equal(magnitude(vector(-1, -2, -3)), sqrt(14), 0.0001);
}

int	test_tuple_magnitude(void)
{
	const struct CMUnitTest	magnitude_tests[] = {
		cmocka_unit_test(magnitude_test_1),
		cmocka_unit_test(magnitude_test_2),
		cmocka_unit_test(magnitude_test_3),
		cmocka_unit_test(magnitude_test_4),
		cmocka_unit_test(magnitude_test_5),
	};
	return (cmocka_run_group_tests(magnitude_tests, NULL, NULL));
}
