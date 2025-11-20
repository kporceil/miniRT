/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_face.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:25:14 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/20 18:35:01 by lcesbron         ###   ########lyon.fr   */
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

//static void	add_triangle(char **args, t_obj_parsing *p)
//{
//	int				v1;
//	int				v2;
//	int				v3;
//	size_t const	nb_vertices = vec_get_header(p->vertices)->nb_elems;
//
//	if (ft_atoi(args[0], &v1) || ft_atoi(args[1], &v2) || ft_atoi(args[2], &v3))
//	{
//		p->status = FILE_INVALID_VERTICE;
//		return ;
//	}
//	if (v1 <= 0 || v2 <= 0 || v3 <= 0)
//	{
//		p->status = FILE_NEGATIVE_VERTICE;
//		return ;
//	}
//	if ((size_t)v1 > nb_vertices || (size_t)v2 > nb_vertices || (size_t)v3 > nb_vertices)
//	{
//		p->status = FILE_NONEXISTANT_VERTICE;
//		return ;
//	}
//	if (group_add_shape(p->current_group, triangle(generate_uid(),
//											p->vertices[v1 - 1],
//											p->vertices[v2 - 1],
//											p->vertices[v3 - 1])))
//		p->status = MALLOC_ERROR;
//}

static void	init_first_vertice(char *str, int *v1, t_obj_parsing *p, size_t const nb_vertices)
{
	if (ft_atoi(str, v1))
		p->status = FILE_INVALID_VERTICE;
	else if (*v1 <= 0)
		p->status = FILE_NEGATIVE_VERTICE;
	else if ((size_t)*v1 > nb_vertices)
		p->status = FILE_NONEXISTANT_VERTICE;
}

static void	add_polygon(char **args, t_obj_parsing *p, size_t len)
{
	int				v1;
	int				v2;
	int				v3;
	size_t			i;
	size_t const	nb_vertices = vec_get_header(p->vertices)->nb_elems;

	init_first_vertice(args[0], &v1, p, nb_vertices);
	i = 1;
	while (i < nb_vertices && i + 1 < len && !p->status)
	{
		if (ft_atoi(args[i], &v2) || ft_atoi(args[i + 1], &v3))
			p->status = FILE_INVALID_VERTICE;
		else if (v2 <= 0 || v3 <= 0)
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

void	add_face(char **args, t_obj_parsing *p)
{
	size_t const	len = args_len(args);

	if (len >= 3)
		add_polygon(args, p, len);
	else
		++p->ignored;
}
