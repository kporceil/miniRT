/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:00:00 by kporceil          #+#    #+#             */
/*   Updated: 2025/12/02 10:00:00 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_decimal(long frac, int precision, int fd)
{
	int	i;

	i = 0;
	while (i < precision)
	{
		frac *= 10;
		ft_putchar_fd("0123456789"[frac / 1000000], fd);
		frac %= 1000000;
		i++;
	}
}

static void	put_integer_part(long nb, int fd)
{
	if (nb > 9)
		put_integer_part(nb / 10, fd);
	ft_putchar_fd("0123456789"[nb % 10], fd);
}

void	ft_putdouble_fd(double n, int fd, int precision)
{
	long	integer_part;
	long	frac;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	integer_part = (long)n;
	frac = (long)((n - integer_part) * 1000000);
	put_integer_part(integer_part, fd);
	if (precision > 0)
	{
		ft_putchar_fd('.', fd);
		put_decimal(frac, precision, fd);
	}
}
