/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:45:41 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/18 19:20:12 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include "obj_parser.h"
#include "get_next_line.h"

t_obj_parsing	obj_parser(char *path)
{
	t_obj_parsing	ret;
	int				fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (t_object){.status = OPEN_ERROR};
}
