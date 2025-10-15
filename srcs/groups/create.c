/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:06:27 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/15 10:42:31 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "matrix.h"
#include "material.h"
#include <stdlib.h>

// NOTE: all calls to this function should ce checked (malloc)

t_shape	group(size_t id, size_t nb_members)
{
	return ((t_shape){.type = GROUP,
			.transformation = identity_matrix(3),
			.inverted = identity_matrix(4),
			.material = material(),
			.parent = NULL,
			.child = malloc(sizeof(t_shape) * nb_members),
			.id = id});
}
