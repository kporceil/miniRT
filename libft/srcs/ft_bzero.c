/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:55:48 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/29 21:02:32 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_bzero(void *s, size_t n)
{
	char		*ptr;
	uint64_t	*word_ptr;

	ptr = (char *)s;
	while (n && ((uintptr_t)ptr & 7))
	{
		*ptr++ = 0;
		n--;
	}
	word_ptr = (uint64_t *)ptr;
	while (n >= 8)
	{
		*word_ptr++ = 0;
		n -= 8;
	}
	ptr = (char *)word_ptr;
	while (n--)
		*ptr++ = 0;
	return (s);
}
