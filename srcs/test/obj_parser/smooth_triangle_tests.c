/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_triangle_tests.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:56:18 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/28 20:29:42 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "tests.h"
#include "obj_parser.h"

static void	smooth_triangle_obj_parser_1_test(__unused void **state)
{
	t_obj_parsing	parsed = obj_parser("./test_assets/smooth_triangle.obj");

	assert_tuple_equal(parsed.normals[0], vector(0, 0, 1));
	assert_tuple_equal(parsed.normals[1], vector(0.707, 0, -0.707));
	assert_tuple_equal(parsed.normals[2], vector(1, 2, 3));
	assert_int_equal(parsed.ignored, 0);
	free_obj_parsing(&parsed);
}

int	test_obj_parser_smooth_triangle(void)
{
	const struct CMUnitTest	obj_parser_smooth_triangle_tests[] = {
		cmocka_unit_test(smooth_triangle_obj_parser_1_test),
	};
	return (cmocka_run_group_tests(obj_parser_smooth_triangle_tests, NULL, NULL));
}
