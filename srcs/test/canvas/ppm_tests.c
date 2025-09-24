/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 11:47:37 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/22 14:08:21 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "canvas.h"
#include "color.h"

static void	ppm_header_test(void **state)
{
	t_canva	c = canva(5, 3);
	char	*ppm;

	if (!c.canva)
	{
		fail_msg("Malloc error");
		return ;
	}
	ppm = canva_to_ppm(c);
	if (!ppm)
	{
		free(c.canva);
		fail_msg("Malloc error");
		return ;
	}
	(void)state;
	assert_memory_equal(ppm, "P3\n5 3\n255\n", 11);
	free(ppm);
	free(c.canva);
}

static void	ppm_pixel_test(void **state)
{
	t_canva	c = canva(5,3);
	char	*ppm;
	
	(void)state;
	if (!c.canva)
	{
		fail_msg("Malloc error");
		return ;
	}
	write_pixel(&c, 0, 0, (t_color){1.5, 0, 0});
	write_pixel(&c, 2, 1, (t_color){0, 0.5, 0});
	write_pixel(&c, 4, 2, (t_color){-0.5, 0, 1});
	ppm = canva_to_ppm(c);
	if (!ppm)
	{
		free(c.canva);
		fail_msg("Malloc error");
		return ;
	}
	assert_memory_equal(ppm, "P3\n5 3\n255\n255 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 128 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 0 0 0 0 0 0 0 255\n", 107);
	free(ppm);
	free(c.canva);
}

static void	ppm_break_line_test(void **state)
{
	t_canva	c = canva(10, 2);
	char	*ppm;

	(void)state;
	if (!c.canva)
	{
		fail_msg("Malloc error");
		return ;
	}
	for (size_t i = 0; i < c.height; ++i)
	{
		for (size_t j = 0; j < c.width; ++j)
		{
			write_pixel(&c, j, i, (t_color){1, 0.8, 0.6});
		}
	}
	ppm = canva_to_ppm(c);
	if (!ppm)
	{
		free(c.canva);
		fail_msg("Malloc error");
		return ;
	}
	assert_memory_equal(ppm, "P3\n10 2\n255\n255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n153 255 204 153 255 204 153 255 204 153 255 204 153\n255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n153 255 204 153 255 204 153 255 204 153 255 204 153\n", 252);
	free(ppm);
	free(c.canva);
}

static void	ppm_endl_test(void **state)
{
	t_canva	c = canva(5, 3);
	char	*ppm;

	(void)state;
	if (!c.canva)
	{
		fail_msg("Malloc error");
		return ;
	}
	ppm = canva_to_ppm(c);
	if (!ppm)
	{
		free(c.canva);
		fail_msg("Malloc error");
		return ;
	}
	assert_int_equal(ppm[ft_strlen(ppm) - 1], '\n');
	free(ppm);
	free(c.canva);
}

int	test_ppm_creation(void)
{
	const struct CMUnitTest	ppm_creation_tests[] = {
		cmocka_unit_test(ppm_header_test),
		cmocka_unit_test(ppm_pixel_test),
		cmocka_unit_test(ppm_break_line_test),
		cmocka_unit_test(ppm_endl_test),
	};
	return (cmocka_run_group_tests(ppm_creation_tests, NULL, NULL));
}
