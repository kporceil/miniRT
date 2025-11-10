/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_set_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:49:13 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/23 15:38:30 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "groups.h"

void	shape_set_matrix(t_shape *s, t_matrix m)
{
	if (s->type == GROUP)
		return (group_set_matrix(s, m));
	s->local_transformation = m;
	if (s->parent)
	{
		m = matrix_mult(s->parent->final_transformation, m);
	}
	s->final_transformation = m;
	s->final_inverted = m;
	if (is_matrix_invertible(m))
		s->final_inverted = matrix_invert(m);
}
