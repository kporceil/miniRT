/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:04:39 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/01 19:16:08 by lcesbron         ###   ########lyon.fr   */
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

static void	bounding_box_add_1_test(__unused void **state)
{
	t_bounding_box	b1 = bounding_box(true, point(-5, -2, 0), point(7, 4, 4));
	t_bounding_box	b2 = bounding_box(true, point(8, -7, -2), point(14, 2, 8));

	bb_add(&b1, b2);
	assert_tuple_equal(b1.min, point(-5, -7, -2));
	assert_tuple_equal(b1.max, point(14, 4, 8));
}

int	test_bounding_box_add(void)
{
	const struct CMUnitTest	bounding_box_add_tests[] = {
		cmocka_unit_test(bounding_box_add_1_test),
	};
	return (cmocka_run_group_tests(bounding_box_add_tests, NULL, NULL));
}
