/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:35:06 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/21 19:36:35 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "color.h"
#include "tests.h"

static void	color_mult_test(void **state)
{
	(void)state;
	assert_color_equal(color_mult(color(1, 0.2, 0.4), color(0.9, 1, 0.1)), color(0.9, 0.2, 0.04));
}

int	test_color_mult(void)
{
	const struct CMUnitTest	color_mult_tests[] = {
		cmocka_unit_test(color_mult_test),
	};
	return (cmocka_run_group_tests(color_mult_tests, NULL, NULL));
}
