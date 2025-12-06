/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:37:36 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/19 14:43:29 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vectors.h"

void	*vec_create(size_t el_size, size_t max_elems)
{
	void			*ret;
	size_t const	vec_size = el_size * max_elems;

	ret = malloc(vec_size + sizeof(t_vector_head));
	if (!ret)
		return (NULL);
	((t_vector_head *)ret)->nb_elems = 0;
	((t_vector_head *)ret)->max_elems = max_elems;
	((t_vector_head *)ret)->vector_size = vec_size;
	((t_vector_head *)ret)->el_size = el_size;
	return ((void *)(&(((t_vector_head *)ret)[1])));
}
