/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:46:17 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/15 17:33:36 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include <float.h>
#include "libft.h"
#include "shape.h"
#include "tests.h"
#include "ray.h"
#include "tuples.h"
#include "groups.h"
#include "vectors.h"

#ifndef EPSILON
# define EPSILON 0.0001
#endif

static void	intersect_group_1_test(__unused void **state)
{
	t_shape	g = group(1, 0);
	t_ray	r = ray(point(0, 0, 0), vector(0, 0, 1));
	t_intersections xs = (t_intersections){0};

	ray_group_intersect(&g, r, &xs);
	xs.size = 0;
	assert_int_equal(xs.size, 0);
}

static void	intersect_group_2_test(__unused void **state)
{
	t_shape	g = group(1, 3);
	t_ray	r = ray(point(0, 0, -5), vector(0, 0, 1));
	t_intersections xs = (t_intersections){0};

	xs.inters = malloc(sizeof(t_inter) * 4);
	xs.size = 0;
	group_add_shape(&g, sphere(2));
	group_add_shape(&g, sphere(3));
	shape_set_matrix(g.child + 1, matrix_translation(0, 0, -3));
	group_add_shape(&g, sphere(4));
	shape_set_matrix(g.child + 2, matrix_translation(5, 0, 0));
	ray_group_intersect(&g, r, &xs);
	assert_int_equal(xs.size, 4);
	free(xs.inters);
	vec_free(g.child);
}

int	test_group_intersect(void)
{
	const struct CMUnitTest	group_intersect_tests[] = {
		cmocka_unit_test(intersect_group_1_test),
		cmocka_unit_test(intersect_group_2_test),
	};
	return (cmocka_run_group_tests(group_intersect_tests, NULL, NULL));
}
