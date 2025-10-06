/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:51:03 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/02 16:21:47 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include <float.h>

t_shape	cone(size_t id)
{
	return ((t_shape){CONE, identity_matrix(3), identity_matrix(4),
		material(), 0, -DBL_MAX, DBL_MAX, id});
}
