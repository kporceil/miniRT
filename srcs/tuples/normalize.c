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

t_tuple	normalize(t_tuple v)
{
	const double	m = magnitude(v);

	return ((t_tuple){v.x / m, v.y / m, v.z / m, v.w / m});
}
