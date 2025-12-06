/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsed_to_group_tests.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:56:18 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/26 13:46:52 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "tests.h"
#include "obj_parser.h"
#include "groups.h"

static void	parsed_to_group_obj_parser_1_test(__unused void **state)
{
	t_obj_parsing	parsed = obj_parser("./test_assets/group.obj");
	t_shape			group = parsed_to_group(&parsed);

	assert_tuple_equal(group.child[0].child[0].tri_p1, parsed.vertices[0]);
	assert_tuple_equal(group.child[0].child[0].tri_p2, parsed.vertices[1]);
	assert_tuple_equal(group.child[0].child[0].tri_p3, parsed.vertices[2]);
	assert_tuple_equal(group.child[1].child[0].tri_p1, parsed.vertices[0]);
	assert_tuple_equal(group.child[1].child[0].tri_p2, parsed.vertices[2]);
	assert_tuple_equal(group.child[1].child[0].tri_p3, parsed.vertices[3]);
	assert_int_equal(parsed.ignored, 0);
	free_obj_parsing(&parsed);
	free_group(&group);
}

int	test_obj_parser_parsed_to_group(void)
{
	const struct CMUnitTest	obj_parser_parsed_to_group_tests[] = {
		cmocka_unit_test(parsed_to_group_obj_parser_1_test),
	};
	return (cmocka_run_group_tests(obj_parser_parsed_to_group_tests, NULL, NULL));
}
