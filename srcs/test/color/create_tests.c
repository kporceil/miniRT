/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:03:25 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/21 19:05:04 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "color.h"
#include "tests.h"

static void	color_creation_test(void **state)
{
	(void)state;
	assert_color_equal(color(-0.5, 0.4, 1.7), ((t_color){-0.5, 0.4, 1.7}));
}

int	test_color_create(void)
{
	const struct CMUnitTest	color_create_test[] = {
		cmocka_unit_test(color_creation_test),
	};
	return (cmocka_run_group_tests(color_create_test, NULL, NULL));
}
