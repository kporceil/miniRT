/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs_count_tests.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:56:21 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/27 16:12:47 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "scenes_parsing.h"
#include "tests.h"
#include "world.h"

static void	one_obj_test(__unused void **state)
{
	t_world	world = world_create();

	assert_int_equal(parse_file("test_assets/one_obj.rt", &world), 0);
	assert_int_equal(world.objs_count, 1);
}

static void	multi_obj_test(__unused void **state)
{
	t_world	world = world_create();
	
	assert_int_equal(parse_file("test_assets/multi_obj.rt", &world), 0);
	assert_int_equal(world.objs_count, 5);
}

static void	no_obj_test(__unused void **state)
{
	t_world	world = world_create();

	assert_int_equal(parse_file("test_assets/no_obj.rt", &world), 0);
	assert_int_equal(world.objs_count, 0);
}

int	test_objs_count(void)
{
	const struct CMUnitTest	obj_count_tests[] = {
		cmocka_unit_test(one_obj_test),
		cmocka_unit_test(multi_obj_test),
		cmocka_unit_test(no_obj_test),
	};
	return (cmocka_run_group_tests(obj_count_tests, NULL, NULL));
}
