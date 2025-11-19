/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:48:44 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/19 15:20:08 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "vectors.h"

int	vec_add(void **vector, void *el)
{
	t_vector_head	*head;
	void			*copy;
	
	head = vec_get_header(*vector);
	++head->nb_elems;
	if (head->nb_elems > head->max_elems)
	{
		copy = malloc(head->vector_size * GROWTH_COEF + sizeof(t_vector_head));
		if (!copy)
			return (1);
		((t_vector_head *)copy)->vector_size = head->vector_size * GROWTH_COEF;
		((t_vector_head *)copy)->max_elems = head->max_elems * GROWTH_COEF;
		((t_vector_head *)copy)->nb_elems = head->nb_elems;
		((t_vector_head *)copy)->el_size = head->el_size;
		ft_memcpy((t_vector_head *)copy + 1, *vector, head->vector_size);
		*vector = ((void *)(&(((t_vector_head *)copy)[1])));
		free(head);
		head = copy;
	}
	ft_memcpy(*vector + (head->nb_elems - 1) * head->el_size, el, head->el_size);
	return (0);
}
