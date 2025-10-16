/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:07:23 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/15 17:33:57 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# ifndef __unused
#  define __unused __attribute__((unused))
# endif

# ifndef assert_tuple_equal
#  define assert_tuple_equal(a, b)	assert_double_equal(a.x, b.x, 0.0001); \
									assert_double_equal(a.y, b.y, 0.0001); \
									assert_double_equal(a.z, b.z, 0.0001); \
									assert_double_equal(a.w, b.w, 0.0001);
# endif

# ifndef assert_color_equal
#  define assert_color_equal(a, b)	assert_double_equal(a.red, b.red, 0.0001); \
									assert_double_equal(a.green, b.green, 0.0001); \
									assert_double_equal(a.blue, b.blue, 0.0001);
# endif

# ifndef assert_matrix_equal
#  define assert_matrix_equal(a, b)	do { \
										assert_int_equal(a.size, b.size); \
										for (uint_fast8_t	i = 0; i < a.size; ++i) \
											for (uint_fast8_t j = 0; j < a.size; ++j) \
												assert_double_equal(a.matrix[i][j], b.matrix[i][j], 0.0001); \
									} while (0);
# endif

# ifndef assert_double_greater
#  define assert_double_greater(a, b)	do { \
											if (!(a > b))  \
												fail_msg("%f is not greater than %f", a, b); \
										} while (0);
# endif

int		test_tuple_creation(void);
int		test_color_create(void);
int		test_tuple_add(void);
int		test_tuple_substract(void);
int		test_tuple_negate(void);
int		test_tuple_scalar(void);
int		test_tuple_magnitude(void);
int		test_tuple_normalizing(void);
int		test_tuple_dot_product(void);
int		test_tuple_cross_product(void);

int		test_color_add(void);
int		test_color_substract(void);
int		test_color_scalar_mult(void);
int		test_color_mult(void);

int		test_canva_create(void);
int		test_write_pixel(void);
int		test_ppm_creation(void);

int		test_matrix_create(void);
int		test_matrix_comparison(void);
int		test_matrix_mult(void);
int		test_matrix_transposing(void);
int		test_matrix_determinant(void);
int		test_submatrix(void);
int		test_matrix_minors(void);
int		test_matrix_cofactor(void);
int		test_larger_determinant(void);
int		test_inverting_matrix(void);
int		test_translation_matrix(void);
int		test_scaling_matrix(void);
int		test_rotation_matrix(void);
int		test_shearing_matrix(void);
int		test_chaining_matrix(void);

int		test_ray_create(void);
int		test_ray_position(void);
int		test_ray_sphere_intersect(void);
int		test_ray_hit(void);
int		test_ray_transformation(void);

int		test_normal_finding(void);
int		test_reflection(void);
int		test_point_light(void);
int		test_material(void);
int		test_phong(void);

int		test_create_world(void);
int		test_world_intersections(void);
int		test_shading_precomputation(void);
int		test_world_shading(void);

int		test_view_transformation(void);

int		test_camera_create(void);
int		test_camera_ray(void);
int		test_camera_render(void);

int		test_in_shadow(void);
int		test_is_shadowed(void);
int		test_render_shadow(void);

int		test_plane_intersect(void);

int		test_cylinder_create(void);
int		test_cylinder_intersect(void);
int		test_cylinder_normal(void);
int		test_cylinder_truncate(void);
int		test_end_cap_cylinder_intersect(void);
int		test_end_cap_cylinder_normal(void);

int		test_cone_intersect(void);
int		test_end_cap_cone_intersect(void);
int		test_cone_normal(void);

int		test_striped_pattern(void);
int		test_transformed_pattern(void);
int		test_ring_pattern(void);
int		test_gradient_pattern(void);
int		test_checker_pattern(void);

int		test_precompute_reflect(void);
int		test_reflective(void);

int		test_determine_indices(void);
int		test_compute_under_point(void);
int		test_refractive_color(void);
int		test_schlick_effect(void);

int		test_cube_intersect(void);
int		test_cube_normal(void);

int		test_group_create(void);
int		test_group_intersect(void);
int		test_group_transform(void);
int		test_group_normal(void);

#endif
