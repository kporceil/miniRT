/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_group.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 19:30:10 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/20 20:34:24 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "obj_parser.h"
#include "vectors.h"
#include "uid.h"

// NOTE: this implementation doesnt allow to re-call an already existing group
// since it doesnt keep track of names

void	change_group(t_obj_parsing *p)
{
	t_shape	new_group;

	new_group = group(generate_uid(), DEFAULT_GROUP_MEMBER_SIZE);
	if (vec_add((void **)&p->groups, &new_group))
		p->status = MALLOC_ERROR;
	else
		p->current_group = p->groups + (vec_get_header(p->groups)->nb_elems - 1);
}
