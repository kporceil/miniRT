/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 19:07:18 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/28 19:10:43 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "libft.h"

int	parse_color(char *file, char **endptr, t_color *color)
{
	color->red = ft_strtod(file, endptr) / 255.0;
	if (*endptr == file || **endptr != ',')
		return (-1);
	file = *endptr + 1;
	color->green = ft_strtod(file, endptr) / 255.0;
	if (*endptr == file || **endptr != ',')
		return (-1);
	file = *endptr + 1;
	color->blue = ft_strtod(file, endptr) / 255.0;
	if (*endptr == file)
		return (-1);
	return (0);
}
