/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_set_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:49:13 by kporceil          #+#    #+#             */
/*   Updated: 2025/09/12 13:39:01 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

void	shape_set_matrix(t_shape *s, t_matrix m)
{
	s->transformation = m;
	s->inverted = m;
	if (is_matrix_invertible(m))
		s->inverted = matrix_invert(m);
}
