/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ignoring_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:56:18 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/18 19:20:14 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "tests.h"
#include "obj_parser.h"

static void	ignoring_obj_parser_1_test(void **state)
{
	t_obj_parsing	parsed = obj_parser("./test_assets/gibberish.obj")
}

int	test_obj_parser_ignoring(void)
{
	const struct CMUnitTest	matrix_mult_tests[] = {
		cmocka_unit_test(matrix4x4_mult_test),
	};
	return (cmocka_run_group_tests(matrix_mult_tests, NULL, NULL));
}
