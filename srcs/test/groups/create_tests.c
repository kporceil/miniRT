/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:46:17 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/16 13:47:30 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include <float.h>
#include "shape.h"
#include "tests.h"
#include "ray.h"
#include "tuples.h"

#ifndef EPSILON
# define EPSILON 0.0001
#endif

static void	create_group_1_test(__unused void **state)
{
	t_shape	g = group(1, 0);

	assert_matrix_equal(g.transformation, identity_matrix(3));
	assert_ptr_equal(g.child, NULL);
}

int	test_group_create(void)
{
	const struct CMUnitTest	group_create_tests[] = {
		cmocka_unit_test(create_group_1_test),
	};
	return (cmocka_run_group_tests(group_create_tests, NULL, NULL));
}
