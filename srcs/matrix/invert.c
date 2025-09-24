/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 02:02:15 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/27 02:24:19 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	matrix_invert(t_matrix m)
{
	t_matrix	inverted;
	double		det;
	int			i;
	int			j;

	inverted = matrix_create(4);
	det = matrix_determinant(m);
	i = 0;
	while (i < m.size)
	{
		j = 0;
		while (j < m.size)
		{
			inverted.matrix[j][i] = matrix_cofactor(m, i, j) / det;
			++j;
		}
		++i;
	}
	return (inverted);
}
