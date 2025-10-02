/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:51:03 by kporceil          #+#    #+#             */
/*   Updated: 2025/09/30 12:43:57 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

t_shape	sphere(size_t id)
{
	return ((t_shape){.type = SPHERE, .transformation = identity_matrix(3),
		.inverted = identity_matrix(4), .material = material(), .id = id});
}
