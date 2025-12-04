/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:34:17 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/26 18:22:32 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"
#include "shape.h"

t_shape	smooth_triangle(size_t id, t_tuple p[3], t_tuple n[3])
{
	t_shape	ret;

	ret = (t_shape){.type = SMOOTH_TRIANGLE,
		.local_transformation = identity_matrix(4),
		.final_transformation = identity_matrix(4),
		.final_inverted = identity_matrix(4),
		.material = material(),
		.tri_p1 = p[0],
		.tri_p2 = p[1],
		.tri_p3 = p[2],
		.tri_n1 = n[0],
		.tri_n2 = n[1],
		.tri_n3 = n[2],
		.tri_e1 = tuple_substract(p[1], p[0]),
		.tri_e2 = tuple_substract(p[2], p[0]),
		.id = id};
	ret.tri_normal = normalize(cross(ret.tri_e2, ret.tri_e1));
	return (ret);
}
