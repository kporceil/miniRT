/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:09:25 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/19 19:20:00 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "obj_parser.h"
#include "vectors.h"

void	free_obj_parsing(t_obj_parsing *p)
{
	size_t const	nb_groups = vec_get_header(p->groups)->nb_elems;
	size_t			i;

	i = 0;
	while (i < nb_groups)
	{
		free_group(p->groups + i);
		++i;
	}
	vec_free(p->vertices);
	vec_free(p->normals);
	vec_free(p->groups);
}
