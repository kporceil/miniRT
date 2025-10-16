/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:50:00 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/16 15:50:00 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

t_shape	torus(size_t id)
{
	return ((t_shape){.type = TORUS, .transformation = identity_matrix(4),
		.inverted = identity_matrix(4), .id = id, .material = material(),
		.torus_major = 1.0, .torus_minor = 0.25});
}
