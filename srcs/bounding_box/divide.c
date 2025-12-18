/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:39:43 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/09 15:46:55 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bounding_box.h"

int	divide(t_shape *g, size_t threshold)
{
	size_t	i;

	if (g == NULL)
		return (0);
	if (g->type == GROUP)
	{
		if (g->nb_members >= threshold)
		{
			if (partition_children(g))
				return (1);
		}
		i = 0;
		while (i < g->nb_members)
		{
			if (divide(g->child + i, threshold))
				return (1);
			++i;
		}
	}
	return (0);
}
