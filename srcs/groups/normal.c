/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:27:30 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/16 15:05:42 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "matrix.h"
#include "tuples.h"

t_tuple	world_to_object(t_shape *s, t_tuple p)
{
	if (s->parent)
	{
		p = world_to_object(s->parent, p);
	}
	return (matrix_tuple_mult(s->inverted, p));
}

t_tuple	normal_to_world(t_shape *s, t_tuple n)
{
	n = matrix_tuple_mult(matrix_transpose(s->inverted), n);
	n.w = 0;
	n = normalize(n);
	if (s->parent)
		n = normal_to_world(s->parent, n);
	return (n);
}
