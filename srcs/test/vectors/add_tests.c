/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:42:35 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/19 15:15:06 by lcesbron         ###   ########lyon.fr   */
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

void	vector_add_1_test(__unused void **state)
{
	int				*tab = vec_create(sizeof(int), 5);
	t_vector_head	*header = vec_get_header(tab);

	vec_add((void **)&tab, &(int){5});
	vec_add((void **)&tab, &(int){-18});
	vec_add((void **)&tab, &(int){8});
	assert_int_equal(header->vector_size, sizeof(int) * 5);
	assert_int_equal(header->nb_elems, 3);
	assert_int_equal(header->max_elems, 5);
	assert_int_equal(tab[0], 5);
	assert_int_equal(tab[1], -18);
	assert_int_equal(tab[2], 8);
	vec_free(tab);
}

void	vector_add_2_test(__unused void **state)
{
	int				*tab = vec_create(sizeof(int), 2);
	t_vector_head	*header;

	vec_add((void **)&tab, &(int){1});
	vec_add((void **)&tab, &(int){2});
	vec_add((void **)&tab, &(int){3});
	header = vec_get_header(tab);
	assert_int_equal(header->vector_size, sizeof(int) * 4);
	assert_int_equal(header->nb_elems, 3);
	assert_int_equal(header->max_elems, 4);
	assert_int_equal(tab[0], 1);
	assert_int_equal(tab[1], 2);
	assert_int_equal(tab[2], 3);
	vec_free(tab);
}

int	test_vector_add(void)
{
	const struct CMUnitTest add_tests[] = {
		cmocka_unit_test(vector_add_1_test),
		cmocka_unit_test(vector_add_2_test),
	};
	return (cmocka_run_group_tests(add_tests, NULL, NULL));
}
