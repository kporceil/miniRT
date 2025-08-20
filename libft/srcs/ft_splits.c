/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:02:47 by kporceil          #+#    #+#             */
/*   Updated: 2025/05/29 11:45:15 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	is_in_charset(char c, const char *charset)
{
	size_t	i;

	i = 0;
	while (charset[i])
		if (c == charset[i++])
			return (1);
	return (0);
}

static size_t	ft_countwords(char const *s, char const *charset)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (!is_in_charset(s[i], charset)
			&& (is_in_charset(s[i + 1], charset) || s[i + 1] == 0))
			words++;
		i++;
	}
	return (words);
}

static char	**ft_free_all(char **tab, size_t i_tab)
{
	size_t	i;

	i = 0;
	while (i < i_tab)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static char	**ft_fill_tab(char **tab, char const *s, char const *c, size_t word)
{
	size_t	start;
	size_t	end;
	size_t	i_tab;

	start = 0;
	i_tab = 0;
	while (i_tab < word)
	{
		end = 0;
		while (s[start] && is_in_charset(s[start], c))
			start++;
		while (s[start + end] && !is_in_charset(s[start + end], c))
			end++;
		tab[i_tab] = ft_substr(s, start, end);
		if (!tab[i_tab])
			return (ft_free_all(tab, i_tab));
		start += end;
		i_tab++;
	}
	tab[i_tab] = NULL;
	return (tab);
}

char	**ft_splits(char const *s, const char *charset)
{
	char	**tab;
	size_t	words;

	words = ft_countwords(s, charset);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	tab = ft_fill_tab(tab, s, charset, words);
	return (tab);
}
