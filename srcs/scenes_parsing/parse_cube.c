/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cube.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:48:41 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/27 16:48:52 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "libft.h"
#include "scenes_parsing.h"
#include <stdlib.h>

static int	parse_mandatory_value(char *file, char **endptr, t_shape *cu)
{
	t_tuple	pos;
	t_tuple	dir;
	t_tuple	scale;
	t_color	rgb;

	if (parse_point(file, endptr, &pos) == -1)
		return (-1);
	file = *endptr;
	if (parse_normalized_vector(file, endptr, &dir) == -1)
		return (-1);
	file = *endptr;
	if (parse_point(file, endptr, &scale) == -1)
		return (-1);
	file = *endptr;
	if (parse_color(file, endptr, &rgb) == -1)
		return (-1);
	*endptr = skip_space(*endptr);
	shape_set_matrix(cu, matrix_mult(object_orientation(pos, dir,
				vector(0, 1, 0)), matrix_scaling(scale.x, scale.y, scale.z)));
	if (fabs(dir.y) > 0.9)
		shape_set_matrix(cu, matrix_mult(object_orientation(pos, dir,
					vector(1, 0, 0)), matrix_scaling(scale.x,
					scale.y, scale.z)));
	cu->material.color = rgb;
	return (0);
}

static int	parse_pattern(char *file, t_shape *cu)
{
	t_uvpat const	pat = uv_checkers(8, 8, cu->material.color, color(1, 1, 1));
	size_t			i;
	char			backup;

	if (ft_strncmp("checker", file, 7) == 0)
		cu->material.pat = cube_pattern((t_uvpat[6]){pat, pat, pat, pat, pat,
				pat});
	else if (*file == 'T')
	{
		++file;
		i = 0;
		while (!ft_isspace(file[i]))
			++i;
		backup = file[i];
		file[i] = '\0';
		if (parse_cube_texture_map(file, cu) == -1)
		{
			file[i] = backup;
			return (-1);
		}
		file[i] = backup;
	}
	return (0);
}

static int	parse_bonus_value(char *file, char **endptr, t_shape *cu)
{
	cu->material.reflective = ft_strtod(file, endptr);
	cu->material.transparency = ft_strtod(*endptr, endptr);
	cu->material.refractive_index = ft_strtod(*endptr, endptr);
	file = skip_space(*endptr);
	if (*file != '\0')
	{
		if (parse_pattern(file, cu) == -1)
			return (-1);
	}
	while (*file && !ft_isspace(*file))
		++file;
	file = skip_space(file);
	if (*file == 'S')
	{
		set_skybox_params(cu);
		++file;
	}
	if (*skip_space(file) != '\0')
	{
		if (cu->material.pat.type == CUBE_UV)
			free_cube_textures(cu->material.pat.faces, 6);
		return (-1);
	}
	return (0);
}

static int	parse_cube_value(char *file, t_world *world)
{
	t_shape	cu;
	char	*endptr;

	cu = cube(get_shape_id(world));
	if (parse_mandatory_value(file, &endptr, &cu) == -1)
		return (-1);
	file = endptr;
	if (*file != '\0' && parse_bonus_value(file, &endptr, &cu) == -1)
		return (-1);
	if (new_shape_node(world, &cu) == -1)
		return (-1);
	return (0);
}

int	parse_cube(char *file, t_world *world)
{
	if (parse_cube_value(file, world) == -1)
		return (-1);
	++world->objs_count;
	return (0);
}
