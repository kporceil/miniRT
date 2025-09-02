/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cofactor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 00:48:45 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/27 01:01:27 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

inline double	matrix_cofactor(t_matrix m, int row, int col)
{
	if ((row + col) % 2)
		return (-matrix_minor(m, row, col));
	return (matrix_minor(m, row, col));
}
