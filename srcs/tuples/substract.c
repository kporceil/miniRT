/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substract.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 19:28:54 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/21 19:21:52 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

inline t_tuple	tuple_substract(t_tuple t1, t_tuple t2)
{
	return ((t_tuple){t1.x - t2.x, t1.y - t2.y, t1.z - t2.z, t1.w - t2.w});
}
