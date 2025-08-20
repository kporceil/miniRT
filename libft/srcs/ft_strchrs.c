/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:37:15 by kporceil          #+#    #+#             */
/*   Updated: 2025/05/23 18:37:26 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchrs(const char *str, const char *charset)
{
	size_t	i;
	char	ascii[256];

	ft_bzero(ascii, sizeof(ascii));
	i = 0;
	while (charset[i])
		ascii[(unsigned char)(charset[i++])] = 1;
	i = 0;
	while (str[i])
	{
		if (ascii[(unsigned char)(str[i])])
			return ((char *)(str + i));
		++i;
	}
	return (NULL);
}
