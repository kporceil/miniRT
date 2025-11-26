/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 21:29:12 by kporceil          #+#    #+#             */
/*   Updated: 2025/09/12 13:40:27 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include "world.h"
#include "ray.h"

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

static void	world_ray_intersect_test(void **state)
{
	t_world	*world = (t_world *)*state;
	t_intersections	inters = world_intersect(*world, ray(point(0, 0, -5), vector(0, 0, 1)));

	assert_int_equal(inters.size, 4);
	assert_double_equal(inters.inters[0].point, 4, 0.0001);
	assert_double_equal(inters.inters[1].point, 4.5, 0.0001);
	assert_double_equal(inters.inters[2].point, 5.5, 0.0001);
	assert_double_equal(inters.inters[3].point, 6, 0.0001);
}

int	test_world_intersections(void)
{
	const struct CMUnitTest	world_intersection_tests[] = {
		cmocka_unit_test_setup_teardown(world_ray_intersect_test, setup, teardown),
	};
	return (cmocka_run_group_tests(world_intersection_tests, NULL, NULL));
}
