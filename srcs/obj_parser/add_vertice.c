/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vertice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:23:12 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/20 16:15:00 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "obj_parser.h"
#include "tuples.h"
#include "vectors.h"

void	add_vertice(char **args, t_obj_parsing *p)
{
	size_t	i;
	t_tuple	new_vertice;

	i = 0;
	while (args[i] && i < 4)
	{
		if (i == 0)
			new_vertice.x = ft_atof(args[i]);
		else if (i == 1)
			new_vertice.y = ft_atof(args[i]);
		else if (i == 2)
			new_vertice.z = ft_atof(args[i]);
		else if (i == 3)
			new_vertice.w = ft_atof(args[i]);
		++i;
	}
	if (i == 3)
		new_vertice.w = 1;
	if (vec_add((void **)&p->vertices, &new_vertice))
		p->status = MALLOC_ERROR;
}
