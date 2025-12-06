/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:41:51 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/20 14:44:20 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// NOTE: doesnt detect overflow

static void	ft_atof_init(const char **nptr, double *mult, double *ret,
			char *sign)
{
	*sign = 1;
	*ret = 0.0;
	*mult = 0.1;
	while (ft_isspace(**nptr))
		++*nptr;
	if (**nptr == '+' || **nptr == '-')
	{
		*sign = 44 - **nptr;
		++*nptr;
	}
}

double	ft_atof(const char *nptr)
{
	double	ret;
	double	mult;
	char	sign;

	ft_atof_init(&nptr, &mult, &ret, &sign);
	while (ft_isdigit(*nptr))
	{
		ret = (10 * ret) + (*nptr - '0');
		++nptr;
	}
	if (*nptr != ',' && *nptr != '.')
		return (ret * sign);
	++nptr;
	while (ft_isdigit(*nptr) && mult > 1e-7)
	{
		ret += (*nptr - '0') * mult;
		mult /= 10;
		++nptr;
	}
	return (ret * sign);
}
