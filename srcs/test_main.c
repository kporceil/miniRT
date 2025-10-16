/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 00:15:57 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/15 17:34:23 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <stdio.h>

int	main(void)
{
	int	ret;

	ret = 0;
	ret += test_tuple_creation();
	ret += test_tuple_add();
	ret += test_tuple_substract();
	ret += test_tuple_negate();
	ret += test_tuple_scalar();
	ret += test_tuple_magnitude();
	ret += test_tuple_normalizing();
	ret += test_tuple_dot_product();
	ret += test_tuple_cross_product();
	ret += test_color_create();
	ret += test_color_add();
	ret += test_color_substract();
	ret += test_color_scalar_mult();
	ret += test_color_mult();
	ret += test_canva_create();
	ret += test_write_pixel();
	ret += test_ppm_creation();
	ret += test_matrix_create();
	ret += test_matrix_comparison();
	ret += test_matrix_mult();
	ret += test_matrix_transposing();
	ret += test_matrix_determinant();
	ret += test_submatrix();
	ret += test_matrix_minors();
	ret += test_matrix_cofactor();
	ret += test_larger_determinant();
	ret += test_inverting_matrix();
	ret += test_translation_matrix();
	ret += test_scaling_matrix();
	ret += test_rotation_matrix();
	ret += test_shearing_matrix();
	ret += test_chaining_matrix();
	ret += test_ray_create();
	ret += test_ray_position();
	ret += test_ray_sphere_intersect();
	ret += test_ray_hit();
	ret += test_ray_transformation();
	ret += test_normal_finding();
	ret += test_reflection();
	ret += test_point_light();
	ret += test_material();
	ret += test_phong();
	ret += test_create_world();
	ret += test_world_intersections();
	ret += test_shading_precomputation();
	ret += test_world_shading();
	ret += test_view_transformation();
	ret += test_camera_create();
	ret += test_camera_ray();
	ret += test_camera_render();
	ret += test_in_shadow();
	ret += test_is_shadowed();
	ret += test_render_shadow();
	ret += test_plane_intersect();
	ret += test_cylinder_create();
	ret += test_cylinder_intersect();
	ret += test_cylinder_normal();
	ret += test_cylinder_truncate();
	ret += test_end_cap_cylinder_intersect();
	ret += test_end_cap_cylinder_normal();
	ret += test_cone_intersect();
	ret += test_end_cap_cone_intersect();
	ret += test_cone_normal();
	ret += test_striped_pattern();
	ret += test_transformed_pattern();
	ret += test_ring_pattern();
	ret += test_gradient_pattern();
	ret += test_checker_pattern();
	ret += test_precompute_reflect();
	ret += test_reflective();
	ret += test_determine_indices();
	ret += test_compute_under_point();
	ret += test_refractive_color();
	ret += test_schlick_effect();
	ret += test_cube_intersect();
	ret += test_cube_normal();
	ret += test_group_create();
	ret += test_group_intersect();
	ret += test_group_transform();
	ret += 	test_group_normal();
	printf("Failed %d tests\n", ret);
	return (ret);
}
