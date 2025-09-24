/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:14:54 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/21 19:18:17 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "color.h"
#include "tests.h"

static void	color_add_test(void **state)
{
	(void)state;
	assert_color_equal(color_add(color(0.9, 0.6, 0.75), color(0.7, 0.1, 0.25)), color(1.6, 0.7, 1));
}

int	test_color_add(void)
{
	const struct CMUnitTest	color_add_tests[] = {
		cmocka_unit_test(color_add_test),
	};
	return (cmocka_run_group_tests(color_add_tests, NULL, NULL));
}
