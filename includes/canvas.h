/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 00:23:04 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/22 13:43:39 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# include <stddef.h>
# include "color.h"

typedef struct s_canva
{
	size_t	width;
	size_t	height;
	t_color	*canva;
}				t_canva;

t_canva	canva(size_t width, size_t height);
void	write_pixel(t_canva *c, size_t x, size_t y, t_color color);
char	*canva_to_ppm(t_canva c);

#endif
