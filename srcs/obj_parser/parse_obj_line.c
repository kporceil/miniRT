/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:21:08 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/20 20:34:25 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "obj_parser.h"
#include "libft.h"
#include "vectors.h"

static void	free_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		++i;
	}
	free(split);
}

// NOTE: for readibility and time reasons, yes this is done with split

void	parse_obj_line(char *line, t_obj_parsing *p)
{
	char ** const	args = ft_splits(line, " \f\t\n\r\v");

	if (!args)
	{
		p->status = MALLOC_ERROR;
		return ;
	}
	if (!args[0])
		++p->ignored;
	else if (!ft_strncmp(args[0], "v", 2))
		add_vertice(args + 1, p);
	else if (!ft_strncmp(args[0], "f", 2))
		add_face(args + 1, p);
	else if (!ft_strncmp(args[0], "g", 2))
		change_group(p);
	else
		++p->ignored;
	free_split(args);
}
