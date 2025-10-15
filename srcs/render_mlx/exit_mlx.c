/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:17:50 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/13 13:40:09 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "display_mlx.h"

void	exit_mlx(t_display display)
{
	if (!display.mlx_ptr)
		return ;
	if (display.image)
	{
		mlx_destroy_image(display.mlx_ptr, display.image);
	}
	if (display.window)
	{
		mlx_destroy_window(display.mlx_ptr, display.window);
	}
	mlx_destroy_display(display.mlx_ptr);
	free(display.mlx_ptr);
}
