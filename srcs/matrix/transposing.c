/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transposing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 19:52:20 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/28 22:17:28 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	matrix_transpose(t_matrix m)
{
	return ((t_matrix){{
			{m.matrix[0][0],
			m.matrix[1][0],
		m.matrix[2][0],
			m.matrix[3][0]},
			{m.matrix[0][1],
			m.matrix[1][1],
			m.matrix[2][1],
			m.matrix[3][1]},
			{m.matrix[0][2],
			m.matrix[1][2],
			m.matrix[2][2],
			m.matrix[3][2]},
			{m.matrix[0][3],
			m.matrix[1][3],
			m.matrix[2][3],
			m.matrix[3][3]}},
			m.size});
}
