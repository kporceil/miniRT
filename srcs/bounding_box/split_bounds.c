/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_bounds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:22:17 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/02 18:33:58 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bounding_box.h"

void	bb_split_bounds(t_bounding_box b, t_bounding_box *left, t_bounding_box *right)
{
	double const	dx = fabs(b.max.x - b.min.x);
	double const	dy = fabs(b.max.y - b.min.y);
	double const	dz = fabs(b.max.z - b.min.z);
	double const	max = fmax(fmax(dx, dy), dz);

	
}
