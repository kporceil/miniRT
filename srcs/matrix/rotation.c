/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:39:23 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/27 15:42:48 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <math.h>

t_matrix	matrix_x_rotation(double rad)
{
	return ((t_matrix){{
			{1, 0, 0, 0},
			{0, cos(rad), -sin(rad), 0},
			{0, sin(rad), cos(rad), 0},
			{0, 0, 0, 1}}, 4});
}

t_matrix	matrix_y_rotation(double rad)
{
	return ((t_matrix){{
			{cos(rad), 0, sin(rad), 0},
			{0, 1, 0, 0},
			{-sin(rad), 0, cos(rad), 0},
			{0, 0, 0, 1}}, 4});
}

t_matrix	matrix_z_rotation(double rad)
{
	return ((t_matrix){{
			{cos(rad), -sin(rad), 0, 0},
			{sin(rad), cos(rad), 0, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 1}}, 4});
}
