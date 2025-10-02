/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:51:03 by kporceil          #+#    #+#             */
/*   Updated: 2025/09/30 12:41:22 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include <float.h>

t_shape	cylinder(size_t id)
{
	return ((t_shape){CYLINDER, identity_matrix(3), identity_matrix(4),
		material(), -DBL_MAX, DBL_MAX, id});
}
