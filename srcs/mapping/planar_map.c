/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planar_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:47:25 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/09 17:54:32 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"
#include <math.h>

void	planar_map(t_tuple p, double *u, double *v)
{
	*u = fmod(p.x, 1);
	if (*u < 0)
		*u += 1;
	*v = fmod(p.z, 1);
	if (*v < 0)
		*v += 1;
}
