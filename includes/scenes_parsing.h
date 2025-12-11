/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes_parsing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:55:38 by kporceil          #+#    #+#             */
/*   Updated: 2025/12/09 15:15:27 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENES_PARSING_H
# define SCENES_PARSING_H

# include "world.h"
# include "libft.h"

int		parse_file(char *file, t_world *world);
int		parse_line(char *file, t_world *world);
int		parse_cone(char *file, t_world *world);
int		parse_cube(char *file, t_world *world);
int		parse_cylinder(char *file, t_world *world);
int		parse_plane(char *file, t_world *world);
int		parse_sphere(char *file, t_world *world);
int		parse_light(char *file, t_world *world);
int		parse_ambient(char *file, t_world *world);
int		parse_camera(char *file, t_world *world);
int		parse_point(char *file, char **endptr, t_tuple *point);
int		parse_color(char *file, char **endptr, t_color *color);
int		parse_vector(char *file, char **endptr, t_tuple *point);
int		new_shape_node(t_world *world, t_shape *shape);
int		new_light_node(t_world *world, t_plight *light);
void	free_light_list(t_world *world);
void	free_shape_list(t_world *world);
size_t	get_shape_id(t_world *world);
int		parse_normalized_vector(char *file, char **endptr, t_tuple *point);
int		parse_cube_texture_map(char *dir, t_shape *cu);
void	free_cube_textures(t_uvpat faces[6], int count);
void	set_skybox_params(t_shape *cu);
size_t	count_possible_intersections(t_world *world);
int		parse_model(char *file, t_world *world);
int		parse_texture(char *file, char **endptr, t_shape *sh,
			void (*uvmapper)(t_tuple, double *, double *));

static inline char	*skip_space(char *str)
{
	while (ft_isspace(*str))
		++str;
	return (str);
}

static inline char	*skip_filename(char *str)
{
	while (*str != '\0' && !ft_isspace(*str))
		++str;
	return (str);
}

#endif
