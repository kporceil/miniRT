/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:00:18 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/28 22:16:52 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "tuples.h"
#include <stdint.h>

t_matrix	matrix_mult(t_matrix m1, t_matrix m2)
{
	t_matrix	ret;
	int			i;
	int			j;

	ret = matrix_create(m1.size);
	i = 0;
	while (i < m1.size)
	{
		j = 0;
		while (j < m1.size)
		{
			ret.matrix[i][j] = m1.matrix[i][0] * m2.matrix[0][j]
				+ m1.matrix[i][1] * m2.matrix[1][j]
				+ m1.matrix[i][2] * m2.matrix[2][j]
				+ m1.matrix[i][3] * m2.matrix[3][j];
			++j;
		}
		++i;
	}
	return (ret);
}

t_tuple	matrix_tuple_mult(t_matrix m1, t_tuple t1)
{
	const double	x = t1.x;
	const double	y = t1.y;
	const double	z = t1.z;

	return ((t_tuple){x * m1.matrix[0][0] +
			y * m1.matrix[0][1] +
			z * m1.matrix[0][2] +
			t1.w * m1.matrix[0][3],
			x * m1.matrix[1][0] +
			y * m1.matrix[1][1] +
			z * m1.matrix[1][2] +
			t1.w * m1.matrix[1][3],
			x * m1.matrix[2][0] +
			y * m1.matrix[2][1] +
			z * m1.matrix[2][2] +
			t1.w * m1.matrix[2][3],
			x * m1.matrix[3][0] +
			y * m1.matrix[3][1] +
			z * m1.matrix[3][2] +
			t1.w * m1.matrix[3][3]});
}
