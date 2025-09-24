/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negate_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 19:33:47 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/21 15:56:52 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "tuples.h"
#include "tests.h"

void	negate_tuple_test(void **state)
{
	t_tuple	t = {1, -2, 3 , -4};
	t_tuple	expected_result = {-1, 2, -3, 4};
	t_tuple result = tuple_negate(t);

	(void)state;
	assert_tuple_equal(result, expected_result);
}

int	test_tuple_negate(void)
{
	const struct CMUnitTest	negate_tests[] = {
		cmocka_unit_test(negate_tuple_test),
	};
	return (cmocka_run_group_tests(negate_tests, NULL, NULL));
}
