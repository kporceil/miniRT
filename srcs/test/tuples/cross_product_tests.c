/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_product_tests.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:53:26 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/21 16:59:10 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "tests.h"
#include "tuples.h"

static void	cross_product_test1(void **state)
{
	(void)state;
	assert_tuple_equal(cross(vector(1, 2, 3), vector(2, 3, 4)), vector(-1, 2, -1));
	assert_tuple_equal(cross(vector(2, 3, 4), vector(1, 2, 3)), vector(1, -2, 1));
}

int	test_tuple_cross_product(void)
{
	const struct CMUnitTest	cross_product_tests[] = {
		cmocka_unit_test(cross_product_test1),
	};
	return (cmocka_run_group_tests(cross_product_tests, NULL, NULL));
}
