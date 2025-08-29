/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:49:46 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/21 19:21:24 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_tuple	tuple_scalar_mult(t_tuple t, double scalar)
{
	return ((t_tuple){t.x * scalar, t.y * scalar, t.z * scalar, t.w * scalar});
}

t_tuple	tuple_scalar_div(t_tuple t, double scalar)
{
	return ((t_tuple){t.x / scalar, t.y / scalar, t.z / scalar, t.w / scalar});
}
