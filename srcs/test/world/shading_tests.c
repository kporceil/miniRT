/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 22:58:31 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/26 16:53:47 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include "ray.h"
#include "world.h"
#include "color.h"
#include "tests.h"

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
	world->ambient = color(0.1, 0.1, 0.1);
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

static void	shading_intersect_test(void **state)
{
	t_world	*world = (t_world *)*state;
	t_ray	r = ray(point(0, 0, -5), vector(0, 0, 1));
	t_inter	i = {.s = world->objs, .point = 4};
	t_precomp	comps = precompute(i, r, NULL);
	t_color		c = shade_hit(*world, comps, 0);

	assert_color_equal(color(0.38066, 0.47583, 0.2855), c);
}

static void	inside_shading_intersect_test(void **state)
{
	t_world	*world = (t_world *)*state;
	*world->lights = point_light(point(0, 0.25, 0), color(1, 1, 1));
	t_ray	r = ray(point(0, 0, 0), vector(0, 0, 1));
	t_inter	i = {.s = world->objs + 1, .point = 0.5};
	t_precomp	comps = precompute(i, r, NULL);
	t_color		c = shade_hit(*world, comps, 0);

	assert_color_equal(color(0.90498, 0.90498, 0.90498), c);
}

static void	shading_no_hit_test(void **state)
{
	t_world	*world = (t_world *)*state;
	t_ray	r = ray(point(0, 0, -5), vector(0, 1, 0));
	t_color	c;

	if (color_at(*world, r, &c, 0))
		fail_msg("Malloc_fail");
	assert_color_equal(color(0, 0, 0), c);
}

static void	shading_hit_test(void **state)
{
	t_world	*world = (t_world *)*state;
	t_ray	r = ray(point(0, 0, -5), vector(0, 0, 1));
	t_color	c;

	if (color_at(*world, r, &c, 0))
		fail_msg("Malloc fail");
	assert_color_equal(color(0.38066, 0.47583, 0.2855), c);
}

static void	behind_shading_hit_test(void **state)
{
	t_world	*world = (t_world *)*state;
	t_shape	*inner = world->objs + 1;
	world->ambient = color(1, 1, 1);
	t_ray	r = ray(point(0, 0, 0.75), vector(0, 0, -1));
	t_color	c;

	if (color_at(*world, r, &c, 0))
		fail_msg("Malloc fail");
	assert_color_equal(inner->material.color, c);
}

int	test_world_shading(void)
{
	const struct CMUnitTest	world_shading_tests[] = {
		cmocka_unit_test_setup_teardown(shading_intersect_test, setup, teardown),
		cmocka_unit_test_setup_teardown(inside_shading_intersect_test, setup, teardown),
		cmocka_unit_test_setup_teardown(shading_no_hit_test, setup, teardown),
		cmocka_unit_test_setup_teardown(shading_hit_test, setup, teardown),
		cmocka_unit_test_setup_teardown(behind_shading_hit_test, setup, teardown),
	};
	return (cmocka_run_group_tests(world_shading_tests, NULL, NULL));
}
