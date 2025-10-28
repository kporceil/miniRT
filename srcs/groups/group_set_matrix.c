/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_set_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:45:19 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/23 15:39:12 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "matrix.h"

static void	group_member_shape_set_matrix(t_shape *s, t_matrix m)
{
	s->final_transformation = m;
	s->final_inverted = m;
	if (is_matrix_invertible(m))
		s->final_inverted = matrix_invert(m);
}

static void	group_member_group_set_matrix(t_shape *g, t_matrix m)
{
	size_t	i;

	g->final_transformation = m;
	g->final_inverted = m;
	if (is_matrix_invertible(m))
		g->final_inverted = matrix_invert(m);
	i = 0;
	while (i < g->nb_members)
	{
		if (g->child[i].type == GROUP)
			group_member_group_set_matrix(g->child + i, matrix_mult(
					m, g->child[i].local_transformation));
		else
			group_member_shape_set_matrix(g->child + i, matrix_mult(
					m, g->child[i].local_transformation));
		++i;
	}
}

void	group_set_matrix(t_shape *g, t_matrix m)
{
	size_t	i;

	g->local_transformation = m;
	if (g->parent)
		m = matrix_mult(g->parent->final_transformation, m);
	g->final_transformation = m;
	g->final_inverted = m;
	if (is_matrix_invertible(m))
		g->final_inverted = matrix_invert(m);
	i = 0;
	while (i < g->nb_members)
	{
		if (g->child[i].type == GROUP)
			group_member_group_set_matrix(g->child + i, matrix_mult(
					m, g->child[i].local_transformation));
		else
			group_member_shape_set_matrix(g->child + i, matrix_mult(
					m, g->child[i].local_transformation));
		++i;
	}
}
