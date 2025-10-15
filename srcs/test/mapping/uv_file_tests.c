/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_file_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:24:32 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/15 19:40:29 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "patterns.h"
#include "canvas.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

static void	uv_file_test(__unused void **state)
{
	t_canva	c = ppm_to_canva("./test_assets/uv_file.ppm");
	t_uvpat	pat = uv_image(c);
	t_color		e_c[] = {
		color(0.9, 0.9, 0.9),
		color(0.2, 0.2, 0.2),
		color(0.1, 0.1, 0.1),
		color(0.9, 0.9, 0.9),
	};
	double		u[] = {0, 0.3, 0.6, 1};
	double		v[] = {0, 0, 0.3, 1};

	for (size_t i = 0; i < 4; ++i) {
		assert_color_equal(e_c[i], uv_pattern_at(pat, u[i], v[i]));
	}
	free(c.canva);
}

int	test_uv_file(void)
{
	const struct CMUnitTest	uv_file_tests[] = {
		cmocka_unit_test(uv_file_test),
	};
	return (cmocka_run_group_tests(uv_file_tests, NULL, NULL));
}
