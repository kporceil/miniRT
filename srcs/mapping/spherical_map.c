/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spherical_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:14:39 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/09 15:18:34 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"
#include <math.h>

void	spherical_map(t_tuple p, double *u, double *v)
{
	const double	theta = atan2(p.x, p.z);
	const t_tuple	vec = vector(p.x, p.y, p.z);
	const double	radius = magnitude(vec);
	const double	phi = acos(p.y / radius);
	const double	raw_u = theta / (2 * M_PI);

	*u = 1 - (raw_u + 0.5);
	*v = 1 - phi / M_PI;
}
