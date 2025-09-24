/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_tests.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:06:12 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/29 13:09:44 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <math.h>
#include "tuples.h"
#include "light.h"
#include "tests.h"

static void	reflection_test(void **state)
{
	(void)state;
	assert_tuple_equal(reflect(vector(1, -1, 0), vector(0, 1, 0)), vector(1, 1, 0));
}

static void	slanted_surface_reflection_test(void **state)
{
	(void)state;
	assert_tuple_equal(reflect(vector(0, -1, 0), vector(sqrt(2)/2, sqrt(2)/2, 0)), vector(1, 0, 0));
}

int	test_reflection(void)
{
	const struct CMUnitTest	reflection_tests[] = {
		cmocka_unit_test(reflection_test),
		cmocka_unit_test(slanted_surface_reflection_test),
	};
	return (cmocka_run_group_tests(reflection_tests, NULL, NULL));
}
