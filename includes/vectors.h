/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:38:50 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/08 11:06:35 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include <stddef.h>

# define GROWTH_COEF 2

typedef struct s_vector_head	t_vector_head;

struct s_vector_head
{
	size_t	vector_size;
	size_t	nb_elems;
	size_t	max_elems;
	size_t	el_size;
};

void			*vec_create(size_t el_size, size_t vec_size);
t_vector_head	*vec_get_header(void *vec);
void			vec_free(void *vec);
int				vec_add(void **vector, void *el);
int				vec_delete_index(void *vec, size_t index);

#endif
