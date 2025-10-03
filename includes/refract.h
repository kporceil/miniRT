/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refract.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:27:23 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/02 17:31:24 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef REFRACT_H
# define REFRACT_H

# include "ray.h"

typedef struct s_objlist
{
	t_shape				*obj;
	struct s_objlist	*next;
}				t_objlist;

typedef struct s_lstbuf
{
	t_objlist	*lst;
	size_t		size;
	size_t		taken;
}				t_lstbuf;

void		find_nx(t_precomp *comps, t_inter hit, t_intersections xs);
t_lstbuf	init_list(size_t size);
void		insert_or_delete_inter(t_lstbuf mem, t_objlist **first, t_objlist **last, t_inter *inter);

#endif
