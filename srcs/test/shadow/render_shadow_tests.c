/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_shadow_tests.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:05:23 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/02 17:37:38 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include "light.h"
#include "world.h"
#include "tests.h"
#include "ray.h"

static void	shading_in_shadow_test(__unused void **state)
{
	t_world	w = { .ambient = color(0.1, 0.1, 0.1), .lights_count = 1, .objs_count = 2, .objs = malloc(sizeof(t_shape) * 2), .lights = malloc(sizeof(t_plight)), .buf_inter = malloc(sizeof(t_inter) * 4)};

	w.objs[0] = sphere(0);
	w.objs[1] = sphere(1);
	w.lights[0] = point_light(point(0, 0, -10), color(1, 1, 1));
	shape_set_matrix(w.objs + 1, matrix_translation(0, 0, 10));
	t_ray	r = ray(point(0, 0, 5), vector(0, 0, 1));
	t_inter	inters = {w.objs + 1, 4};
	t_precomp	comps = precompute(inters, r, NULL);
	t_color		c = shade_hit(w, comps, 0);
	free(w.buf_inter);
	free(w.lights);
	free(w.objs);
	assert_color_equal(color(0.1, 0.1, 0.1), c);
}

static void	over_point_test(__unused void **state)
{
	t_ray	r = ray(point(0, 0, -5), vector(0, 0, 1));
	t_shape	s = sphere(0);
	shape_set_matrix(&s, matrix_translation(0, 0, 1));
	t_inter		i = {&s, 5};
	t_precomp	comp = precompute(i, r, NULL);
	if (comp.over_point.z >= -0.0001/2)
		fail_msg("%lf is not inferior to %lf", comp.over_point.z, -0.0001/2);
	if (comp.point.z <= comp.over_point.z)
		fail_msg("%lf is not superior to %lf", comp.point.z, comp.over_point.z);
}

int	test_render_shadow(void)
{
	const struct CMUnitTest	render_shadow_test[] = {
		cmocka_unit_test(shading_in_shadow_test),
		cmocka_unit_test(over_point_test),
	};
	return (cmocka_run_group_tests(render_shadow_test, NULL, NULL));
}
