/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cube_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:00:00 by kporceil          #+#    #+#             */
/*   Updated: 2025/12/05 10:00:00 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "libft.h"
#include "scenes_parsing.h"
#include <stdlib.h>

static int	load_cube_face(char *dir, char *face_name, t_uvpat *uvpat)
{
	char	*path;
	size_t	dir_len;
	size_t	face_len;
	t_canva	texture;

	dir_len = ft_strlen(dir);
	face_len = ft_strlen(face_name);
	path = malloc(dir_len + face_len + 2);
	if (!path)
		return (-1);
	ft_strlcpy(path, dir, dir_len + 1);
	if (dir[dir_len - 1] != '/')
		ft_strlcat(path, "/", dir_len + 2);
	ft_strlcat(path, face_name, dir_len + face_len + 2);
	texture = ppm_to_canva(path);
	free(path);
	if (texture.canva == NULL)
		return (-1);
	*uvpat = uv_image(texture);
	return (0);
}

void	set_skybox_params(t_shape *cu)
{
	cu->skybox = true;
	cu->material.diffuse = 0;
	cu->material.specular = 0;
}

void	free_cube_textures(t_uvpat faces[6], int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (faces[i].file.canva)
			free(faces[i].file.canva);
		++i;
	}
}

int	parse_cube_texture_map(char *dir, t_shape *cu)
{
	t_uvpat		faces[6];
	const char	*face_names[6] = {"posz.ppm", "negz.ppm", "posx.ppm",
		"negx.ppm", "posy.ppm", "negy.ppm"};
	int			i;

	i = 0;
	while (i < 6)
	{
		if (load_cube_face(dir, (char *)face_names[i], faces + i) == -1)
		{
			free_cube_textures(faces, i);
			return (-1);
		}
		++i;
	}
	cu->material.pat = cube_pattern(faces);
	return (0);
}
