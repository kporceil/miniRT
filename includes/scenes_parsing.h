/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes_parsing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:55:38 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/29 19:11:51 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENES_PARSING_H
# define SCENES_PARSING_H

# include "world.h"

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
int		new_light_node(t_world *world, t_plight *light);
void	free_light_list(t_world *world);

#endif
