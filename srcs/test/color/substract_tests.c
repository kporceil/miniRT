/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substract_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:24:56 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/21 19:29:02 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "color.h"
#include "tests.h"

static void	color_substract_test(void **state)
{
	(void)state;
	assert_color_equal(color_substract(color(0.9, 0.6, 0.75), color(0.7, 0.1, 0.25)), color(0.2, 0.5, 0.5));
}

int	test_color_substract(void)
{
	const struct CMUnitTest	color_substract_tests[] = {
		cmocka_unit_test(color_substract_test),
	};
	return (cmocka_run_group_tests(color_substract_tests, NULL, NULL));
}
