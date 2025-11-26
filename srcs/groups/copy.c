/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:05:59 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/26 13:46:55 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"
#include "uid.h"
#include "libft.h"

static t_shape	shape_copy(t_shape *src)
{
	t_shape	ret;
	
	ft_memcpy(&ret, src, sizeof(t_shape));
	ret.id = generate_uid();
	return (ret);
}

t_shape	group_copy(t_shape *src)
{
	t_shape	ret;
	t_shape	current;
	size_t	i;

	ret = group(generate_uid(), src->nb_members);
	if (!ret.child)
		return (ret);
	i = 0;
	while (i < src->nb_members)
	{
		if (src->child[i].type == GROUP)
		{
			current = group_copy(src->child + i);
			if (!current.child)
				free_group(&ret);
			if (!current.child)
				return (current);
		}
		else
			current = shape_copy(src->child + i);
		if (group_add_shape(&ret, current))
			return ((t_shape){.child = NULL});
		++i;
	}
	return (ret);
}
