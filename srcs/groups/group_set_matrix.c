/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_set_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:45:19 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/20 18:42:35 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "matrix.h"

static void	reset_group_matrix(t_shape *g)
{
	size_t	i;

	i = 0;
	while (i < g->group_size)
	{
		if (g->child[i].type == GROUP)
			reset_group_matrix(g->child + i);
		else
			shape_set_matrix(g->child + i, matrix_mult(g->child[i].transformation, g->inverted));
			//shape_set_matrix(g->child + i, matrix_mult(g->inverted,g->child[i].transformation));
		++i;
	}
}

static void	group_member_shape_set_matrix(t_shape *s, t_matrix m)
{
	s->transformation = m;
	s->inverted = m;
	if (is_matrix_invertible(m))
		s->inverted = matrix_invert(m);
}

static void	group_member_group_set_matrix(t_shape *g, t_matrix m)
{
	size_t	i;

	//if (matrix_compare(g->transformation, identity_matrix(4)))
		//reset_group_matrix(g);
	g->transformation = m;
	g->inverted = m;
	if (is_matrix_invertible(m))
		g->inverted = matrix_invert(m);
	i = 0;
	while (i < g->group_size)
	{
		if (g->child[i].type == GROUP)
			group_member_group_set_matrix(g->child + i, matrix_mult(m, g->child[i].transformation));
			//group_member_group_set_matrix(g->child + i, matrix_mult(g->child[i].transformation, m));
		else
			group_member_shape_set_matrix(g->child + i, matrix_mult(m, g->child[i].transformation));
			//group_member_shape_set_matrix(g->child + i, matrix_mult(g->child[i].transformation, m));
		++i;
	}
}

void	group_set_matrix(t_shape *g, t_matrix m)
{
	size_t	i;

	if (matrix_compare(g->transformation, identity_matrix(4)))
		reset_group_matrix(g);
	if (g->parent)
		m = matrix_mult(m, g->parent->transformation);
	g->transformation = m;
	g->inverted = m;
	if (is_matrix_invertible(m))
		g->inverted = matrix_invert(m);
	i = 0;
	while (i < g->group_size)
	{
		if (g->child[i].type == GROUP)
			//group_set_matrix(g->child + i, matrix_mult(m, g->child[i].transformation));
			group_member_group_set_matrix(g->child + i, matrix_mult(g->child[i].transformation, m));
		else
			//shape_set_matrix(g->child + i, matrix_mult(m, g->child[i].transformation));
			group_member_shape_set_matrix(g->child + i, matrix_mult(g->child[i].transformation, m));
		++i;
	}
}
