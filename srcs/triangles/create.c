/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:34:17 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/10 17:49:10 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"
#include "shape.h"

t_shape	triangle(size_t id, t_tuple p1, t_tuple p2, t_tuple p3)
{
	t_shape	ret;

	ret = (t_shape){.type = TRIANGLE,
		.local_transformation = identity_matrix(4),
		.final_transformation = identity_matrix(4),
		.final_inverted = identity_matrix(4),
		.material = material(),
		.tri_p1 = p1,
		.tri_p2 = p2,
		.tri_p3 = p3,
		.tri_e1 = tuple_substract(p2, p1),
		.tri_e2 = tuple_substract(p3, p1),
		.id = id};
	ret.tri_normal = normalize(cross(ret.tri_e2, ret.tri_e1));
	return (ret);
}
