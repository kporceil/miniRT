/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_product_tests.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:45:26 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/21 16:50:28 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "tuples.h"

static void	dot_product_test(void **state)
{
	(void)state;
	assert_double_equal(dot(vector(1, 2, 3), vector(2, 3, 4)), 20, 0.0001);
}

int	test_tuple_dot_product(void)
{
	const struct CMUnitTest	dot_product_tests[] = {
		cmocka_unit_test(dot_product_test),
	};
	return (cmocka_run_group_tests(dot_product_tests, NULL, NULL));
}
