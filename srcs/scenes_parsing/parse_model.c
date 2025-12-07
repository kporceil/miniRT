/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_model.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 00:28:13 by kporceil          #+#    #+#             */
/*   Updated: 2025/12/07 00:30:28 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "obj_parser.h"
#include "world.h"
#include "libft.h"
#include "scenes_parsing.h"
#include <stdlib.h>

#define REFL_ATTR 1
#define TRANSP_ATTR 2
#define REFR_ATTR 3

static  void	set_group_color(t_shape *group, t_color rgb)
{
	size_t	i;

	if  (group->type == GROUP)
	{
		i = 0;
		while (i < group->nb_members)
		{
			set_group_color(group->child + i, rgb);
			++i;
		}
		return ;
	}
	group->material.color = rgb;
}

static  void	set_group_attribute(t_shape *group, double value, int attribute)
{
	size_t	i;

	if  (group->type == GROUP)
	{
		i = 0;
		while (i < group->nb_members)
		{
			set_group_attribute(group->child + i, value, attribute);
			++i;
		}
		return ;
	}
	if (attribute == REFL_ATTR)
		group->material.reflective = value;
	else if (attribute == TRANSP_ATTR)
		group->material.transparency = value;
	else if (attribute == REFR_ATTR)
		group->material.refractive_index = value;
}

static int	parse_mandatory_value(char *file, char **endptr, t_shape *ob)
{
	t_tuple	pos;
	t_tuple	dir;
	t_tuple	scale;
	t_color	rgb;

	if (parse_point(file, endptr, &pos) == -1)
		return (-1);
	file = *endptr;
	if (parse_vector(file, endptr, &dir) == -1)
		return (-1);
	file = *endptr;
	if (parse_point(file, endptr, &scale) == -1)
		return (-1);
	file = *endptr;
	if (parse_color(file, endptr, &rgb) == -1)
		return (-1);
	*endptr = skip_space(*endptr);
	dir = tuple_scalar_mult(dir, M_PI / 180);
	shape_set_matrix(ob, matrix_mult(matrix_translation(pos.x, pos.y, pos.z),
			matrix_mult(matrix_xyz_rotation(dir.x, dir.y, dir.z),
				matrix_scaling(scale.x, scale.y, scale.z))));
	set_group_color(ob, rgb);
	return (0);
}

static int	parse_bonus_value(char *file, char **endptr, t_shape *ob)
{
	set_group_attribute(ob, ft_strtod(file, endptr), REFL_ATTR);
	set_group_attribute(ob, ft_strtod(*endptr, endptr), TRANSP_ATTR);
	set_group_attribute(ob, ft_strtod(*endptr, endptr), REFR_ATTR);
	if (*skip_space(*endptr) != '\0')
		return (-1);
	return (0);
}

static int	parse_model_value(char *file, t_world *world)
{
	t_shape			model;
	char			*endptr;
	size_t			i;
	char			backup;
	t_obj_parsing	p;

	file = skip_space(file);
	i = 0;
	while (file[i] && !ft_isspace(file[i]))
		++i;
	backup = file[i];
	file[i] = '\0';
	p = obj_parser(file);
	model = parsed_to_group(&p);
	free_obj_parsing(&p);
	file[i] = backup;
	file += i;
	if (parse_mandatory_value(file, &endptr, &model) == -1)
		return (-1);
	file = endptr;
	if (*file != '\0' && parse_bonus_value(file, &endptr, &model) == -1)
		return (-1);
	if (new_shape_node(world, &model) == -1)
		return (-1);
	return (0);
}

int	parse_model(char *file, t_world *world)
{
	if (parse_model_value(file, world) == -1)
		return (-1);
	++world->objs_count;
	return (0);
}
