/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:21:08 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/19 19:34:44 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "obj_parser.h"
#include "libft.h"

// NOTE: for readibility and time reasons, yes this is done with split

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

static void	add_vertice(char **args, t_obj_parsing *p)
{

}

void	parse_obj_line(char *line, t_obj_parsing *p)
{
	char ** const	args = ft_splits(line, " \f\t\n\r\v");

	if (!args)
	{
		p->status = MALLOC_ERROR;
		return ;
	}
	if (!ft_strncmp(args[0], "v", 2))
		(void)args;
	else
		++p->ignored;
	free_split(args);
}
