/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:06:27 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/03 14:41:21 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "matrix.h"
#include "material.h"
#include "bounding_box.h"
#include "vectors.h"
#include <stdlib.h>

// NOTE: all calls to this function should ce checked (malloc)

t_shape	group(size_t id, size_t group_size)
{
	t_shape	ret;

	ret = (t_shape){.type = GROUP,
		.local_transformation = identity_matrix(4),
		.final_transformation = identity_matrix(4),
		.final_inverted = identity_matrix(4),
		.material = material(),
		.parent = NULL,
		.group_bbox = bounding_box(false, (t_tuple){0}, (t_tuple){0}),
		.group_size = group_size,
		.nb_members = 0,
		.id = id};
	if (group_size)
		ret.child = vec_create(sizeof(t_shape), group_size);
	else
		ret.child = NULL;
	return (ret);
}
