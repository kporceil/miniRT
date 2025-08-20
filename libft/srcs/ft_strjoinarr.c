/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinarr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:40:21 by kporceil          #+#    #+#             */
/*   Updated: 2025/06/13 11:43:23 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_strlenarr(char **arr)
{
	size_t	len;

	len = 0;
	while (*arr)
		len += ft_strlen(*arr++);
	return (len);
}

char	*ft_strjoinarr(char **arr)
{
	const size_t	len = ft_strlenarr(arr);
	const char		*dest = malloc(sizeof(char) * (len + 1));
	size_t			i;
	size_t			j;
	size_t			dest_i;

	if (!dest)
		return (NULL);
	i = 0;
	dest_i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
			((char *)dest)[dest_i++] = arr[i][j++];
		++i;
	}
	((char *)dest)[dest_i] = '\0';
	return ((char *)dest);
}
