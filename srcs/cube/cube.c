/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:55:13 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/08 12:56:14 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

t_shape	cube(size_t id)
{
	return ((t_shape){.type = CUBE, .transformation = identity_matrix(4),
		.inverted = identity_matrix(4), .parent = NULL,
		.id = id, .material = material()});
}
