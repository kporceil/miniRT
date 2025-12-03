/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vertice_normal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:23:12 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/28 21:04:17 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "obj_parser.h"
#include "tuples.h"
#include "vectors.h"

void	add_vertice_normal(char **args, t_obj_parsing *p)
{
	size_t	i;
	t_tuple	new_vertice_normal;

	i = 0;
	while (args[i] && i < 4)
	{
		if (i == 0)
			new_vertice_normal.x = ft_atof(args[i]);
		else if (i == 1)
			new_vertice_normal.y = ft_atof(args[i]);
		else if (i == 2)
			new_vertice_normal.z = ft_atof(args[i]);
		else if (i == 3)
			new_vertice_normal.w = ft_atof(args[i]);
		++i;
	}
	if (i == 3)
		new_vertice_normal.w = 0;
	if (vec_add((void **)&p->normals, &new_vertice_normal))
		p->status = MALLOC_ERROR;
}
