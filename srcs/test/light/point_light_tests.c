/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_light_tests.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:18:52 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/29 13:22:37 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "tuples.h"
#include "color.h"
#include "tests.h"
#include "light.h"

static void	point_light_test(void **state)
{
	t_plight	light = point_light(point(0, 0, 0), color(1, 1, 1));
	
	(void)state;
	assert_tuple_equal(light.pos, point(0, 0, 0));
	assert_color_equal(light.intensity, color(1, 1, 1));
}

int	test_point_light(void)
{
	const struct CMUnitTest	point_light_tests[] = {
		cmocka_unit_test(point_light_test),
	};
	return (cmocka_run_group_tests(point_light_tests, NULL, NULL));
}
