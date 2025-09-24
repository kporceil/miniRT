/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalizing_tests.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:31:52 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/21 16:41:46 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "tuples.h"
#include "tests.h"

static void	normalizing_test1(void **state)
{
	(void)state;
	assert_tuple_equal(normalize(vector(4, 0, 0)), vector(1, 0, 0));
}

static void	normalizing_test2(void **state)
{
	(void)state;
	assert_tuple_equal(normalize(vector(1, 2, 3)), vector(0.26726, 0.53452, 0.80178));
}

static void	magnitude_normalized_vector_check_test(void **state)
{
	(void)state;
	assert_double_equal(magnitude(normalize(vector(1, 2, 3))), 1, 0.0001);
}

int	test_tuple_normalizing(void)
{
	const struct CMUnitTest	normalizing_tests[] = {
		cmocka_unit_test(normalizing_test1),
		cmocka_unit_test(normalizing_test2),
		cmocka_unit_test(magnitude_normalized_vector_check_test),
	};
	return (cmocka_run_group_tests(normalizing_tests, NULL, NULL));
}
