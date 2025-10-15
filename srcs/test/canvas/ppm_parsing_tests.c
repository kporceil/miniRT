/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm_parsing_tests.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:32:06 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/13 19:06:32 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "tests.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

static void	magic_number_test(__unused void **state)
{
	t_canva	c = ppm_to_canva("./test_assets/wrong_magic.ppm");

	assert_int_equal(0, c.canva);
	free(c.canva);
}

static void	size_test(__unused void **state)
{
	t_canva c = ppm_to_canva("./test_assets/size_test.ppm");

	assert_int_equal(10, c.width);
	assert_int_equal(2, c.height);
	free(c.canva);
}

static void	parse_color_test(__unused void **state)
{
	t_canva c = ppm_to_canva("./test_assets/color_test.ppm");
	t_color expected[] = {
		color(1, 0.498, 0),
		color(0, 0.498, 1),
    	color(0.498, 1, 0),
    	color(1, 1, 1),
    	color(0, 0, 0),
    	color(1, 0, 0),
    	color(0, 1, 0),
    	color(0, 0, 1),
    	color(1, 1, 0),
    	color(0, 1, 1),
    	color(1, 0, 1),
    	color(0.498, 0.498, 0.498),
	};
	for (size_t y = 0; y < 3; ++y) {
		for (size_t x = 0; x < 4; ++x) {
			assert_color_equal(expected[y * 3 + x], c.canva[y * 3 + x]);
		}
	}
	free(c.canva);
}

static void	comment_test(__unused void **state)
{
	t_canva c = ppm_to_canva("./test_assets/comment_test.ppm");
	assert_color_equal(color(1, 1, 1), c.canva[0]);
	assert_color_equal(color(1, 0, 1), c.canva[1]);
	free(c.canva);
}

static void	line_splitting_test(__unused void **state)
{
	t_canva c = ppm_to_canva("./test_assets/line_splitting_test.ppm");
	assert_color_equal(color(0.2, 0.6, 0.8), c.canva[0]);
	free(c.canva);
}

static void	scaling_test(__unused void **state)
{
	t_canva	c = ppm_to_canva("./test_assets/scaling_test.ppm");
	assert_color_equal(color(0.75, 0.5, 0.25), c.canva[2]);
	free(c.canva);
}

int	test_ppm_parsing(void)
{
	const struct CMUnitTest	ppm_parsing_tests[] = {
		cmocka_unit_test(magic_number_test),
		cmocka_unit_test(size_test),
		cmocka_unit_test(parse_color_test),
		cmocka_unit_test(comment_test),
		cmocka_unit_test(line_splitting_test),
		cmocka_unit_test(scaling_test),
	};
	return (cmocka_run_group_tests(ppm_parsing_tests, NULL, NULL));
}
