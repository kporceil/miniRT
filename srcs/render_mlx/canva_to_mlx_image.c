/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canva_to_mlx_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 09:54:55 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/30 11:26:58 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "display_mlx.h"
#include "canvas.h"
#include <mlx.h>

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

void	canva_to_mlx_image(t_display display, t_canva canva)
{
	size_t			pos;
	size_t			pos_max;

	pos = 0;
	pos_max = canva.height * canva.width;
	while (pos < pos_max)
	{
		((int *)display.data_addr)[pos]
			= mlx_get_color_value(display.mlx_ptr,
				color_to_int(canva.canva[pos]));
		++pos;
	}
}
