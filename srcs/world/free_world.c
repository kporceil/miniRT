/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:49:08 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/19 19:13:32 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "world.h"
#include "groups.h"
#include "vectors.h"
#include <stdlib.h>

void	free_world(t_world *w)
{
	size_t	i;

	i = 0;
	while (i < w->objs_count)
	{
		if (w->objs[i].type == GROUP)
			free_group(w->objs + i);
		++i;
	}
	free(w->objs);
	free(w->lights);
	free(w->buf_inter);
}
