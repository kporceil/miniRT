/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:04:56 by kporceil          #+#    #+#             */
/*   Updated: 2024/11/05 00:54:41 by kporceil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

size_t	ft_strlen(const char *s)
{
	const char	*ptr = s;
	uint64_t	*word_ptr;
	uint64_t	word;

	while ((uintptr_t)ptr & 7)
	{
		if (!*ptr)
			return (ptr - s);
		ptr++;
	}
	word_ptr = (uint64_t *)ptr;
	while (1)
	{
		word = *word_ptr;
		if ((word - 0x0101010101010101ULL) & ~word & 0x8080808080808080ULL)
			break ;
		word_ptr++;
	}
	ptr = (const char *)word_ptr;
	while (*ptr)
		ptr++;
	return (ptr - s);
}
