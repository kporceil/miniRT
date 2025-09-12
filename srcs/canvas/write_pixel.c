/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 01:24:36 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/22 01:27:16 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "color.h"

void	write_pixel(t_canva *c, size_t x, size_t y, t_color color)
{
	if (x <= c->width && y <= c->height)
		c->canva[x + y * c->width] = color;
}
