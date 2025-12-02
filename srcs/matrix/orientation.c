/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:50:06 by kporceil          #+#    #+#             */
/*   Updated: 2025/12/02 21:52:59 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	object_orientation(t_tuple position, t_tuple forward, t_tuple up)
{
	const t_tuple	right = normalize(cross(normalize(up), forward));
	const t_tuple	true_up = cross(forward, right);
	const t_matrix	orientation = {{
	{right.x, forward.x, true_up.x, 0},
	{right.y, forward.y, true_up.y, 0},
	{right.z, forward.z, true_up.z, 0},
	{0, 0, 0, 1}
	}, 4};

	return (matrix_mult(matrix_translation(position.x, position.y, position.z),
			orientation));
}
