/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindrical_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:05:28 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/09 18:07:25 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"
#include <math.h>

void	cylindrical_map(t_tuple p, double *u, double *v)
{
	const double	theta = atan2(p.x, p.z);
	const double	raw_u = theta / (2 * M_PI);

	*u = 1 - (raw_u + 0.5);
	*v = fmod(p.y, 1);
	if (*v < 0)
		*v += 1;
}
