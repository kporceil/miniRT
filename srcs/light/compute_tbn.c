/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_tbn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:43:06 by kporceil          #+#    #+#             */
/*   Updated: 2025/12/09 13:00:23 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"
#include "shape.h"
#include <math.h>

static void	sphere_tbn(t_tuple o_p, t_tuple o_n, t_tuple *t, t_tuple *b)
{
	*t = vector(-o_p.z, 0.0, o_p.x);
	if (magnitude(*t) < 0.0001)
		*t = vector(1, 0, 0);
	else
		*t = normalize(*t);
	*b = cross(o_n, *t);
	*b = normalize(*b);
}

static void	plane_tbn(t_tuple o_n, t_tuple *t, t_tuple *b)
{
	t_tuple	up;

	if (fabs(o_n.y) > 0.9)
		up = vector(1, 0, 0);
	else
		up = vector(0, 1, 0);
	*t = cross(up, o_n);
	*t = normalize(*t);
	*b = cross(o_n, *t);
	*b = normalize(*b);
}

static void	cylinder_tbn(t_shape *cy, t_tuple o_p, t_tuple o_n, t_tuple *tb[2])
{
	bool	is_cap;

	is_cap = false;
	if (cy->cyl_closed)
	{
		if (fabs(o_p.y - cy->cyl_min) < 0.0001
			|| fabs(o_p.y - cy->cyl_max) < 0.0001)
			is_cap = true;
	}
	if (is_cap)
		plane_tbn(o_n, tb[0], tb[1]);
	else
	{
		*(tb[0]) = vector(-o_p.z, 0.0, o_p.x);
		if (magnitude(*(tb[0])) < 0.0001)
			*(tb[0]) = vector(1, 0, 0);
		else
			*(tb[0]) = normalize(*(tb[0]));
		*(tb[1]) = cross(o_n, *(tb[0]));
		*(tb[1]) = normalize(*(tb[1]));
	}
}

void	compute_tbn(t_shape *sh, t_tuple o_p, t_tuple o_n, t_tuple *tb[2])
{
	if (sh->type == PLANE || sh->type == CUBE)
		plane_tbn(o_n, tb[0], tb[1]);
	else if (sh->type == CYLINDER || sh->type == CONE)
		cylinder_tbn(sh, o_p, o_n, tb);
	else
		sphere_tbn(o_p, o_n, tb[0], tb[1]);
}
