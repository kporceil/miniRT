/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pixel_tests.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 01:08:50 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/22 01:26:08 by kporceil         ###   ########lyon.fr   */
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

static void	write_pixel_test(void **state)
{
	t_canva	c = canva(10, 20);
	t_color	red = color(1, 0, 0);

	(void)state;
	write_pixel(&c, 2, 3, red);
	assert_color_equal(c.canva[2 + 3 * 10], red);
	free(c.canva);
}

int	test_write_pixel(void)
{
	const struct CMUnitTest	write_pixel_tests[] = {
		cmocka_unit_test(write_pixel_test),
	};
	return (cmocka_run_group_tests(write_pixel_tests, NULL, NULL));
}
