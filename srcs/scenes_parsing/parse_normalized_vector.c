/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_unit_vector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:39:22 by kporceil          #+#    #+#             */
/*   Updated: 2025/12/02 15:41:57 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scenes_parsing.h"
#include "libft.h"

int	parse_normalized_vector(char *file, char **endptr, t_tuple *point)
{
	t_tuple	normalized;

	if (parse_vector(file, endptr, point) == -1)
		return (-1);
	if (fabs(magnitude(*point)) - 1 > 0.0001)
	{
		ft_putstr_fd("Not a normalized vector: the normalized vector of your "
			"input vector is: ", 2);
		normalized = normalize(*point);
		ft_putdouble_fd(normalized.x, 2, 5);
		ft_putchar_fd(',', 2);
		ft_putdouble_fd(normalized.y, 2, 5);
		ft_putchar_fd(',', 2);
		ft_putdouble_fd(normalized.z, 2, 5);
		ft_putchar_fd('\n', 2);
		return (-1);
	}
	return (0);
}
