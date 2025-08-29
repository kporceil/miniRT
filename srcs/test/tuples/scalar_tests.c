/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:37:44 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/21 15:56:01 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "tuples.h"
#include "tests.h"

static void	multiply_tuple_test(void **state)
{
	t_tuple	t1 = {1, -2, 3, -4};
	t_tuple	expected_result = {3.5, -7, 10.5, -14};
	t_tuple	result = tuple_scalar_mult(t1, 3.5);
	
	(void)state;
	assert_tuple_equal(result, expected_result);
}

static void	multiply_tuple_fraction_test(void **state)
{
	t_tuple	t1 = {1, -2, 3, -4};
	t_tuple	expected_result = {0.5, -1, 1.5, -2};
	t_tuple	result = tuple_scalar_mult(t1, 0.5);
	
	(void)state;
	assert_tuple_equal(result, expected_result);
}

static void	divide_tuple_test(void **state)
{
	t_tuple	t1 = {1, -2, 3, -4};
	t_tuple	expected_result = {0.5, -1, 1.5, -2};
	t_tuple	result = tuple_scalar_div(t1, 2);
	
	(void)state;
	assert_tuple_equal(result, expected_result);
}

int	test_tuple_scalar(void)
{
	const struct CMUnitTest	scalar_tests[] = {
		cmocka_unit_test(multiply_tuple_test),
		cmocka_unit_test(multiply_tuple_fraction_test),
		cmocka_unit_test(divide_tuple_test),
	};
	return (cmocka_run_group_tests(scalar_tests, NULL, NULL));
}
