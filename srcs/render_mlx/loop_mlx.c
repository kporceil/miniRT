/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:30:11 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/23 17:19:53 by lcesbron         ###   ########lyon.fr   */
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
	if (c.red >= 1.0)
		ret += 255 << 16;
	else
		ret += (unsigned char)(c.red * 255) << 16;
	if (c.green >= 1.0)
		ret += 255 << 8;
	else
		ret += (unsigned char)(c.green * 255) << 8;
	if (c.blue >= 1.0)
		ret += 255;
	else
		ret += (unsigned char)(c.blue * 255);
	return (ret);
}

int	render_loop(t_loop_params *p)
{
	static size_t	frame = 0;
	size_t			pos;
	size_t			pos_max;

	if (!frame)
	{
		pos = 0;
		pos_max = p->canva.height * p->canva.width;
		while (pos < pos_max)
		{
			((int *)p->display.data_addr)[pos]
				= mlx_get_color_value(p->display.mlx_ptr,
					color_to_int(p->canva.canva[pos]));
			++pos;
		}
		mlx_put_image_to_window(p->display.mlx_ptr, p->display.window,
			p->display.image, 0, 0);
	}
	return (++frame);
}
