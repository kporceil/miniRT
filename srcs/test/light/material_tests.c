/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_tests.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:26:33 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/29 13:29:13 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "color.h"
#include "material.h"
#include "tests.h"

static void	material_test(void **state)
{
	t_material	m = material();

	(void)state;
	assert_color_equal(m.color, color(1, 1, 1));
	assert_double_equal(m.diffuse, 0.9, 0.0001);
	assert_double_equal(m.specular, 0.9, 0.0001);
	assert_double_equal(m.shininess, 200, 0.0001);
}

int	test_material(void)
{
	const struct CMUnitTest	material_tests[] = {
		cmocka_unit_test(material_test),
	};
	return (cmocka_run_group_tests(material_tests, NULL, NULL));
}
