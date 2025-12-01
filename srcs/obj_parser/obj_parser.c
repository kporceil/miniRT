/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:45:41 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/28 20:57:04 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "obj_parser.h"
#include "get_next_line.h"
#include "shape.h"
#include "vectors.h"
#include "groups.h"
#include "uid.h"

static void	init_obj_parsing(t_obj_parsing *p)
{
	t_shape	default_group;

	p->groups = vec_create(sizeof(t_shape), DEFAULT_GROUP_SIZE);
	if (p->groups)
	{
		default_group = group(generate_uid(), DEFAULT_GROUP_MEMBER_SIZE);
		if (default_group.child && !vec_add((void **)&p->groups,
				&default_group))
		{
			p->current_group = p->groups;
			p->vertices = vec_create(sizeof(t_tuple), DEFAULT_VERTICES_SIZE);
			if (p->vertices)
			{
				p->normals = vec_create(sizeof(t_tuple), DEFAULT_NORMALS_SIZE);
				if (p->normals)
					return ;
				vec_free(p->vertices);
			}
			vec_free(p->groups->child);
		}
		vec_free(p->groups);
	}
	p->status = MALLOC_ERROR;
}

static void	parse_obj_file(int fd, t_obj_parsing *p)
{
	char	*line;

	line = get_next_line(fd, READ);
	while (line)
	{
		parse_obj_line(line, p);
		free(line);
		if (p->status)
		{
			get_next_line(fd, DELETE);
			return ;
		}
		line = get_next_line(fd, READ);
	}
}

t_obj_parsing	obj_parser(char *path)
{
	t_obj_parsing	ret;
	int				fd;

	ret = (t_obj_parsing){0};
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return ((t_obj_parsing){.status = OPEN_ERROR});
	init_obj_parsing(&ret);
	if (!ret.status)
	{
		parse_obj_file(fd, &ret);
	}
	close(fd);
	return (ret);
}
