/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   face_from_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:32:51 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/15 21:32:59 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "patterns.h"

int	face_from_point(t_tuple p)
{
	const double	abs_x = fabs(p.x);
	const double	abs_y = fabs(p.y);
	const double	abs_z = fabs(p.z);
	const double	coord = fmax(fmax(abs_x, abs_y), abs_z);
	const double	epsilon = 1e-10;

	if (coord - abs_x < epsilon && p.x > 0)
		return (RIGHTF);
	if (coord - abs_x < epsilon && p.x < 0)
		return (LEFTF);
	if (coord - abs_y < epsilon && p.y > 0)
		return (UPF);
	if (coord - abs_y < epsilon && p.y < 0)
		return (DOWNF);
	if (coord - abs_z < epsilon && p.z > 0)
		return (FRONTF);
	return (BACKF);
}
