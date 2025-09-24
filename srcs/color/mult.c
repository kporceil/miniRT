/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:38:14 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/21 19:39:25 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	color_mult(t_color c1, t_color c2)
{
	return ((t_color){c1.red * c2.red, c1.green * c2.green, c1.blue * c2.blue});
}
