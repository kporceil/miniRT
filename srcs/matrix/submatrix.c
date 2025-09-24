/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   submatrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 21:11:27 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/26 21:23:15 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	submatrix(t_matrix m1, int row, int col)
{
	t_matrix	ret;
	int			i[2];
	int			j[2];

	ret = matrix_create(m1.size - 1);
	i[0] = 0;
	i[1] = 0;
	while (i[1] < m1.size)
	{
		if (i[1] == row)
			++i[1];
		j[1] = 0;
		j[0] = 0;
		while (j[1] < m1.size)
		{
			if (j[1] == col)
				++j[1];
			if (j[1] >= m1.size || i[1] >= m1.size)
				break ;
			ret.matrix[i[0]][j[0]++] = m1.matrix[i[1]][j[1]++];
		}
		++i[0];
		++i[1];
	}
	return (ret);
}
