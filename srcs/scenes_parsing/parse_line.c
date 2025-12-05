/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:56:48 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/27 17:11:19 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "libft.h"
#include "scenes_parsing.h"
#include <unistd.h>

int	parse_line(char *file, t_world *world)
{
	file = skip_space(file);
	if (*file == '\0')
		return (0);
	if (*file == 'A')
		return (parse_ambient(file + 1, world));
	if (*file == 'C')
		return (parse_camera(file + 1, world));
	if (*file == 'L')
		return (parse_light(file + 1, world));
	if (*file == 's' && *(file + 1) == 'p')
		return (parse_sphere(file + 2, world));
	if (*file == 'p' && *(file + 1) == 'l')
		return (parse_plane(file + 2, world));
	if (*file == 'c' && *(file + 1) == 'y')
		return (parse_cylinder(file + 2, world));
	if (*file == 'c' && *(file + 1) == 'u')
		return (parse_cube(file + 2, world));
	if (*file == 'c' && *(file + 1) == 'o')
		return (parse_cone(file + 2, world));
	write(2, "Invalid Identifier at this line: ", 33);
	ft_putstr_fd(file, 2);
	return (-1);
}
