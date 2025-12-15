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

static void	fix_parent_pointers(t_shape *g)
{
	size_t	i;

	i = 0;
	while (i < g->nb_members)
	{
		g->child[i].parent = g;
		++i;
	}
}

static int	place_childrens(t_shape *left, t_shape *right, t_shape *g)
{
	size_t	i;

	i = 0;
	while (i < g->nb_members)
	{
		if (bb_contains_box(left->group_bbox,
				bb_parent_space_bounds_of(g->child + i)))
		{
			if (group_add_shape(left, g->child[i]))
				return (1);
			group_delete_index(g, i);
		}
		else if (bb_contains_box(right->group_bbox,
				bb_parent_space_bounds_of(g->child + i)))
		{
			if (group_add_shape(right, g->child[i]))
				return (1);
			group_delete_index(g, i);
		}
		else
			++i;
	}
	return (0);
}

int	partition_children(t_shape *g)
{
	t_shape			left_g;
	t_shape			right_g;

	if (init_partitioning(g->nb_members / 2, &left_g, &right_g))
		return (1);
	bb_split_bounds(g->group_bbox, &left_g.group_bbox, &right_g.group_bbox);
	if (place_childrens(&left_g, &right_g, g))
		return (1);
	if (group_add_shape(g, left_g))
		return (1);
	if (group_add_shape(g, right_g))
		return (1);
	fix_parent_pointers(&g->child[g->nb_members - 2]);
	fix_parent_pointers(&g->child[g->nb_members - 1]);
	return (0);
}
