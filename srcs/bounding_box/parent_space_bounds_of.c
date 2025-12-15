/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_space_bounds_of.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:38:56 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/02 10:59:51 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bounding_box.h"

t_bounding_box	bb_parent_space_bounds_of(t_shape *s)
{
	return (bb_transform(bb_bounds_of(*s), s->local_transformation));
}
