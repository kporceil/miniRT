/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:14:24 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/13 13:37:29 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include "canvas.h"
#include "display_mlx.h"

t_display	init_mlx_display(size_t width, size_t height)
{
	t_display	display;

	display = (t_display){0};
	display.mlx_ptr = mlx_init();
	if (display.mlx_ptr)
	{
		display.window = mlx_new_window(display.mlx_ptr, width, height,
				WINDOW_TITLE);
		if (display.window)
		{
			display.image = mlx_new_image(display.mlx_ptr, width, height);
			if (display.image)
			{
				display.data_addr = mlx_get_data_addr(display.image,
						&display.bpp, &display.size_line, &display.endian);
				display.opp = display.bpp / 8;
				return (display);
			}
		}
	}
	exit_mlx(display);
	return ((t_display){0});
}
