/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contains_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 09:34:46 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/02 09:41:57 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bounding_box.h"

_Bool	bb_contains_point(t_bounding_box b, t_tuple p)
{
	return (b.min.x <= p.x && p.x <= b.max.x
			&& b.min.y <= p.y && p.y <= b.max.y
			&& b.min.z <= p.z && p.z <= b.max.z);
}
