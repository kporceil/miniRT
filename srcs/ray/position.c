/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:30:27 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/28 22:18:42 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

inline t_tuple	ray_position(t_ray r, double t)
{
	return ((t_tuple){r.origin.x + r.dir.x * t,
		r.origin.y + r.dir.y * t,
		r.origin.z + r.dir.z * t, 1});
}
