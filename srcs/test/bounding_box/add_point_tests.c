/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_point_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:40:28 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/01 18:04:19 by lcesbron         ###   ########lyon.fr   */
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

static void	bounding_box_add_point_1_test(__unused void **state)
{
	t_bounding_box	b = bounding_box(false, (t_tuple){0}, (t_tuple){0});

	bb_add_point(&b, point(-5, 0, -3));
	bb_add_point(&b, point(7, 2, 0));
	assert_tuple_equal(b.min, point(-5, 0, -3));
	assert_tuple_equal(b.max, point(7, 2, 0));
}

int	test_bounding_box_add_point(void)
{
	const struct CMUnitTest	bounding_box_add_point_tests[] = {
		cmocka_unit_test(bounding_box_add_point_1_test),
	};
	return (cmocka_run_group_tests(bounding_box_add_point_tests, NULL, NULL));
}
