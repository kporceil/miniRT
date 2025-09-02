/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:00:30 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/31 12:45:09 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <stdint.h>
# include <stdbool.h>
# include "tuples.h"

typedef struct s_matrix
{
	double			matrix[4][4];
	uint_fast8_t	size;
}				t_matrix;

int			matrix_compare(t_matrix m1, t_matrix m2);
t_matrix	matrix_create(uint_fast8_t	size);
t_matrix	matrix_mult(t_matrix m1, t_matrix m2)__attribute__((hot));
t_tuple		matrix_tuple_mult(t_matrix m1, t_tuple t1)__attribute__((hot));
t_matrix	identity_matrix(uint_fast8_t size);
t_matrix	matrix_transpose(t_matrix m);
double		matrix_determinant(t_matrix m)__attribute__((hot));
t_matrix	submatrix(t_matrix m1, int row, int col)__attribute__((hot));
double		matrix_minor(t_matrix m, int row, int col)__attribute__((hot));
double		matrix_cofactor(t_matrix m, int r, int c)__attribute__((hot));
bool		is_matrix_invertible(t_matrix m);
t_matrix	matrix_invert(t_matrix m);
t_matrix	matrix_translation(double x, double y, double z);
t_matrix	matrix_scaling(double x, double y, double z);
t_matrix	matrix_x_rotation(double rad);
t_matrix	matrix_y_rotation(double rad);
t_matrix	matrix_z_rotation(double rad);
t_matrix	matrix_shearing(double x[2], double y[2], double z[2]);
t_matrix	view_transform(t_tuple from, t_tuple to, t_tuple up);

#endif
