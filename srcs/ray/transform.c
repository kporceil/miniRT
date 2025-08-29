/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 23:31:42 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/28 23:32:56 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "matrix.h"

t_ray	ray_transform(t_ray r, t_matrix m)
{
	return ((t_ray){matrix_tuple_mult(m, r.origin),
			matrix_tuple_mult(m, r.direction)});
}
