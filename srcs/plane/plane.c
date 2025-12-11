/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:15:09 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/15 10:26:57 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

t_shape	plane(size_t id)
{
	return ((t_shape){.type = PLANE,
		.local_transformation = identity_matrix(3),
		.final_transformation = identity_matrix(3),
		.final_inverted = identity_matrix(4),
		.material = material(),
		.parent = NULL,
		.id = id,
		.skybox = false});
}
