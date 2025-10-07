/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute_reflect_tests.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 02:08:14 by kporceil          #+#    #+#             */
/*   Updated: 2025/09/27 02:13:58 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "tests.h"
#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

static void	precompute_reflect_test(__unused void **state)
{
	t_shape		obj = plane(0);
	t_ray		r = ray(point(0, 1, -1), vector(0, -(sqrt(2)/2), sqrt(2)/2));
	t_inter		i = (t_inter){&obj, sqrt(2)};
	t_precomp	comps = precompute(i, r);

	assert_tuple_equal(vector(0, sqrt(2)/2, sqrt(2)/2), comps.reflectv);
}

int	test_precompute_reflect(void)
{
	const struct CMUnitTest	precompute_reflect_tests[] = {
		cmocka_unit_test(precompute_reflect_test),
	};
	return (cmocka_run_group_tests(precompute_reflect_tests, NULL, NULL));
}
