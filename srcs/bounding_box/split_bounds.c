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

static void	split_x(t_bounding_box b, t_bounding_box *left, t_bounding_box *right, double dx)
{
	t_tuple	min_helper;
	t_tuple	max_helper;

	min_helper = b.min;
	max_helper = b.max; 
	max_helper.x = min_helper.x + dx / 2.0;
	min_helper.x = max_helper.x;
	*left = bounding_box(true, b.min, max_helper);
	*right = bounding_box(true, min_helper, b.max);
}

static void	split_y(t_bounding_box b, t_bounding_box *left, t_bounding_box *right, double dy)
{
	t_tuple	min_helper;
	t_tuple	max_helper;

	min_helper = b.min;
	max_helper = b.max; 
	max_helper.y = min_helper.y + dy / 2.0;
	min_helper.y = max_helper.y;
	*left = bounding_box(true, b.min, max_helper);
	*right = bounding_box(true, min_helper, b.max);
}

static void	split_z(t_bounding_box b, t_bounding_box *left, t_bounding_box *right, double dz)
{
	t_tuple	min_helper;
	t_tuple	max_helper;

	min_helper = b.min;
	max_helper = b.max; 
	max_helper.z = min_helper.z + dz / 2.0;
	min_helper.z = max_helper.z;
	*left = bounding_box(true, b.min, max_helper);
	*right = bounding_box(true, min_helper, b.max);
}

void	bb_split_bounds(t_bounding_box b, t_bounding_box *left, t_bounding_box *right)
{
	double const	dx = fabs(b.max.x - b.min.x);
	double const	dy = fabs(b.max.y - b.min.y);
	double const	dz = fabs(b.max.z - b.min.z);
	double const	max = fmax(fmax(dx, dy), dz);

	if (max == dx)
		split_x(b, left, right, dx);
	else if (max == dy)
		split_y(b, left, right, dy);
	else
		split_z(b, left, right, dz);
}
