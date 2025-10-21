/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   schlick_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 20:38:55 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/07 21:16:36 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "tests.h"
#include "refract.h"
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

static int	setup(void **state)
{
	t_world	*world = malloc(sizeof(t_world));
	if (!world)
		return (-1);

	world->lights_count = 1;
	world->objs_count = 4;
	world->objs = malloc(sizeof(t_shape) * world->objs_count);
	world->lights = malloc(sizeof(t_plight) * world->lights_count);
	if (!world->objs || !world->lights)
	{
		free(world->objs);
		free(world->lights);
		free(world);
		return (-1);
	}
	world->buf_inter = malloc(sizeof(t_inter) * 8);
	if (!world->buf_inter)
	{
		free(world->objs);
		free(world->lights);
		free(world);
		return (-1);
	}
	world->objs[0] = sphere(0);
	world->objs[1] = sphere(1);
	world->objs[0].material.diffuse = 0.7;
	world->objs[0].material.specular = 0.2;
	world->objs[0].material.color = color(0.8, 1, 0.6);
	shape_set_matrix(world->objs + 1, matrix_scaling(0.5, 0.5, 0.5));
	world->objs[2] = plane(2);
	world->objs[2].material.reflective = 0.5;
	world->objs[2].material.transparency = 0.5;
	world->objs[2].material.refractive_index = 1.5;
	shape_set_matrix(world->objs + 2, matrix_translation(0, -1, 0));
	world->objs[3] = sphere(3);
	world->objs[3].material.color = color(1, 0, 0);
	world->objs[3].material.ambient = 0.5;
	shape_set_matrix(world->objs + 3, matrix_translation(0, -3.5, -0.5));
	world->lights[0].intensity = color(1, 1, 1);
	world->lights[0].pos = point(-10, 10, -10);
	*state = world;
	return (0);
}

static int	teardown(void **state)
{
	t_world	*world = *state;

	free(world->buf_inter);
	free(world->lights);
	free(world->objs);
	free(world);
	return (0);
}

static t_shape	glass_sphere(size_t id)
{
	t_shape	s = sphere(id);

	s.material.refractive_index = 1.5;
	s.material.transparency = 1;
	return (s);
}

static void	total_internal_reflection_test(__unused void **state)
{
	t_shape	s = glass_sphere(0);
	t_ray	r = ray(point(0, 0, sqrt(2)/2), vector(0, 1, 0));
	t_intersections	xs = (t_intersections){malloc(sizeof(t_inter) * 2), 2};
	xs.inters[0] = (t_inter){&s, -sqrt(2)/2};
	xs.inters[1] = (t_inter){&s, sqrt(2)/2};
	t_precomp	comps = precompute(xs.inters[1], r, &xs);
	assert_double_equal(1, schlick(comps), 0.0001);
	free(xs.inters);
}

static void	perpendicular_angle_test(__unused void **state)
{
	t_shape	s = glass_sphere(0);
	t_ray	r = ray(point(0, 0, 0), vector(0, 1, 0));
	t_intersections	xs = (t_intersections){malloc(sizeof(t_inter) * 2), 2};
	xs.inters[0] = (t_inter){&s, -1};
	xs.inters[1] = (t_inter){&s, 1};
	t_precomp	comps = precompute(xs.inters[1], r, &xs);
	assert_double_equal(0.04, schlick(comps), 0.0001);
	free(xs.inters);
}

static void	n2_greater_n1_test(__unused void **state)
{
	t_shape	s = glass_sphere(0);
	t_ray	r = ray(point(0, 0.99, -2), vector(0, 0, 1));
	t_intersections	xs = (t_intersections){malloc(sizeof(t_inter)), 1};
	xs.inters[0] = (t_inter){&s, 1.8589};
	t_precomp	comps = precompute(xs.inters[0], r, &xs);
	assert_double_equal(0.48873, schlick(comps), 0.0001);
	free(xs.inters);
}

static void	shade_hit_test(void **state)
{
	t_world	*w = (t_world *)*state;
	t_ray	r = ray(point(0, 0, -3), vector(0, -sqrt(2)/2, sqrt(2)/2));
	t_intersections	xs = (t_intersections){malloc(sizeof(t_inter)), 1};
	xs.inters[0] = (t_inter){w->objs + 2, sqrt(2)};
	t_precomp	comps = precompute(xs.inters[0], r, &xs);
	assert_color_equal(color(0.93391, 0.69643, 0.69243), shade_hit(*w, comps, 5));
	free(xs.inters);
}

int	test_schlick_effect(void)
{
	const struct CMUnitTest	shlik_effect_tests[] = {
		cmocka_unit_test(total_internal_reflection_test),
		cmocka_unit_test(perpendicular_angle_test),
		cmocka_unit_test(n2_greater_n1_test),
		cmocka_unit_test_setup_teardown(shade_hit_test, setup, teardown),
	};
	return (cmocka_run_group_tests(shlik_effect_tests, NULL, NULL));
}
