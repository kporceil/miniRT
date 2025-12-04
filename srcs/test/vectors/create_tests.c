/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:42:35 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/19 14:44:04 by lcesbron         ###   ########lyon.fr   */
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

void	vector_create_1_test(__unused void **state)
{
	int				*tab = vec_create(sizeof(int), 5);
	t_vector_head	*header = vec_get_header(tab);

	assert_int_equal(header->vector_size, sizeof(int) * 5);
	assert_int_equal(header->nb_elems, 0);
	assert_int_equal(header->max_elems, 5);
	assert_int_equal(header->el_size, sizeof(int));
	vec_free(tab);
}

int	test_vector_create(void)
{
	const struct CMUnitTest create_tests[] = {
		cmocka_unit_test(vector_create_1_test),
	};
	return (cmocka_run_group_tests(create_tests, NULL, NULL));
}
