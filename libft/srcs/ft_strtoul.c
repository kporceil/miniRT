/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:45:43 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/13 19:51:32 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdint.h>

static char	*go_to_number_and_set_sign(const char *nptr, int8_t *neg, int base)
{
	uint8_t	c;

	neg[2] = (uint8_t)base;
	neg[0] = 0;
	c = *nptr++;
	while (ft_isspace(c))
		c = *nptr++;
	if (c == '+')
		c = *nptr++;
	if (base == 16 && c == '0' && (*nptr == 'x' || *nptr == 'X'))
		nptr += 1;
	else
		nptr -= 1;
	return ((char *)nptr);
}

static void	set_cut(int base, uint64_t *cut)
{
	cut[0] = SIZE_MAX;
	cut[1] = cut[0] % (unsigned long)base;
	cut[0] /= (unsigned long)base;
}

static char	*set_nbr(uint64_t *nbr, int8_t *neg_any, char *s, uint64_t *cut)
{
	uint8_t	c;

	while (1)
	{
		c = *s++;
		if (ft_isdigit(c))
			c -= '0';
		else if (ft_isalpha(c) && ft_isupper(c))
			c -= 'A' - 10;
		else if (ft_isalpha(c))
			c -= 'a' - 10;
		else
			break ;
		if (c >= neg_any[2])
			break ;
		if (neg_any[1] < 0 || *nbr > cut[0] || (*nbr == cut[0] && c > cut[1]))
			neg_any[1] = -1;
		else
		{
			neg_any[1] = 1;
			*nbr *= neg_any[2];
			*nbr += c;
		}
	}
	return ((char *)s);
}

size_t	ft_strtoul(const char *nptr, char **endptr, int base)
{
	const char	*s;
	int8_t		neg_any[3];
	uint64_t	nbr;
	uint64_t	cut[2];

	s = go_to_number_and_set_sign(nptr, neg_any, base);
	set_cut(base, cut);
	nbr = 0;
	neg_any[1] = 0;
	s = set_nbr(&nbr, neg_any, (char *)s, cut);
	if (neg_any[1] < 0)
	{
		nbr = SIZE_MAX;
		if (neg_any[0])
			nbr = SIZE_MAX;
	}
	if (endptr != 0)
	{
		*endptr = (char *)s - 1;
		if (neg_any[1] <= 0)
			*endptr = (char *)nptr;
	}
	return (nbr);
}
