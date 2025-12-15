/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:48:30 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/01 18:07:55 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bounding_box.h"
#include <math.h>

t_bounding_box	bounding_box(_Bool points, t_tuple min, t_tuple max)
{
	if (points)
		return ((t_bounding_box){.min = min, .max = max});
	return ((t_bounding_box){.max = point(-INFINITY, -INFINITY, -INFINITY),
		.min = point(INFINITY, INFINITY, INFINITY)});
}
