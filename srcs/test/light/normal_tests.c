/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:05:38 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/29 12:41:07 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <math.h>
#include "matrix.h"
#include "spheres.h"
#include "tuples.h"
#include "tests.h"
#include "light.h"

static void	x_axis_normal_test(void **state)
{
	t_sphere	s = sphere(0);
	t_tuple		n = normal_at(s, point(1, 0, 0));

	(void)state;
	assert_tuple_equal(n, vector(1, 0, 0));
}

static void	y_axis_normal_test(void **state)
{
	t_sphere	s = sphere(0);
	t_tuple		n = normal_at(s, point(0, 1, 0));

	(void)state;
	assert_tuple_equal(n, vector(0, 1, 0));
}

static void	z_axis_normal_test(void **state)
{
	t_sphere	s = sphere(0);
	t_tuple		n = normal_at(s, point(0, 0, 1));

	(void)state;
	assert_tuple_equal(n, vector(0, 0, 1));
}

static void	non_axial_normal_test(void **state)
{
	t_sphere	s = sphere(0);
	t_tuple		n = normal_at(s, point(sqrt(3.0)/3.0, sqrt(3.0)/3.0, sqrt(3.0)/3.0));

	(void)state;
	assert_tuple_equal(n, vector(sqrt(3.0)/3.0, sqrt(3.0)/3.0, sqrt(3.0)/3.0));
}

static void	normalized_normal_test(void **state)
{
	t_sphere	s = sphere(0);
	t_tuple		n = normal_at(s, point(sqrt(3.0)/3.0, sqrt(3.0)/3.0, sqrt(3.0)/3.0));

	(void)state;
	assert_tuple_equal(n, normalize(vector(sqrt(3.0)/3.0, sqrt(3.0)/3.0, sqrt(3.0)/3.0)));
}

static void	translated_sphere_normal_test(void **state)
{
	t_sphere	s = sphere(0);
	s.transformation = matrix_translation(0, 1, 0);
	t_tuple		n = normal_at(s, point(0, 1.70711, -0.70711));

	(void)state;
	assert_tuple_equal(n, vector(0, 0.70711, -0.70711));
}

static void	scaled_sphere_normal_test(void **state)
{
	t_sphere	s = sphere(0);
	s.transformation = matrix_mult(matrix_scaling(1, 0.5, 1), matrix_z_rotation(M_PI / 5));
	t_tuple		n = normal_at(s, point(0, sqrt(2.0/2.0), -sqrt(2.0/2.0)));

	(void)state;
	assert_tuple_equal(n, vector(0, 0.97014, -0.24254));
}

int	test_normal_finding(void)
{
	const struct CMUnitTest	finding_normal_tests[] = {
		cmocka_unit_test(x_axis_normal_test),
		cmocka_unit_test(y_axis_normal_test),
		cmocka_unit_test(z_axis_normal_test),
		cmocka_unit_test(non_axial_normal_test),
		cmocka_unit_test(normalized_normal_test),
		cmocka_unit_test(scaled_sphere_normal_test),
		cmocka_unit_test(translated_sphere_normal_test),
	};
	return (cmocka_run_group_tests(finding_normal_tests, NULL, NULL));
}
