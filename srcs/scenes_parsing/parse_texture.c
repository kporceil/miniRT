/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:00:00 by kporceil          #+#    #+#             */
/*   Updated: 2025/12/09 15:22:13 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scenes_parsing.h"
#include <stdlib.h>

static int	parse_image_pattern(char *file, t_shape *sp, int mode,
			void (*uvmapper)(t_tuple, double *, double *))
{
	size_t	i;
	char	backup;
	t_canva	texture;

	i = 0;
	while (!ft_isspace(file[i]))
		++i;
	backup = file[i];
	file[i] = '\0';
	texture = ppm_to_canva(file);
	if (texture.canva == NULL)
		return (-1);
	file[i] = backup;
	if (mode == 1)
		sp->material.pat = texture_map(uv_image(texture), uvmapper);
	else if (mode == 2)
		sp->material.normal_map = texture_map(uv_image(texture), uvmapper);
	return (0);
}

int	parse_texture(char *file, char **endptr, t_shape *sh,
			void (*uvmapper)(t_tuple, double *, double *))
{
	if (ft_strncmp("checker", file, 7) == 0)
		sh->material.pat = texture_map(uv_checkers(16, 8, sh->material.color,
					color(1, 1, 1)), uvmapper);
	else if (*file == 'T')
	{
		if (parse_image_pattern(file + 1, sh, 1, uvmapper) == -1)
			return (-1);
	}
	if (sh->material.pat.type != NO)
		file = skip_filename(file);
	file = skip_space(file);
	if (*file == 'N')
	{
		if (parse_image_pattern(file + 1, sh, 2, uvmapper) == -1)
		{
			if (sh->material.pat.type == UV
				&& sh->material.pat.uvpat.type == IMAGE)
				free(sh->material.pat.uvpat.file.canva);
			return (-1);
		}
	}
	if (sh->material.normal_map.type != NO)
		file = skip_filename(file);
	*endptr = file;
	return (0);
}
