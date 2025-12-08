/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_index_tests.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:10:50 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/08 11:28:31 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "tests.h"
#include "groups.h"

#include <stdio.h>

void	group_delete_index_1_test(__unused void **state)
{
	t_shape	g = group(1, 3);

	group_add_shape(&g, sphere(2));
	group_add_shape(&g, sphere(3));
	group_add_shape(&g, sphere(4));
	group_delete_index(&g, 0);
	assert_int_equal(g.group_size, 3);
	assert_int_equal(g.nb_members, 2);
	assert_int_equal(g.child[0].id, 3);
	assert_int_equal(g.child[1].id, 4);
	free_group(&g);
}

void	group_delete_index_2_test(__unused void **state)
{
	t_shape	g = group(1, 3);

	group_add_shape(&g, sphere(2));
	group_add_shape(&g, sphere(3));
	group_add_shape(&g, sphere(4));
	group_delete_index(&g, 0);
	group_delete_index(&g, 0);
	group_delete_index(&g, 0);
	assert_int_equal(g.group_size, 3);
	assert_int_equal(g.nb_members, 0);
	free_group(&g);
}

void	group_delete_index_3_test(__unused void **state)
{
	t_shape	g = group(1, 3);

	group_add_shape(&g, sphere(2));
	group_add_shape(&g, sphere(3));
	group_add_shape(&g, sphere(4));
	group_delete_index(&g, 1);
	group_delete_index(&g, 1);
	assert_int_equal(g.group_size, 3);
	assert_int_equal(g.nb_members, 1);
	assert_int_equal(g.child[0].id, 2);
	free_group(&g);
}

void	group_delete_index_4_test(__unused void **state)
{
	t_shape	g = group(1, 3);
	int		ret;

	group_add_shape(&g, sphere(2));
	group_add_shape(&g, sphere(3));
	group_add_shape(&g, sphere(4));
	ret = group_delete_index(&g, 3);
	assert_int_equal(ret, 1);
	assert_int_equal(g.group_size, 3);
	assert_int_equal(g.nb_members, 3);
	assert_int_equal(g.child[0].id, 2);
	assert_int_equal(g.child[1].id, 3);
	assert_int_equal(g.child[2].id, 4);
	free_group(&g);
}

int	test_group_delete_index(void)
{
	const struct CMUnitTest delete_index_tests[] = {
		cmocka_unit_test(group_delete_index_1_test),
		cmocka_unit_test(group_delete_index_2_test),
		cmocka_unit_test(group_delete_index_3_test),
		cmocka_unit_test(group_delete_index_4_test),
	};
	return (cmocka_run_group_tests(delete_index_tests, NULL, NULL));
}
