/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ignoring_tests.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:56:18 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/19 19:20:09 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "tests.h"
#include "obj_parser.h"

static void	ignoring_obj_parser_1_test(__unused void **state)
{
	t_obj_parsing	parsed = obj_parser("./test_assets/gibberish.obj");

	assert_int_equal(parsed.ignored, 5);
	free_obj_parsing(&parsed);
}

int	test_obj_parser_ignoring(void)
{
	const struct CMUnitTest	obj_parser_ignoring_tests[] = {
		cmocka_unit_test(ignoring_obj_parser_1_test),
	};
	return (cmocka_run_group_tests(obj_parser_ignoring_tests, NULL, NULL));
}
