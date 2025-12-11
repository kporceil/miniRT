/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_children.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:37:38 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/08 17:58:55 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bounding_box.h"
#include "groups.h"
#include "uid.h"

static int	init_partitioning(size_t group_size, t_shape *left, t_shape *right)
{
	*left = group(generate_uid(), group_size);
	if (!left->child)
	{
		return (1);
	}
	*right = group(generate_uid(), group_size);
	if (!right->child)
	{
		free_group(left);
		return (1);
	}
	return (0);
}

int	partition_children(t_shape *g)
{
	t_shape			left_g;
	t_shape			right_g;
	size_t			i;

	if (init_partitioning(g->nb_members / 2, &left_g, &right_g))
		return (1);
	bb_split_bounds(g->group_bbox, &left_g.group_bbox, &right_g.group_bbox);
	i = 0;
	while (i < g->nb_members)
	{
		if (bb_contains_box(left_g.group_bbox, bb_parent_space_bounds_of(g->child + i)))
		{
			group_add_shape(&left_g, g->child[i]);
			group_delete_index(g, i);
		}
		else if (bb_contains_box(right_g.group_bbox, bb_parent_space_bounds_of(g->child + i)))
		{
			group_add_shape(&right_g, g->child[i]);
			group_delete_index(g, i);
		}
		else
			++i;
	}
	group_add_shape(g, left_g);
	group_add_shape(g, right_g);
	return (0);
}
