/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:30:52 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/21 19:31:45 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	color_scalar_mult(t_color c, double scalar)
{
	return ((t_color){c.red * scalar, c.green * scalar, c.blue * scalar});
}
