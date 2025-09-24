/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:22:05 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/27 21:24:31 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

inline t_ray	ray(t_tuple origin, t_tuple direction)
{
	return ((t_ray){origin, direction});
}
