/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 19:06:29 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/28 19:06:43 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"
#include "libft.h"

int	parse_point(char *file, char **endptr, t_tuple *point)
{
	point->x = ft_strtod(file, endptr);
	if (file == *endptr || **endptr != ',')
		return (-1);
	file = *endptr + 1;
	point->y = ft_strtod(file, endptr);
	if (file == *endptr || **endptr != ',')
		return (-1);
	file = *endptr + 1;
	point->z = ft_strtod(file, endptr);
	if (file == *endptr)
		return (-1);
	point->w = 1;
	return (0);
}
