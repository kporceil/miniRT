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
	int			i_ret;
	int			i_m1;
	int			j_ret;
	int			j_m1;

	ret = matrix_create(m1.size - 1);
	i_ret = 0;
	i_m1 = 0;
	while (i_m1 < m1.size)
	{
		if (i_m1 == row)
			++i_m1;
		j_m1 = 0;
		j_ret = 0;
		while (j_m1 < m1.size)
		{
			if (j_m1 == col)
				++j_m1;
			ret.matrix[i_ret][j_ret++] = m1.matrix[i_m1][j_m1++];
		}
		++i_ret;
		++i_m1;
	}
	return (ret);
}
