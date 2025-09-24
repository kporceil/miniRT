/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 20:55:57 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/28 22:17:40 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

double	matrix_determinant(t_matrix m)
{
	double	det;
	int		i;

	if (m.size == 2)
		return (m.matrix[0][0] * m.matrix[1][1] - m.matrix[0][1]
				* m.matrix[1][0]);
	i = 0;
	det = 0;
	while (i < m.size)
	{
		det += m.matrix[0][i] * matrix_cofactor(m, 0, i);
		++i;
	}
	return (det);
}
