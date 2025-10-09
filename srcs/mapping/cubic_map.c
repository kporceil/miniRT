/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubic_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:02:43 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/09 19:04:52 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "patterns.h"

int	face_from_point(t_tuple p)
{
	const double	abs_x = fabs(p.x);
	const double	abs_y = fabs(p.y);
	const double	abs_z = fabs(p.z);
	const double	coord = fmax(fmax(abs_x, abs_y), abs_z);

	if (fabs(coord - p.x) < 0.0001)
		return (RIGHTF);
	if (fabs(coord + p.x) < 0.0001)
		return (LEFTF);
	if (fabs(coord - p.y) < 0.0001)
		return (UPF);
	if (fabs(coord + p.y) < 0.0001)
		return (DOWNF);
	if (fabs(coord - p.z) < 0.0001)
		return (FRONTF);
	return (BACKF);
}

void	cubic_map_front(t_tuple p, double *u, double *v)
{
	*u = fmod(p.x + 1, 2);
	if (*u < 0)
		*u += 1;
	*u /= 2;
	*v = fmod(p.y + 1, 2);
	if (*v < 0)
		*v += 1;
	*v /= 2;
}

void	cubic_map_back(t_tuple p, double *u, double *v)
{
	*u = fmod(1 - p.x, 2);
	if (*u < 0)
		*u += 2;
	*u /= 2;
	*v = fmod(p.y + 1, 2);
	if (*v < 0)
		*v += 2;
	*v /= 2;
}

void	cubic_map_up(t_tuple p, double *u, double *v)
{
	*u = fmod(p.x + 1, 2);
	if (*u < 0)
		*u += 2;
	*u /= 2;
	*v = fmod(1 - p.z, 2);
	if (*v < 0)
		*v += 2;
	*v /= 2;
}

void	cubic_map_down(t_tuple p, double *u, double *v)
{
	*u = fmod(p.x + 1, 2);
	if (*u < 0)
		*u += 2;
	*u /= 2;
	*v = fmod(p.z + 1, 2);
	if (*v < 0)
		*v += 2;
	*v /= 2;
}

void	cubic_map_left(t_tuple p, double *u, double *v)
{
	*u = fmod(p.z + 1, 2);
	if (*u < 0)
		*u += 2;
	*u /= 2;
	*v = fmod(p.y + 1, 2);
	if (*v < 0)
		*v += 2;
	*v /= 2;
}

void	cubic_map_right(t_tuple p, double *u, double *v)
{
	*u = fmod(1 - p.z, 2);
	if (*u < 0)
		*u += 2;
	*u /= 2;
	*v = fmod(p.y + 1, 2);
	if (*v < 0)
		*v += 2;
	*v /= 2;
}
