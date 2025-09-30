/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:56:22 by kporceil          #+#    #+#             */
/*   Updated: 2025/09/11 14:56:40 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include <math.h>

void	ray_cylinder_intersect(t_shape *cyl, t_ray r, t_intersections *inter)
{
	register double const	a = r.dir.x * r.dir.x + r.dir.z * r.dir.z;
	register double			b;
	register double			c;
	register double			disc;

	if (-0.001 <= a && a <= 0.001)
		return ;
	b = 2 * r.origin.x * r.dir.x + 2 * r.origin.z * r.dir.z;
	c = r.origin.x * r.origin.x + r.origin.z * r.origin.z - 1;
	disc = b * b - 4 * a * c;
	if (disc >= 0)
	{
		inter->inters[inter->size++] = (t_inter){cyl, (- b - sqrt(disc)) / (2 * a)};
		inter->inters[inter->size++] = (t_inter){cyl, (- b + sqrt(disc)) / (2 * a)};
	}
}
