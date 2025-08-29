/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 00:17:03 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/22 00:49:58 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include "canvas.h"
#include "color.h"
#include "tests.h"

static void	canva_creation_test(void **state)
{
	t_canva c = canva(10, 20);

	(void)state;
	assert_int_equal(c.width, 10);
	assert_int_equal(c.height, 20);
	if (c.canva == NULL) { fail_msg("Malloc error"); }
	for (size_t i = 0; i < 200; ++i)
	{
		assert_color_equal(c.canva[i], (t_color){0, 0, 0});
	}
	free(c.canva);
}

int	test_canva_create(void)
{
	const struct CMUnitTest	canva_create_tests[] = {
		cmocka_unit_test(canva_creation_test),
	};
	return (cmocka_run_group_tests(canva_create_tests, NULL, NULL));
}
