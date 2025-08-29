/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 00:37:13 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/27 00:38:57 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

double	matrix_minor(t_matrix m, int row, int col)
{
	return (matrix_determinant(submatrix(m, row, col)));
}
