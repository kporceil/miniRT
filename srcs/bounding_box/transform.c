/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:10:26 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/02 10:33:58 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bounding_box.h"

t_bounding_box	bb_transform(t_bounding_box b, t_matrix m)
{
	t_bounding_box	ret;
	t_tuple			points[8];
	size_t			i;

	ret = bounding_box(false, (t_tuple){0}, (t_tuple){0});
	points[0] = b.min;
	points[1] = point(b.min.x, b.min.y, b.max.z);
	points[2] = point(b.min.x, b.max.y, b.min.z);
	points[3] = point(b.min.x, b.max.y, b.max.z);
	points[4] = point(b.max.x, b.min.y, b.min.z);
	points[5] = point(b.max.x, b.min.y, b.max.z);
	points[6] = point(b.max.x, b.max.y, b.min.z);
	points[7] = b.max;
	i = 0;
	while (i < 8)
	{
		bb_add_point(&ret, matrix_tuple_mult(m, points[i]));
		++i;
	}
	return (ret);
}
