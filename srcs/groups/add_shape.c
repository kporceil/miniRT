/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:44:21 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/23 15:39:10 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "groups.h"
#include "vectors.h"

int	group_add_shape(t_shape *g, t_shape s)
{
	if (g->nb_members == g->group_size)
		return (1);
	s.parent = g;
	if (s.type == GROUP)
		group_set_matrix(&s, s.local_transformation);
	else
		shape_set_matrix(&s, s.local_transformation);
	vec_add((void **)&g->child, &s);
	//g->child[g->nb_members] = s;
	++g->nb_members;
	return (0);
}
