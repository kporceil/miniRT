/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_shadow_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:55:07 by kporceil          #+#    #+#             */
/*   Updated: 2025/09/03 18:16:53 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "light.h"
#include "tests.h"

static void	lighting_in_shadow_test(__unused void **state)
{
	t_lighting lighting_data = {.ambient = color(0.1, 0.1, 0.1), .m = material(), .p = point(0, 0, 0), .eyev = vector(0, 0, -1), .normalv = vector(0, 0, -1), .light = point_light(point(0, 0, -10), color(1, 1, 1)), .in_shadow = true};
	t_color	result = lighting(lighting_data);

	assert_color_equal(color(0.1, 0.1, 0.1), result);
}

int	test_in_shadow(void)
{
	const struct CMUnitTest	in_shadow_tests[] = {
		cmocka_unit_test(lighting_in_shadow_test),
	};
	return (cmocka_run_group_tests(in_shadow_tests, NULL, NULL));
}
