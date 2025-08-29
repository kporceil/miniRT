/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_tests.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:26:44 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/27 21:29:47 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "ray.h"
#include "tests.h"

static void	ray_position_test(void **state)
{
	t_ray	r = ray(point(2, 3, 4), vector(1, 0, 0));

	(void)state;
	assert_tuple_equal(ray_position(r, 0), point(2, 3, 4));
	assert_tuple_equal(ray_position(r, 1), point(3, 3, 4));
	assert_tuple_equal(ray_position(r, -1), point(1, 3, 4));
	assert_tuple_equal(ray_position(r, 2.5), point(4.5, 3, 4));
}

int	test_ray_position(void)
{
	const struct CMUnitTest	ray_position_tests[] = {
		cmocka_unit_test(ray_position_test),
	};
	return (cmocka_run_group_tests(ray_position_tests, NULL, NULL));
}
