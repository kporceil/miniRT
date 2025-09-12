/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:56:44 by kporceil          #+#    #+#             */
/*   Updated: 2025/09/12 14:09:14 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include <math.h>

t_intersect	ray_plane_intersect(t_shape *s, t_ray r)
{
	double	t;

	if (fabs(r.dir.y) < 0.0001)
		return ((t_intersect){0, {{s, 0}, {s, 0}}});
	t = -r.origin.y / r.dir.y;
	return ((t_intersect){1, {{s, t}, {s, t}}});
}
