/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:30:11 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/13 13:42:49 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "display_mlx.h"
#include "camera.h"

static int	color_to_int(t_color c)
{
	int	ret;

	ret = 0;
	if (c.red >= 1)
		ret += 255 << 16;
	else
		ret += (char)(c.red * 255) << 16;
	if (c.blue >= 1)
		ret += 255 << 8;
	else
		ret += (char)(c.blue * 255) << 8;
	if (c.green >= 1)
		ret += 255;
	else
		ret += (char)(c.green * 255);
	return (ret);
}

int	render_loop(t_loop_params *p)
{
	t_canva	canva;
	size_t	pos;
	size_t	pos_max;

	canva = render(p->camera, p->world);
	// TODO: check if fail;
	pos = 0;
	pos_max = canva.height * canva.width;
	while (pos < pos_max)
	{
		((int *)p->display.data_addr)[pos] = mlx_get_color_value(p->display.mlx_ptr, color_to_int(canva.canva[pos]));
		++pos;
	}
	mlx_put_image_to_window(p->display.mlx_ptr, p->display.window, p->display.image, 0, 0);
	free(canva.canva);
	return (0);
}
