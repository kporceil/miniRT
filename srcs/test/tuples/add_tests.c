/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:42:35 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/21 15:56:31 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "tests.h"
#include "tuples.h"

void	add_tuple_test(void **state)
{
	t_tuple	t1 = point(3, -2, 5);
	t_tuple	t2 = vector(-2, 3, 1);
	t_tuple	expected_result = point(1, 1, 6);
	t_tuple	result = tuple_add(t1, t2);

	(void)state;
	assert_tuple_equal(result, expected_result);
}

int	test_tuple_add(void)
{
	const struct CMUnitTest	add_tests[] = {
		cmocka_unit_test(add_tuple_test),
	};
	return (cmocka_run_group_tests(add_tests, NULL, NULL));
}
