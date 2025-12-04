/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:53:09 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/04 12:00:40 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"
#include "libft.h"

int	vec_delete_index(void **vec, size_t index)
{
	t_vector_head * const	header = vec_get_header(*vec);
	void				*dest;

	if (index >= header->nb_elems)
	{
		return (1);
	}
	dest = *vec + header->el_size * index;
	ft_memmove(dest, dest + header->el_size, header->el_size * (header->nb_elems - index - 1));
	--header->nb_elems;
	return (0);
}
