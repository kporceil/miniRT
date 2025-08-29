/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:06:08 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/21 19:39:52 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_color
{
	double	red;
	double	green;
	double	blue;
}				t_color;

t_color	color(double red, double green, double blue);
t_color	color_add(t_color c1, t_color c2);
t_color	color_substract(t_color c1, t_color c2);
t_color	color_scalar_mult(t_color c, double scalar);
t_color	color_mult(t_color c1, t_color c2);

#endif
