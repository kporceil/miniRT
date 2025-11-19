/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertices_tests.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:56:18 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/19 19:32:27 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "tests.h"
#include "obj_parser.h"

static void	vertices_obj_parser_1_test(__unused void **state)
{
	t_obj_parsing	parsed = obj_parser("./test_assets/vertices.obj");

	assert_tuple_equal(parsed->vertices[0], point(-1, 1, 0));
	assert_tuple_equal(parsed->vertices[1], point(-1, 0.5, 0));
	assert_tuple_equal(parsed->vertices[2], point(1, 0, 0));
	assert_tuple_equal(parsed->vertices[3], point(1, 1, 0));
	free_obj_parsing(&parsed);
}

int	test_obj_parser_vertices(void)
{
	const struct CMUnitTest	obj_parser_vertices_tests[] = {
		cmocka_unit_test(vertices_obj_parser_1_test),
	};
	return (cmocka_run_group_tests(obj_parser_vertices_tests, NULL, NULL));
}
