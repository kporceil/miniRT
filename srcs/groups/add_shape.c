/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:44:21 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/20 16:13:03 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "groups.h"
#include "vectors.h"

int	group_add_shape(t_shape *g, t_shape s)
{
	t_vector_head	*head;

	s.parent = g;
	if (s.type == GROUP)
		group_set_matrix(&s, s.local_transformation);
	else
		shape_set_matrix(&s, s.local_transformation);
	if (vec_add((void **)&g->child, &s))
		return (1);
	head = vec_get_header(g->child);
	g->nb_members = head->nb_elems;
	g->group_size = head->max_elems;
	return (0);
}
