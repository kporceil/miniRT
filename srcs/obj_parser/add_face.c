/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_face.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:25:14 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/28 21:48:24 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "obj_parser.h"
#include "shape.h"
#include "uid.h"
#include "vectors.h"

static size_t	args_len(char **args)
{
	size_t	ret;

	ret = 0;
	while (args[ret])
	{
		++ret;
	}
	return (ret);
}

//static void	init_first_vertice(char *str, int *v1, t_obj_parsing *p, size_t const nb_vertices)
//{
//	if (ft_atoi(str, v1))
//		p->status = FILE_INVALID_VERTICE;
//	else if (*v1 <= 0)
//		p->status = FILE_NEGATIVE_VERTICE;
//	else if ((size_t)*v1 > nb_vertices)
//		p->status = FILE_NONEXISTANT_VERTICE;
//}
//
//static void	add_polygon(char **args, t_obj_parsing *p, size_t len)
//{
//	int				v1;
//	int				v2;
//	int				v3;
//	size_t			i;
//	size_t const	nb_vertices = vec_get_header(p->vertices)->nb_elems;
//
//	init_first_vertice(args[0], &v1, p, nb_vertices);
//	i = 1;
//	while (i < nb_vertices && i + 1 < len && !p->status)
//	{
//		if (ft_atoi(args[i], &v2) || ft_atoi(args[i + 1], &v3))
//			p->status = FILE_INVALID_VERTICE;
//		else if (v2 <= 0 || v3 <= 0)
//			p->status = FILE_NEGATIVE_VERTICE;
//		else if ((size_t)v2 > nb_vertices || (size_t)v3 > nb_vertices)
//			p->status = FILE_NONEXISTANT_VERTICE;
//		if (p->status)
//			return ;
//		if (group_add_shape(p->current_group, triangle(generate_uid(),
//												p->vertices[v1 - 1],
//												p->vertices[v2 - 1],
//												p->vertices[v3 - 1])))
//			p->status = MALLOC_ERROR;
//		++i;
//	}
//}
//
//void	add_face(char **args, t_obj_parsing *p)
//{
//	size_t const	len = args_len(args);
//
//	if (len >= 3)
//		add_polygon(args, p, len);
//	else
//		++p->ignored;
//}

static void	add_polygon(char **args, unsigned long v1, t_obj_parsing *p, size_t len)
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

// NOTE: check only for vertice and normal since texture isnt implemented

static t_vertice_data	parse_vertice_data(char *s, t_obj_parsing *p)
{
	t_vertice_data	v;

	v = (t_vertice_data){0};
	v.vertice = ft_strtoul(s, &s, 10);
	if (*s)
		v.texture = ft_strtoul(s + 1, &s, 10);
	if (*s)
		v.normal = ft_strtoul(s + 1, &s, 10);
	if (v.vertice > vec_get_header(p->vertices)->nb_elems && v.normal > vec_get_header(p->normals)->nb_elems)
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

static void	add_smooth_polygon(char **args, t_vertice_data v1, t_obj_parsing *p, size_t len)
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

void	add_face(char **args, t_obj_parsing *p)
{
	size_t const	len = args_len(args);
	t_vertice_data	v1;

	if (len >= 3)
	{
		v1 = parse_vertice_data(*args, p);
		if (!p->status)
		{
			if (v1.normal)
				add_smooth_polygon(args, v1, p, len);
			else
				add_polygon(args, v1.vertice, p, len);

		}
		else
			++p->ignored;
	}
	else
		++p->ignored;
}
