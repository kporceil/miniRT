/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_children_tests.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:15:05 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/08 17:58:57 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <math.h>
#include "tests.h"
#include "bounding_box.h"
#include "shape.h"
#include "groups.h"

static void	bounding_box_partition_children_1_test(__unused void **state)
{
	t_shape	g = group(1, 3);

	group_add_shape(&g, sphere(2));
	group_add_shape(&g, sphere(3));
	group_add_shape(&g, sphere(4));
	shape_set_matrix(g.child, matrix_translation(-2, 0, 0));
	shape_set_matrix(g.child + 1, matrix_translation(2, 0, 0));
	partition_children(&g);
	assert_int_equal(g.child[0].type, SPHERE);
	assert_int_equal(g.child[1].type, GROUP);
	assert_int_equal(g.child[2].type, GROUP);
	assert_int_equal(g.child[1].child->id, 2);
	assert_int_equal(g.child[2].child->id, 3);
	free_group(&g);
}

static void	bounding_box_partition_children_2_test(__unused void **state)
{
	t_shape g = group(1, 2);

	group_add_shape(&g, sphere(1));
	group_add_shape(&g, sphere(2));

	shape_set_matrix(g.child + 0, matrix_translation(-3, 0, 0));
	shape_set_matrix(g.child + 1, matrix_translation(3, 0, 0));

	partition_children(&g);

	// Les deux enfants du groupe racine doivent être des GROUP
	assert_int_equal(g.child[0].type, GROUP);
	assert_int_equal(g.child[1].type, GROUP);

	// Le premier groupe contient le sphere 1
	assert_int_equal(g.child[0].nb_members, 1);
	assert_int_equal(g.child[0].child[0].id, 1);

	// Le second groupe contient le sphere 2
	assert_int_equal(g.child[1].nb_members, 1);
	assert_int_equal(g.child[1].child[0].id, 2);

	free_group(&g);
}

static void	bounding_box_partition_children_3_test(__unused void **state)
{
	t_shape g = group(1, 3);

	group_add_shape(&g, sphere(10));  // left
	group_add_shape(&g, sphere(11));  // right

	t_shape large = sphere(12);      // recouvre la séparation
	shape_set_matrix(&large, matrix_scaling(3, 3, 3)); 
	group_add_shape(&g, large);

	shape_set_matrix(g.child + 0, matrix_translation(-3, 0, 0));
	shape_set_matrix(g.child + 1, matrix_translation(3, 0, 0));

	partition_children(&g);

	// Le large sphere reste au parent
	assert_int_equal(g.child[0].type, SPHERE);
	assert_int_equal(g.child[0].id, 12);

	// Les deux autres doivent être triés dans des sous-groupes
	assert_int_equal(g.child[1].type, GROUP);
	assert_int_equal(g.child[2].type, GROUP);

	// left
	assert_int_equal(g.child[1].nb_members, 1);
	assert_int_equal(g.child[1].child[0].id, 10);

	// right
	assert_int_equal(g.child[2].nb_members, 1);
	assert_int_equal(g.child[2].child[0].id, 11);

	free_group(&g);
}

static void	bounding_box_partition_children_4_test(__unused void **state)
{
	t_shape g = group(1, 3);

	group_add_shape(&g, sphere(20)); // left
	group_add_shape(&g, sphere(21)); // center
	group_add_shape(&g, sphere(22)); // right

	shape_set_matrix(g.child + 0, matrix_translation(-2, 0, 0));
	shape_set_matrix(g.child + 1, matrix_translation(0, 0, 0));   // exactement sur le plan
	shape_set_matrix(g.child + 2, matrix_translation(2, 0, 0));

	partition_children(&g);

	// l’objet 21 reste au parent
	assert_int_equal(g.child[0].id, 21);

	// deux groupes créés
	assert_int_equal(g.child[1].type, GROUP);
	assert_int_equal(g.child[2].type, GROUP);

	// left
	assert_int_equal(g.child[1].nb_members, 1);
	assert_int_equal(g.child[1].child[0].id, 20);

	// right
	assert_int_equal(g.child[2].nb_members, 1);
	assert_int_equal(g.child[2].child[0].id, 22);

	free_group(&g);
}

static void	bounding_box_partition_children_5_test(__unused void **state)
{
	t_shape g = group(1, 2);

	group_add_shape(&g, sphere(30));
	group_add_shape(&g, sphere(31));

	shape_set_matrix(g.child + 0, matrix_translation(0, -5, 0)); // très bas
	shape_set_matrix(g.child + 1, matrix_translation(0,  5, 0)); // très haut

	// La bbox va être plus grande en Y → split en Y

	partition_children(&g);

	assert_int_equal(g.child[0].type, GROUP);
	assert_int_equal(g.child[1].type, GROUP);

	assert_int_equal(g.child[0].nb_members, 1);
	assert_int_equal(g.child[1].nb_members, 1);

	assert_int_equal(g.child[0].child[0].id, 30); // Y < 0 ⇒ groupe 1
	assert_int_equal(g.child[1].child[0].id, 31); // Y > 0 ⇒ groupe 2

	free_group(&g);
}

int	test_bounding_box_partition_children(void)
{
	const struct CMUnitTest	bounding_box_partition_children_tests[] = {
		cmocka_unit_test(bounding_box_partition_children_1_test),
		cmocka_unit_test(bounding_box_partition_children_2_test),
		cmocka_unit_test(bounding_box_partition_children_3_test),
		cmocka_unit_test(bounding_box_partition_children_4_test),
		cmocka_unit_test(bounding_box_partition_children_5_test),
	};
	return (cmocka_run_group_tests(bounding_box_partition_children_tests, NULL, NULL));
}
