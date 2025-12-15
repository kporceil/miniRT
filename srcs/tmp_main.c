/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 22:04:06 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/29 19:42:04 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scenes_parsing.h"
#include "canvas.h"
#include "libft.h"
#include "light.h"
#include "world.h"
#include "camera.h"
#include "display_mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>

void	write_file(char	*name, char	*ppm)
{
	int	fd;

	fd = open(name, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd == -1)
		return ;
	ft_putstr_fd(ppm, fd);
	close(fd);
}

int	main(int argc, char **argv)
{
	t_world	world;
	t_canva	image;
	struct timeval	tv_a = (struct timeval){0};
	struct timeval	tv_b = (struct timeval){0};

	if (argc != 2)
		return (1);
	world = world_create();
	if (parse_file(argv[1], &world) == -1)
	{
		ft_putendl_fd("Invalid Map", 2);
		return (-1);
	}
	image = render(world.cam, world, 1);
	gettimeofday(&tv_b, NULL);
	display_mlx(image, &world.cam, world, 1000 * (tv_a.tv_sec - tv_b.tv_sec)
			+ (tv_a.tv_usec - tv_b.tv_usec) / 1000);
	gettimeofday(&tv_a, NULL);
	free(image.canva);
	free_world(&world);
}
