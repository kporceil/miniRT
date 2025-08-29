/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:50:22 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/28 22:19:02 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_inter	*inter_hit(t_intersect *inter, size_t size)
{
	size_t	i;
	t_inter	*ret;

	i = 0;
	ret = NULL;
	while (i < size)
	{
		if (inter[i].count == 0 || (inter[i].object[0].point < 0 && inter[i].object[1].point < 0))
		{
			++i;
			continue ;
		}
		if (inter[i].object[0].point >= 0 && (ret == NULL
				|| (ret && inter[i].object[0].point < ret->point)))
			ret = inter[i].object;
		if (inter[i].object[1].point >= 0 && (ret == NULL
				|| (ret && inter[i].object[1].point < ret->point)))
			ret = inter[i].object + 1;
		++i;
	}
	return (ret);
}
