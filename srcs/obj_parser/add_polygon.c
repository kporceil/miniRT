/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_polygon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 18:37:58 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/29 18:41:14 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shape.h"
#include "groups.h"
#include "vectors.h"
#include "uid.h"
#include "obj_parser.h"

void	add_polygon(char **args, unsigned long v1, t_obj_parsing *p, size_t len)
{
	unsigned long	v2;
	unsigned long	v3;
	size_t			i;
	size_t const	nb_vertices = vec_get_header(p->vertices)->nb_elems;

	i = 1;
	while (i < nb_vertices && i + 1 < len && !p->status)
	{
		v2 = ft_strtoul(args[i], NULL, 10);
		v3 = ft_strtoul(args[i + 1], NULL, 10);
		if (v2 == 0 || v3 == 0)
			p->status = FILE_NEGATIVE_VERTICE;
		else if ((size_t)v2 > nb_vertices || (size_t)v3 > nb_vertices)
			p->status = FILE_NONEXISTANT_VERTICE;
		if (p->status)
			return ;
		if (group_add_shape(p->current_group, triangle(generate_uid(),
					p->vertices[v1 - 1],
					p->vertices[v2 - 1],
					p->vertices[v3 - 1])))
			p->status = MALLOC_ERROR;
		++i;
	}
}
