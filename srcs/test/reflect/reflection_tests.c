/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_tests.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:51:19 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/02 17:35:55 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "ray.h"
#include "world.h"
#include "tests.h"
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

static void	non_reflective_test(void **state)
{
	t_world	*w = (t_world *)(*state);
	t_ray	r = ray(point(0, 0, 0), vector(0, 0, 1));
	t_inter	i = (t_inter){w->objs + 1, 1};
	
	w->objs[1].material.ambient = 1;
	assert_color_equal(color(0, 0, 0), reflected_color(*w, precompute(i, r, NULL), 1));
}

static void	reflective_test(void **state)
{
	t_world	*w = (t_world*)(*state);
	t_ray	r = ray(point(0, 0, -3), vector(0, -(sqrt(2)/2), sqrt(2)/2));

	w->objs = realloc(w->objs, sizeof(t_shape) * 3);
	w->buf_inter = realloc(w->buf_inter, sizeof(t_inter) * 6);
	w->objs[2] = plane(2);
	w->objs[2].material.reflective = 0.5;
	shape_set_matrix(w->objs + 2, matrix_translation(0, -1, 0));
	assert_color_equal(color(0.19032, 0.2379, 0.14274), reflected_color(*w, precompute((t_inter){w->objs + 2, sqrt(2)}, r, NULL), 1));
}

static void	color_reflective_test(void **state)
{
	t_world	*w = (t_world*)(*state);
	t_ray	r = ray(point(0, 0, -3), vector(0, -(sqrt(2)/2), sqrt(2)/2));

	w->objs = realloc(w->objs, sizeof(t_shape) * 3);
	w->buf_inter = realloc(w->buf_inter, sizeof(t_inter) * 6);
	w->objs[2] = plane(2);
	w->objs[2].material.reflective = 0.5;
	shape_set_matrix(w->objs + 2, matrix_translation(0, -1, 0));
	assert_color_equal(color(0.87677, 0.92436, 0.82918), shade_hit(*w, precompute((t_inter){w->objs + 2, sqrt(2)}, r, NULL), 1));
}

static void	infinte_resursive_test(__unused void **state)
{
	t_world	w = world_create();
	t_ray	r = ray(point(0, 0, 0), vector(0, 1, 0));
	t_color	c;

	w.objs = malloc(sizeof(t_shape) * 2);
	w.lights = malloc(sizeof(t_plight));
	w.buf_inter = malloc(sizeof(t_inter) * 4);
	w.lights[0] = point_light(point(0, 0, 0), color(1, 1, 1));
	w.objs[0] = plane(0);
	w.objs[0].material.reflective = 1;
	shape_set_matrix(w.objs, matrix_translation(0, -1, 0));
	w.objs[1] = plane(1);
	w.objs[1].material.reflective = 1;
	shape_set_matrix(w.objs + 1, matrix_translation(0, 1, 0));
	color_at(w, r, &c, MAX_RECU);
	free(w.buf_inter);
	free(w.objs);
	free(w.lights);
}

static void	limit_recursion_test(void **state)
{
	t_world	*w = (t_world*)(*state);
	t_ray	r = ray(point(0, 0, -3), vector(0, -(sqrt(2)/2), sqrt(2)/2));

	w->objs = realloc(w->objs, sizeof(t_shape) * 3);
	w->buf_inter = realloc(w->buf_inter, sizeof(t_inter) * 6);
	w->objs[2] = plane(3);
	w->objs[2].material.reflective = 0.5;
	shape_set_matrix(w->objs + 2, matrix_translation(0, -1, 0));
	assert_color_equal(color(0, 0, 0), reflected_color(*w, precompute((t_inter){w->objs + 2, sqrt(2)}, r, NULL), 0));
}

int	test_reflective(void)
{
	const struct CMUnitTest	reflection_tests[] = {
		cmocka_unit_test_setup_teardown(non_reflective_test, setup, teardown),
		cmocka_unit_test_setup_teardown(reflective_test, setup, teardown),
		cmocka_unit_test_setup_teardown(color_reflective_test, setup, teardown),
		cmocka_unit_test(infinte_resursive_test),
		cmocka_unit_test_setup_teardown(limit_recursion_test, setup, teardown),
	};
	return (cmocka_run_group_tests(reflection_tests, NULL, NULL));
}
