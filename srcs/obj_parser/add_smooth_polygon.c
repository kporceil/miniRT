/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_smooth_polygon.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 18:29:40 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/29 18:43:01 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "groups.h"
#include "vectors.h"
#include "uid.h"
#include "obj_parser.h"

// NOTE: check only for vertice and normal since texture isnt implemented

t_vertice_data	parse_vertice_data(char *s, t_obj_parsing *p)
{
	t_vertice_data	v;

	v = (t_vertice_data){0};
	v.vertice = ft_strtoul(s, &s, 10);
	if (*s)
		v.texture = ft_strtoul(s + 1, &s, 10);
	if (*s)
		v.normal = ft_strtoul(s + 1, &s, 10);
	if (v.vertice > vec_get_header(p->vertices)->nb_elems
		&& v.normal > vec_get_header(p->normals)->nb_elems)
		p->status = FILE_NONEXISTANT_VERTICE;
	if (v.vertice == 0)
		p->status = FILE_NEGATIVE_VERTICE;
	return (v);
}

static void	fill_points_normals_tabs(t_tuple (*points)[3], t_tuple (*normals)[3], t_obj_parsing *p, t_vertice_data v[2])
{
	(*points)[1] = p->vertices[v[0].vertice - 1];
	(*points)[2] = p->vertices[v[1].vertice - 1];
	(*normals)[1] = p->normals[v[0].normal - 1];
	(*normals)[2] = p->normals[v[1].normal - 1];
}

void	add_smooth_polygon(char **args, t_vertice_data v1, t_obj_parsing *p, size_t len)
{
	t_vertice_data	v[2];
	t_tuple			points[3];
	t_tuple			normals[3];
	size_t			i;
	size_t const	nb_vertices = vec_get_header(p->vertices)->nb_elems;

	i = 1;
	points[0] = p->vertices[v1.vertice - 1];
	normals[0] = p->normals[v1.normal - 1];
	while (i < nb_vertices && i + 1 < len && !p->status)
	{
		v[0] = parse_vertice_data(args[i], p);
		v[1] = parse_vertice_data(args[i + 1], p);
		if (v[0].vertice == 0 || v[1].vertice == 0 || v[0].normal == 0 || v[1].normal == 0)
			p->status = FILE_NEGATIVE_VERTICE;
		else if (v[0].vertice > nb_vertices || v[1].vertice > nb_vertices)
			p->status = FILE_NONEXISTANT_VERTICE;
		if (p->status)
			return ;
		fill_points_normals_tabs(&points, &normals, p, v);
		if (group_add_shape(p->current_group, smooth_triangle(generate_uid(), points, normals)))
			p->status = MALLOC_ERROR;
		++i;
	}
}
