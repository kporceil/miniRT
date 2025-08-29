/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparison.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:14:59 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/26 17:59:15 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <stdint.h>
#include <math.h>

int	matrix_compare(t_matrix m1, t_matrix m2)
{
	uint_fast8_t	i;
	uint_fast8_t	j;

	if (m1.size != m2.size)
		return (-1);
	i = 0;
	while (i < m1.size)
	{
		j = 0;
		while (j < m1.size)
		{
			if (fabs(m1.matrix[i][j] - m2.matrix[i][j]) > 0.0001)
				return (-1);
			++j;
		}
		++i;
	}
	return (0);
}
