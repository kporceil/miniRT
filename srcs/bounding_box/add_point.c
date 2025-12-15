/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:04:36 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/01 18:08:50 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bounding_box.h"

void	bb_add_point(t_bounding_box *box, t_tuple point)
{
	if (point.x < box->min.x)
		box->min.x = point.x;
	if (point.y < box->min.y)
		box->min.y = point.y;
	if (point.z < box->min.z)
		box->min.z = point.z;
	if (point.x > box->max.x)
		box->max.x = point.x;
	if (point.y > box->max.y)
		box->max.y = point.y;
	if (point.z > box->max.z)
		box->max.z = point.z;
}
