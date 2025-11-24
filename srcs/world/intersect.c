/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:15:15 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/15 17:26:08 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "world.h"
#include "ray.h"

static void	swap_inter(t_inter *a, t_inter *b)
{
	t_inter	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(t_inter *arr, int low, int high)
{
	double	pivot;
	int		i;
	int		j;

	pivot = arr[high].point;
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j].point <= pivot)
		{
			i++;
			swap_inter(arr + i, arr + j);
		}
		j++;
	}
	swap_inter(arr + i + 1, arr + high);
	return (i + 1);
}

static void	quicksort_inter(t_inter *arr, int low, int high)
{
	int	pivot_index;

	if (low < high)
	{
		pivot_index = partition(arr, low, high);
		quicksort_inter(arr, low, pivot_index - 1);
		quicksort_inter(arr, pivot_index + 1, high);
	}
}

static t_intersections	sort_inter(t_intersections *inter)
{
	if (inter->size > 1)
		quicksort_inter(inter->inters, 0, (int)(inter->size - 1));
	return (*inter);
}

t_intersections	world_intersect(t_world	world, t_ray r)
{
	t_intersections	inter;
	size_t			i;

	inter.size = 0;
	inter.inters = world.buf_inter;
	if (!world.objs_count)
		return (inter);
	i = 0;
	while (i < world.objs_count)
	{
		ray_intersect(world.objs + i, r, &inter);
		++i;
	}
	return (sort_inter(&inter));
}
