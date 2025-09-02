/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:18:12 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/27 21:24:34 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "ray.h"
#include "tests.h"

static void	ray_create_test(void **state)
{
	t_ray	r = ray(point(1, 2, 3), vector(4, 5, 6));

	(void)state;
	assert_tuple_equal(r.origin, point(1, 2, 3));
	assert_tuple_equal(r.dir, vector(4, 5, 6));
}

int	test_ray_create(void)
{
	const struct CMUnitTest	ray_create_tests[] = {
		cmocka_unit_test(ray_create_test),
	};
	return (cmocka_run_group_tests(ray_create_tests, NULL, NULL));
}
