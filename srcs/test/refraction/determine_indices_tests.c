/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_indices_tests.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:57:04 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/02 17:39:09 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "ray.h"
#include "material.h"
#include "tests.h"
#include "shape.h"
#include <malloc.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

static t_shape	glass_sphere(size_t id)
{
	t_shape	s = sphere(id);

	s.material.refractive_index = 1.5;
	s.material.transparency = 1;
	return (s);
}

static void	determine_indices_test(__unused void **state)
{
	t_shape			a = glass_sphere(0);
	t_shape			b = glass_sphere(1);
	t_shape			c = glass_sphere(2);
	t_ray			r = ray(point(0, 0, -4), vector(0, 0, 1));
	t_intersections	xs = (t_intersections){malloc(sizeof(t_inter) * 6), 6};
	xs.inters[0].s = &a;
	xs.inters[0].point = 2;
	xs.inters[1].s = &b;
	xs.inters[1].point = 2.75;
	xs.inters[2].s = &c;
	xs.inters[2].point = 3.25;
	xs.inters[3].s = &b;
	xs.inters[3].point = 4.75;
	xs.inters[4].s = &c;
	xs.inters[4].point = 5.25;
	xs.inters[5].s = &a;
	xs.inters[5].point = 6;
	double			n1[6] = {1.0, 1.5, 2.0, 2.5, 2.5, 1.5};
	double			n2[6] = {1.5, 2.0, 2.5, 2.5, 1.5, 1.0};
	shape_set_matrix(&a, matrix_scaling(2, 2, 2));
	a.material.refractive_index = 1.5;
	shape_set_matrix(&b, matrix_translation(0, 0, -0.25));
	b.material.refractive_index = 2.0;
	shape_set_matrix(&c, matrix_translation(0, 0, 0.25));
	c.material.refractive_index = 2.5;
	
	for (size_t i = 0; i < xs.size; ++i) {
		t_precomp		comps = precompute(xs.inters[i], r, &xs); 
		assert_double_equal(n1[i], comps.n1, 0.0001);
		assert_double_equal(n2[i], comps.n2, 0.0001);
	}
	free(xs.inters);
}

int	test_determine_indices(void)
{
	const struct CMUnitTest	determine_indices_tests[] = {
		cmocka_unit_test(determine_indices_test),
	};
	return (cmocka_run_group_tests(determine_indices_tests, NULL, NULL));
}
