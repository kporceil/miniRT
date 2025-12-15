/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_index_tests.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:53:51 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/08 11:06:37 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "tests.h"
#include "vectors.h"

#include <stdio.h>

void	vector_delete_index_1_test(__unused void **state)
{
	int				*tab = vec_create(sizeof(int), 5);
	t_vector_head	*header = vec_get_header(tab);

	vec_add((void **)&tab, &(int){5});
	vec_add((void **)&tab, &(int){-18});
	vec_add((void **)&tab, &(int){8});
	vec_delete_index(tab, 1);
	assert_int_equal(header->vector_size, sizeof(int) * 5);
	assert_int_equal(header->nb_elems, 2);
	assert_int_equal(header->max_elems, 5);
	assert_int_equal(tab[0], 5);
	assert_int_equal(tab[1], 8);
	vec_free(tab);
}

void	vector_delete_index_2_test(__unused void **state)
{
	int				*tab = vec_create(sizeof(int), 5);
	t_vector_head	*header = vec_get_header(tab);

	vec_add((void **)&tab, &(int){5});
	vec_add((void **)&tab, &(int){-18});
	vec_add((void **)&tab, &(int){8});
	vec_delete_index(tab, 0);
	vec_delete_index(tab, 0);
	vec_delete_index(tab, 0);
	assert_int_equal(header->vector_size, sizeof(int) * 5);
	assert_int_equal(header->nb_elems, 0);
	assert_int_equal(header->max_elems, 5);
	vec_free(tab);
}

void	vector_delete_index_3_test(__unused void **state)
{
	int				*tab = vec_create(sizeof(int), 5);
	t_vector_head	*header = vec_get_header(tab);

	vec_add((void **)&tab, &(int){5});
	vec_add((void **)&tab, &(int){-18});
	vec_add((void **)&tab, &(int){8});
	vec_delete_index(tab, 0);
	assert_int_equal(header->vector_size, sizeof(int) * 5);
	assert_int_equal(header->nb_elems, 2);
	assert_int_equal(header->max_elems, 5);
	assert_int_equal(tab[0], -18);
	assert_int_equal(tab[1], 8);
	vec_free(tab);
}

void	vector_delete_index_4_test(__unused void **state)
{
	int				*tab = vec_create(sizeof(int), 5);
	t_vector_head	*header = vec_get_header(tab);

	vec_add((void **)&tab, &(int){5});
	vec_add((void **)&tab, &(int){-18});
	vec_add((void **)&tab, &(int){8});
	vec_delete_index(tab, 3);
	assert_int_equal(header->vector_size, sizeof(int) * 5);
	assert_int_equal(header->nb_elems, 3);
	assert_int_equal(header->max_elems, 5);
	assert_int_equal(tab[0], 5);
	assert_int_equal(tab[1], -18);
	assert_int_equal(tab[2], 8);
	vec_free(tab);
}

int	test_vector_delete_index(void)
{
	const struct CMUnitTest delete_index_tests[] = {
		cmocka_unit_test(vector_delete_index_1_test),
		cmocka_unit_test(vector_delete_index_2_test),
		cmocka_unit_test(vector_delete_index_3_test),
		cmocka_unit_test(vector_delete_index_4_test),
	};
	return (cmocka_run_group_tests(delete_index_tests, NULL, NULL));
}
