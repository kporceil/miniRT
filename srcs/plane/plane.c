/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:15:09 by kporceil          #+#    #+#             */
/*   Updated: 2025/09/30 12:44:53 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

t_shape	plane(size_t id)
{
	return ((t_shape){.type = PLANE, .transformation = identity_matrix(3),
		.inverted = identity_matrix(4), .material = material(), .id = id});
}
