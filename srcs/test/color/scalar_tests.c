/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:27:47 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/21 19:37:07 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "color.h"
#include "tests.h"

static void	color_scalar_mult_test(void **state)
{
	(void)state;
	assert_color_equal(color_scalar_mult(color(0.2, 0.3, 0.4), 2), color(0.4, 0.6, 0.8));
}

int	test_color_scalar_mult(void)
{
	const struct CMUnitTest	color_scalar_mult_tests[] = {
		cmocka_unit_test(color_scalar_mult_test),
	};
	return (cmocka_run_group_tests(color_scalar_mult_tests, NULL, NULL));
}
