/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substract_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 19:23:05 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/21 15:57:43 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "tuples.h"
#include "tests.h"

void	substract_point_test(void **state)
{
	t_tuple	t1 = point(3, 2, 1);
	t_tuple	t2 = point(5, 6, 7);
	t_tuple	expected_result = vector(-2, -4, -6);
	t_tuple	result = tuple_substract(t1, t2);

	(void)state;
	assert_tuple_equal(result, expected_result);
}

void	substract_vec_from_point_test(void **state)
{
	t_tuple	t1 = point(3, 2, 1);
	t_tuple	t2 = vector(5, 6, 7);
	t_tuple	expected_result = point(-2, -4, -6);
	t_tuple	result = tuple_substract(t1, t2);

	(void)state;
	assert_tuple_equal(result, expected_result);
}

void	substract_vector_test(void **state)
{
	t_tuple	t1 = vector(3, 2, 1);
	t_tuple	t2 = vector(5, 6, 7);
	t_tuple	expected_result = vector(-2, -4, -6);
	t_tuple	result = tuple_substract(t1, t2);

	(void)state;
	assert_tuple_equal(result, expected_result);
}

int	test_tuple_substract(void)
{
	const struct CMUnitTest	substract_tests[] = {
		cmocka_unit_test(substract_point_test),
		cmocka_unit_test(substract_vec_from_point_test),
		cmocka_unit_test(substract_vector_test),
	};
	return (cmocka_run_group_tests(substract_tests, NULL, NULL));
}
