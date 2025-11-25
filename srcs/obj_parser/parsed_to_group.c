/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsed_to_group.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:24:52 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/25 18:56:58 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"
#include "obj_parser.h"
#include "vectors.h"
#include "uid.h"

t_shape	parsed_to_group(t_obj_parsing *p)
{
	size_t	i;
	size_t	nb_groups;
	t_shape	ret;

	i = 0;
	nb_groups = vec_get_header(p->groups)->nb_elems;
	ret = group(generate_uid(), nb_groups);
	if (!ret.child)
		return ((t_shape){0});
	while (i < nb_groups)
	{
		if (p->groups[i].nb_members)
		{
			group_add_shape(&ret, p->groups[i]);
		}
		++i;
	}
	return (ret);
}
