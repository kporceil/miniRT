/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:56:44 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/26 16:46:43 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include <math.h>

void	ray_plane_intersect(t_shape *s, t_ray r, t_intersections *inter)
{
	if (fabs(r.dir.y) >= 0.0001)
		inter->inters[inter->size++] = (t_inter){.s = s, .point = -r.origin.y / r.dir.y};
}
