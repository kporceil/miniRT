/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_children_tests.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:15:05 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/03 15:29:04 by lcesbron         ###   ########lyon.fr   */
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
#include "shape.h"

static void	bounding_box_partition_children_1_test(__unused void **state)
{
	t_shape	g = group(1, 3);

	g.child[0] = sphere(2);
	g.child[1] = sphere(3);
	g.child[2] = sphere(4);
	shape_set_matrix(g.child, matrix_translation(-2, 0, 0));
	shape_set_matrix(g.child + 1, matrix_translation(2, 0, 0));
	partition_children(&g);
	assert_int_equal(g.child[0].type, SPHERE);
	assert_int_equal(g.child[1].type, GROUP);
	assert_int_equal(g.child[2].type, GROUP);
	assert_int_equal(g.child[1].child->id, 2);
	assert_int_equal(g.child[2].child->id, 3);
}

int	test_bounding_box_partition_children(void)
{
	const struct CMUnitTest	bounding_box_partition_children_tests[] = {
		cmocka_unit_test(bounding_box_partition_children_1_test),
	};
	return (cmocka_run_group_tests(bounding_box_partition_children_tests, NULL, NULL));
}
