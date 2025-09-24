/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:38:59 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/21 16:40:25 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

inline t_tuple	normalize(t_tuple v)
{
	const double	m = magnitude(v);
	const double	inv_m = 1.0 / m;

	return ((t_tuple){v.x * inv_m, v.y * inv_m, v.z * inv_m, v.w * inv_m});
}
