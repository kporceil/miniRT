/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magnitude.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:18:31 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/21 16:21:16 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "tuples.h"

inline double	magnitude(t_tuple v)
{
	if (!v.w)
		return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w));
}
