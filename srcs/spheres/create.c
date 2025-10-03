/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:51:03 by kporceil          #+#    #+#             */
/*   Updated: 2025/09/30 19:02:04 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

t_shape	sphere(size_t id)
{
	return ((t_shape){SPHERE, identity_matrix(4), identity_matrix(4),
		material(), id});
}
