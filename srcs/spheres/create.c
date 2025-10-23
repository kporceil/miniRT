/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:51:03 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/15 10:27:27 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

t_shape	sphere(size_t id)
{
	return ((t_shape){.type = SPHERE,
		.local_transformation = identity_matrix(3),
		.final_transformation = identity_matrix(3),
		.final_inverted = identity_matrix(4),
		.material = material(),
		.parent = NULL,
		.id = id});
}
