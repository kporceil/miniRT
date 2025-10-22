/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_set_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:49:13 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/20 20:04:45 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

void	shape_set_matrix(t_shape *s, t_matrix m)
{
	if (s->type == GROUP)
		return (group_set_matrix(s, m));
	if (s->parent)
	{
		m = matrix_mult(m, s->parent->transformation);
		//m = matrix_mult(s->parent->transformation, m);
	}
	s->transformation = m;
	s->inverted = m;
	if (is_matrix_invertible(m))
		s->inverted = matrix_invert(m);
}
