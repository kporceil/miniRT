/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_nx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:26:29 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/02 17:29:52 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "refract.h"
#include <stdlib.h>


static double	set_n(t_objlist *first, t_objlist *last)
{
	if (!first)
		return (1.0);
	return (last->obj->material.refractive_index);
}

void	find_nx(t_precomp *comps, t_inter hit, t_intersections xs)
{
	const t_lstbuf	to_free = init_list(xs.size);
	t_objlist		*first;
	t_objlist		*last;
	size_t			i;

	comps->n1 = 0;
	comps->n2 = 0;
	if (!to_free.lst)
		return ;
	first = NULL;
	last = NULL;
	i = 0;
	while (i < xs.size)
	{
		if (xs.inters[i].point == hit.point && xs.inters[i].s == hit.s)
			comps->n1 = set_n(first, last);
		insert_or_delete_inter(to_free, &first, &last, xs.inters + i);
		if (xs.inters[i].point == hit.point && xs.inters[i].s == hit.s)
			comps->n2 = set_n(first, last);
		++i;
	}
	free(to_free.lst);
	return ;
}
