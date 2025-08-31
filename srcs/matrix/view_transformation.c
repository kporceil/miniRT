/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transformation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 12:38:23 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/31 12:44:55 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	const t_tuple	forward = normalize(tuple_substract(to, from));
	const t_tuple	left = cross(forward, normalize(up));
	const t_tuple	true_up = cross(left, forward);
	const t_matrix	orientation = {{{left.x, left.y, left.z, 0},
		{true_up.x, true_up.y, true_up.z, 0},
		{-forward.x, -forward.y, -forward.z, 0},
		{0, 0, 0, 1}}, 4};

	return (matrix_mult(orientation, matrix_translation (-from.x, -from.y,
					-from.z)));
}
