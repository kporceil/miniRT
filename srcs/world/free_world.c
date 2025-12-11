/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:49:08 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/09 15:23:25 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "world.h"
#include "groups.h"
#include "scenes_parsing.h"
#include <stdlib.h>

static void	free_cube_texture(t_shape *cu)
{
	free(cu->material.pat.faces[0].file.canva);
	free(cu->material.pat.faces[1].file.canva);
	free(cu->material.pat.faces[2].file.canva);
	free(cu->material.pat.faces[3].file.canva);
	free(cu->material.pat.faces[4].file.canva);
	free(cu->material.pat.faces[5].file.canva);
}

void	free_world(t_world *w)
{
	size_t	i;

	i = 0;
	while (i < w->objs_count)
	{
		if (w->objs[i].type == GROUP)
			free_group(w->objs + i);
		if (w->objs[i].material.pat.type == UV
			&& w->objs[i].material.pat.uvpat.type == IMAGE)
			free(w->objs[i].material.pat.uvpat.file.canva);
		if (w->objs[i].material.pat.type == CUBE_UV
			&& w->objs[i].material.pat.faces->type == IMAGE)
			free_cube_texture(w->objs + i);
		if (w->objs[i].material.normal_map.type != NO)
			free(w->objs[i].material.normal_map.uvpat.file.canva);
		++i;
	}
	free_light_list(w);
	free_shape_list(w);
	free(w->objs);
	free(w->lights);
	free(w->buf_inter);
}
