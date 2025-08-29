/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:07:23 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/29 13:51:59 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include "tuples.h"
# include "color.h"
# include "matrix.h"

void	assert_tuple_equal(t_tuple a, t_tuple b);
void	assert_color_equal(t_color a, t_color b);
void	assert_matrix_equal(t_matrix a, t_matrix b);

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

#endif
