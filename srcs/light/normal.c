/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:31:22 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/29 20:52:54 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "tuples.h"
#include "spheres.h"

t_tuple	normal_at(t_sphere s, t_tuple p)
{
	t_tuple	object_normal;
	t_tuple	object_point;
	t_tuple	normal;

	object_point = matrix_tuple_mult(s.inverted, p);
	object_normal = tuple_substract(object_point, point(0, 0, 0));
	normal = matrix_tuple_mult(matrix_transpose(s.inverted), object_normal);
	normal.w = 0;
	return (normalize(normal));
}
