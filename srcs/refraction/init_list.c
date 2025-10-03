/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:32:12 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/02 17:32:28 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "refract.h"
#include <stdlib.h>
#include <unistd.h>

t_lstbuf	init_list(size_t size)
{
	t_objlist	*lst;
	size_t		i;
	
	lst = malloc(sizeof(t_objlist) * size);
	if (!lst)
		write(2, "Malloc error: not enough memory for refraction\n", 47);
	else
	{
		i = 0;
		while (i < size)
		{
			lst[i].next = NULL;
			lst[i].obj = NULL;
			++i;
		}
	}
	return ((t_lstbuf){lst, size, 0});
}
