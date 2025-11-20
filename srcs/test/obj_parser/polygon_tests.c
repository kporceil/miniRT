/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polygon_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:56:18 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/20 18:03:30 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "tests.h"
#include "obj_parser.h"

static void	polygon_obj_parser_1_test(__unused void **state)
{
	t_obj_parsing	parsed = obj_parser("./test_assets/polygons.obj");

	assert_tuple_equal(parsed.groups->child[0].tri_p1, parsed.vertices[0]);
	assert_tuple_equal(parsed.groups->child[0].tri_p2, parsed.vertices[1]);
	assert_tuple_equal(parsed.groups->child[0].tri_p3, parsed.vertices[2]);
	assert_tuple_equal(parsed.groups->child[1].tri_p1, parsed.vertices[0]);
	assert_tuple_equal(parsed.groups->child[1].tri_p2, parsed.vertices[2]);
	assert_tuple_equal(parsed.groups->child[1].tri_p3, parsed.vertices[3]);
	assert_tuple_equal(parsed.groups->child[2].tri_p1, parsed.vertices[0]);
	assert_tuple_equal(parsed.groups->child[2].tri_p2, parsed.vertices[3]);
	assert_tuple_equal(parsed.groups->child[2].tri_p3, parsed.vertices[4]);
	assert_int_equal(parsed.ignored, 0);
	free_obj_parsing(&parsed);
}

int	test_obj_parser_polygon(void)
{
	const struct CMUnitTest	obj_parser_polygon_tests[] = {
		cmocka_unit_test(polygon_obj_parser_1_test),
	};
	return (cmocka_run_group_tests(obj_parser_polygon_tests, NULL, NULL));
}
