/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 00:23:04 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/15 16:07:19 by kporceil         ###   ########lyon.fr   */
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
t_canva	ppm_to_canva(char *file);
int		parse_ppm_header(int fd, t_canva *c, size_t *max_color);
int		open_file(char *file, int flag);
void	close_ppm(int fd);

#endif
