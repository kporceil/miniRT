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

void	cubic_map_front(t_tuple p, double *u, double *v)
{
	*u = fmod(p.x + 1.0, 2.0);
	if (*u < 0)
		*u += 2.0;
	*u = fmin(fmax(*u / 2.0, 0.0), 1.0);
	*v = fmod(p.y + 1.0, 2.0);
	if (*v < 0)
		*v += 2.0;
	*v = fmin(fmax(*v / 2.0, 0.0), 1.0);
}

void	cubic_map_back(t_tuple p, double *u, double *v)
{
	*u = fmod(1.0 - p.x, 2.0);
	if (*u < 0)
		*u += 2.0;
	*u = fmin(fmax(*u / 2.0, 0.0), 1.0);
	*v = fmod(p.y + 1.0, 2.0);
	if (*v < 0)
		*v += 2.0;
	*v = fmin(fmax(*v / 2.0, 0.0), 1.0);
}

void	cubic_map_up(t_tuple p, double *u, double *v)
{
	*u = fmod(p.x + 1.0, 2.0);
	if (*u < 0)
		*u += 2.0;
	*u = fmin(fmax(*u / 2.0, 0.0), 1.0);
	*v = fmod(1.0 - p.z, 2.0);
	if (*v < 0)
		*v += 2.0;
	*v = fmin(fmax(*v / 2.0, 0.0), 1.0);
}

void	cubic_map_down(t_tuple p, double *u, double *v)
{
	*u = fmod(p.x + 1.0, 2.0);
	if (*u < 0)
		*u += 2.0;
	*u = fmin(fmax(*u / 2.0, 0.0), 1.0);
	*v = fmod(p.z + 1.0, 2.0);
	if (*v < 0)
		*v += 2.0;
	*v = fmin(fmax(*v / 2.0, 0.0), 1.0);
}

void	cubic_map_left(t_tuple p, double *u, double *v)
{
	*u = fmod(p.z + 1.0, 2.0);
	if (*u < 0)
		*u += 2.0;
	*u = fmin(fmax(*u / 2.0, 0.0), 1.0);
	*v = fmod(p.y + 1.0, 2.0);
	if (*v < 0)
		*v += 2.0;
	*v = fmin(fmax(*v / 2.0, 0.0), 1.0);
}

void	cubic_map_right(t_tuple p, double *u, double *v)
{
	*u = fmod(1.0 - p.z, 2.0);
	if (*u < 0)
		*u += 2.0;
	*u = fmin(fmax(*u / 2.0, 0.0), 1.0);
	*v = fmod(p.y + 1.0, 2.0);
	if (*v < 0)
		*v += 2.0;
	*v = fmin(fmax(*v / 2.0, 0.0), 1.0);
}
