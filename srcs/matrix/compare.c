/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:14:59 by kporceil          #+#    #+#             */
/*   Updated: 2025/09/24 02:37:44 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <stdint.h>
#include <math.h>

int	matrix_compare(t_matrix m1, t_matrix m2)
{
	if (m1.size != m2.size)
		return (-1);
	if (fabs(m1.matrix[0][0] - m2.matrix[0][0]) > 0.0001 ||
		fabs(m1.matrix[0][1] - m2.matrix[0][1]) > 0.0001 ||
		fabs(m1.matrix[0][2] - m2.matrix[0][2]) > 0.0001 ||
		fabs(m1.matrix[0][3] - m2.matrix[0][3]) > 0.0001 ||
		fabs(m1.matrix[1][0] - m2.matrix[1][0]) > 0.0001 ||
		fabs(m1.matrix[1][1] - m2.matrix[1][1]) > 0.0001 ||
		fabs(m1.matrix[1][2] - m2.matrix[1][2]) > 0.0001 ||
		fabs(m1.matrix[1][3] - m2.matrix[1][3]) > 0.0001 ||
		fabs(m1.matrix[2][0] - m2.matrix[2][0]) > 0.0001 ||
		fabs(m1.matrix[2][1] - m2.matrix[2][1]) > 0.0001 ||
		fabs(m1.matrix[2][2] - m2.matrix[2][2]) > 0.0001 ||
		fabs(m1.matrix[2][3] - m2.matrix[2][3]) > 0.0001 ||
		fabs(m1.matrix[3][0] - m2.matrix[3][0]) > 0.0001 ||
		fabs(m1.matrix[3][1] - m2.matrix[3][1]) > 0.0001 ||
		fabs(m1.matrix[3][2] - m2.matrix[3][2]) > 0.0001 ||
		fabs(m1.matrix[3][3] - m2.matrix[3][3]) > 0.0001)
		return (-1);
	return (0);
}
