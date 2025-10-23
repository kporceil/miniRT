/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_set_material.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:30:38 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/23 17:20:38 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

void	group_set_material(t_shape *g, t_material m)
{
	size_t	i;

	g->material = m;
	i = 0;
	while (i < g->nb_members)
	{
		if (g->child[i].type == GROUP)
			group_set_material(g->child + i, m);
		else
			g->child[i].material = m;
		++i;
	}
}
