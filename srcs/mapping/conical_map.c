/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conical_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:50:11 by kporceil          #+#    #+#             */
/*   Updated: 2025/12/04 15:51:39 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"
#include <math.h>

void	conical_map(t_tuple p, double *u, double *v)
{
	const double	theta = atan2(p.x, p.z);
	const double	raw_u = theta / (2 * M_PI);
	const double	dist = sqrt(p.x * p.x + p.z * p.z);

	*u = 1 - (raw_u + 0.5);
	if (dist < 0.0001)
		*v = 0;
	else
		*v = dist;
	if (*v < 0)
		*v = 0;
}
