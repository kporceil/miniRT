/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:50:22 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/30 23:37:54 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_inter	*inter_hit(t_inter *inter, size_t size)
{
	size_t	i;
	t_inter	*ret;

	i = 0;
	ret = NULL;
	while (i < size)
	{
		if (inter[i].point < 0)
		{
			++i;
			continue ;
		}
		if (!ret)
			ret = inter + i;
		if (inter[i].point < ret->point)
			ret = inter + i;
		++i;
	}
	return (ret);
}
