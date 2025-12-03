/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_children.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:37:38 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/03 15:29:06 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bounding_box.h"

void	partition_children(t_shape *group)
{
	t_bounding_box	left;
	t_bounding_box	right;
	size_t			i;

	bb_split_bounds(g->group_bbox, &left, &right);
	i = 0;
	while ()
}
