/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:11:03 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/08 15:27:42 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "light.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

static void	normal_test(__unused void **state)
{
	t_shape	c = cube(0);
	t_tuple	p[] = { point(1, 0.5, -0.8),
					point(-1, -0.2, 0.9),
					point(-0.4, 1, -0.1),
					point(0.3, -1, -0.7),
					point(-0.6, 0.3, 1),
					point(0.4, 0.4, -1),
					point(1, 1, 1),
					point(-1, -1, -1) };
	t_tuple	n[] = { vector(1, 0, 0),
					vector(-1, 0, 0),
					vector(0, 1, 0),
					vector(0, -1, 0),
					vector(0, 0, 1),
					vector(0, 0, -1),
					vector(1, 0, 0),
					vector(-1, 0, 0) };
	for (size_t i = 0; i < 8; ++i) {
		assert_tuple_equal(n[i], normal_at(c, p[i]));
	}
}

int	test_cube_normal(void)
{
	const struct CMUnitTest	normal_tests[] = {
		cmocka_unit_test(normal_test),
	};
	return (cmocka_run_group_tests(normal_tests, NULL, NULL));
}
