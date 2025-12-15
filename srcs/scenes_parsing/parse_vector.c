/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 19:06:47 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/29 19:13:18 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"
#include "libft.h"

int	parse_vector(char *file, char **endptr, t_tuple *point)
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
	point->w = 0;
	return (0);
}
