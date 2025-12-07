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

static int	parse_mandatory_value(char *file, char **endptr, t_shape *ob)
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
	shape_set_matrix(ob, matrix_mult(object_orientation(pos, dir,
				vector(0, 1, 0)), matrix_scaling(scale.x, scale.y, scale.z)));
	if (fabs(dir.y) > 0.9)
		shape_set_matrix(ob, matrix_mult(object_orientation(pos, dir,
					vector(1, 0, 0)), matrix_scaling(scale.x,
					scale.y, scale.z)));
	ob->material.color = rgb;
	return (0);
}

static int	parse_bonus_value(char *file, char **endptr, t_shape *ob)
{
	ob->material.reflective = ft_strtod(file, endptr);
	ob->material.transparency = ft_strtod(*endptr, endptr);
	ob->material.refractive_index = ft_strtod(*endptr, endptr);
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
