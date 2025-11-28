/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:09:05 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/28 16:39:28 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

static size_t	calc_dec_size(const char *nptr)
{
	size_t	size;
	char	*s;

	size = 1;
	s = (char *)nptr;
	while (ft_isdigit(*s++))
		size *= 10;
	return (size);
}

static char	*go_to_number_and_set_sign(const char *nptr, int8_t *sign)
{
	char	c;

	c = *nptr++;
	*sign = 1;
	while (ft_isspace(c))
		c = *nptr++;
	if (c == '-')
		*sign = -1;
	else
		nptr -= 1;
	return ((char *)nptr);
}

static double	get_number(const char *nptr, char **endptr)
{
	char	*s;
	int8_t		sign;
	double		nbr;
	char		c;

	s = go_to_number_and_set_sign(nptr, &sign);
	nbr = 0;
	c = *s++;
	while (ft_isdigit(c))
	{
		nbr *= 10;
		nbr += c - '0';
		c = *s++;
	}
	*endptr = s - 1;
	return (nbr * sign);
}

double	ft_strtod(const char *nptr, char **endptr)
{
	size_t	dec_size;
	double	integer_part;
	double	dec_part;
	char	*s;

	integer_part = get_number(nptr, endptr);
	if (nptr == *endptr)
		return (0);
	if (**endptr != '.')
		return (integer_part);
	if (!ft_isdigit(*(*endptr + 1)))
	{
		*endptr = (char *)nptr;
		return (integer_part);
	}
	s = *endptr + 1;
	dec_size = calc_dec_size(s);
	dec_part = get_number(s, endptr);
	if (integer_part < 0)
		return (integer_part - dec_part / dec_size);
	return (integer_part + dec_part / dec_size);
}
