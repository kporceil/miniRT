/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:51:03 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/15 10:28:46 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "float_limits.h"

t_shape	cylinder(size_t id)
{
	return ((t_shape){.type = CYLINDER,
			.local_transformation = identity_matrix(3),
			.final_transformation = identity_matrix(3),
			.final_inverted = identity_matrix(4),
			.material = material(),
			.parent = NULL,
			.cyl_closed = 0,
			.cyl_min = -DBL_MAX,
			.cyl_max = DBL_MAX,
			.id = id});
}
