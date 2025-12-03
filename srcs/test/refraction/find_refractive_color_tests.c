/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_refractive_color_tests.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:30:18 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/06 15:29:01 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "ray.h"
#include "world.h"
#include "refract.h"
#include <math.h>
#include <stdlib.h>
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
	world->objs_count = 2;
	world->objs = malloc(sizeof(t_shape) * 2);
	world->lights = malloc(sizeof(t_plight));
	if (!world->objs || !world->lights)
	{
		free(world->objs);
		free(world->lights);
		free(world);
		return (-1);
	}
	world->buf_inter = malloc(sizeof(t_inter) * 4);
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

static void	opaque_object_test(void **state)
{
	t_world	*w = (t_world *)*state;
	t_ray	r = ray(point(0, 0, -5), vector(0, 0, 1));
	t_intersections	xs = (t_intersections){malloc(sizeof(t_inter) * 2), 2};

	xs.inters[0].s = w->objs;
	xs.inters[0].point = 4;
	xs.inters[1].s = w->objs;
	xs.inters[1].point = 6;
	assert_color_equal(color(0, 0, 0), refracted_color(*w, precompute(xs.inters[0], r, &xs), 5));
	free(xs.inters);
}

static void	max_recursive_test(void **state)
{
	t_world	*w = (t_world *)*state;
	t_ray	r = ray(point(0, 0, -5), vector(0, 0, 1));
	t_intersections	xs = (t_intersections){malloc(sizeof(t_inter) * 2), 2};

	xs.inters[0].s = w->objs;
	xs.inters[0].point = 4;
	xs.inters[1].s = w->objs;
	xs.inters[1].point = 6;
	w->objs[0].material.transparency = 1.0;
	w->objs[0].material.refractive_index = 1.5;
	assert_color_equal(color(0, 0, 0), refracted_color(*w, precompute(xs.inters[0], r, &xs), 0));
	free(xs.inters);
}

static void	total_internal_test(void **state)
{
	t_world	*w = (t_world *)*state;
	t_ray	r = ray(point(0, 0, sqrt(2)/2), vector(0, 1, 0));
	t_intersections	xs = (t_intersections){malloc(sizeof(t_inter) * 2), 2};

	xs.inters[0].s = w->objs;
	xs.inters[0].point = -sqrt(2)/2;
	xs.inters[1].s = w->objs;
	xs.inters[1].point = sqrt(2)/2;
	w->objs[0].material.transparency = 1.0;
	w->objs[0].material.refractive_index = 1.5;
	assert_color_equal(color(0, 0, 0), refracted_color(*w, precompute(xs.inters[1], r, &xs), 5));
	free(xs.inters);
}

static void	refractive_color_test(void **state)
{
	t_world	*w = (t_world *)*state;
	t_ray	r = ray(point(0, 0, 0.1), vector(0, 1, 0));
	t_intersections	xs = (t_intersections){malloc(sizeof(t_inter) * 4), 2};

	w->objs[0].material.ambient = 1.0;
	w->objs[0].material.pat = pattern(NO, color(1, 1, 1), color(0, 0, 0));
	w->objs[1].material.transparency = 1.0;
	w->objs[1].material.refractive_index = 1.5;
	xs.inters[0].s = w->objs;
	xs.inters[0].point = -0.9899;
	xs.inters[1].s = w->objs + 1;
	xs.inters[1].point = -0.4899;
	xs.inters[2].s = w->objs + 1;
	xs.inters[2].point = 0.4899;
	xs.inters[3].s = w->objs;
	xs.inters[3].point = 0.9899;
	assert_color_equal(color(0, 0.99888, 0.4725), refracted_color(*w, precompute(xs.inters[2], r, &xs), 5));
	free(xs.inters);
}

static void	refractive_in_shade_hit_test(void **state)
{
	t_world			*w = (t_world *)*state;
	t_ray			r = ray(point(0, 0, -3), vector(0, -sqrt(2)/2, sqrt(2)/2));
	t_intersections	xs = (t_intersections){malloc(sizeof(t_inter)), 1};
	t_shape			floor = plane(2);
	t_shape			ball = sphere(3);
	w->objs = realloc(w->objs, sizeof(t_shape) * 4);
	w->buf_inter = realloc(w->buf_inter, sizeof(t_inter) * 8);
	w->objs[2] = floor;
	w->objs[3] = ball;
	w->objs[2].material.transparency = 0.5;
	w->objs[2].material.refractive_index = 1.5;
	w->objs[3].material.color = color(1, 0, 0);
	w->objs[3].material.ambient = 0.5;
	w->objs_count = 4;
	shape_set_matrix(w->objs + 2, matrix_translation(0, -1, 0));
	shape_set_matrix(w->objs + 3, matrix_translation(0, -3.5, -0.5));
	xs.inters[0].s = w->objs + 2;
	xs.inters[0].point = sqrt(2);
	t_color	ret = shade_hit(*w, precompute(xs.inters[0], r, &xs), 50);
	assert_color_equal(color(0.93642, 0.68642, 0.68642), ret);
	free(xs.inters);
}

int	test_refractive_color(void)
{
	const struct CMUnitTest	refractive_color_tests[] = {
		cmocka_unit_test_setup_teardown(opaque_object_test, setup, teardown),
		cmocka_unit_test_setup_teardown(max_recursive_test, setup, teardown),
		cmocka_unit_test_setup_teardown(total_internal_test, setup, teardown),
		cmocka_unit_test_setup_teardown(refractive_color_test, setup, teardown),
		cmocka_unit_test_setup_teardown(refractive_in_shade_hit_test, setup, teardown),
	};
	return (cmocka_run_group_tests(refractive_color_tests, NULL, NULL));
}
