/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:40:28 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/01 18:08:10 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <math.h>
#include "tests.h"
#include "bounding_box.h"

static void	bounding_box_create_1_test(__unused void **state)
{
	t_bounding_box	b = bounding_box(false, (t_tuple){0}, (t_tuple){0});

	assert_tuple_equal(point(INFINITY, INFINITY, INFINITY), b.min);
	assert_tuple_equal(point(-INFINITY, -INFINITY, -INFINITY), b.max);
}

static void	bounding_box_create_2_test(__unused void **state)
{
	t_bounding_box	b = bounding_box(true, point(-1, -2, -3), point(3, 2, 1));

	assert_tuple_equal(point(-1, -2, -3), b.min);
	assert_tuple_equal(point(3, 2, 1), b.max);
}

int	test_bounding_box_create(void)
{
	const struct CMUnitTest	bounding_box_create_tests[] = {
		cmocka_unit_test(bounding_box_create_1_test),
		cmocka_unit_test(bounding_box_create_2_test),
	};
	return (cmocka_run_group_tests(bounding_box_create_tests, NULL, NULL));
}
