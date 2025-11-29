/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_face.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:25:14 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/29 18:41:30 by lcesbron         ###   ########lyon.fr   */
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
