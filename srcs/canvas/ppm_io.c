/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm_io.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:06:30 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/15 16:07:02 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

int	open_file(char *file, int flag)
{
	int	fd;

	fd = open(file, flag);
	if (fd == -1)
	{
		ft_putstr_fd(file, 2);
		ft_putendl_fd(": Unable to open file", 2);
	}
	return (fd);
}

void	close_ppm(int fd)
{
	get_next_line(fd, DELETE);
	close(fd);
}
