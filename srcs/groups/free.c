/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:12:35 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/19 19:12:57 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"
#include "groups.h"

void	free_group(t_shape *g)
{
	size_t	i;

	i = 0;
	while (i < g->nb_members)
	{
		if (g->child[i].type == GROUP)
			free_group(g->child + i);
		++i;
	}
	vec_free(g->child);
}
