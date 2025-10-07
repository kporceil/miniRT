/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:14:24 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/07 13:27:28 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include "canvas.h"

int	display_mlx(t_canva canva)
{
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	window = mlx_new_window(mlx, canva.width, canva.height, "miniRT");
	//TODO: check fail
	sleep(10);
	if (window)
		mlx_destroy_window(mlx, window);
	mlx_destroy_display(mlx);
	free(mlx);
	return (0);
}
