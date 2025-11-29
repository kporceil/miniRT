/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_count_tests.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:46:39 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/28 19:29:47 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "light.h"
#include "scenes_parsing.h"
#include "tests.h"
#include "world.h"

void	free_light_list(t_world *world);

static void	one_light_test(__unused void **state)
{
	t_world	world = world_create();

	assert_int_equal(parse_file("test_assets/one_light.rt", &world), 0);
	assert_int_equal(world.lights_count, 1);
	assert_tuple_equal(world.tmp_light->light.pos, point(0, 0, 0));
	assert_color_equal(world.tmp_light->light.intensity, color(1, 1, 1));
	free_light_list(&world);
}

static void	multi_light_test(__unused void **state)
{
	t_world	world = world_create();
	
	assert_int_equal(parse_file("test_assets/multi_light.rt", &world), 0);
	assert_int_equal(world.lights_count, 5);
	free_light_list(&world);
}

static void	no_light_test(__unused void **state)
{
	t_world	world = world_create();

	assert_int_equal(parse_file("test_assets/no_light.rt", &world), 0);
	assert_int_equal(world.lights_count, 0);
}

int	test_lights_count(void)
{
	const struct CMUnitTest	light_count_tests[] = {
		cmocka_unit_test(one_light_test),
		cmocka_unit_test(multi_light_test),
		cmocka_unit_test(no_light_test),
	};
	return (cmocka_run_group_tests(light_count_tests, NULL, NULL));
}
