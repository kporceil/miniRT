/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:09:19 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/01 19:16:12 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bounding_box.h"

void	bb_add(t_bounding_box *b1, t_bounding_box b2)
{
	bb_add_point(b1, b2.min);
	bb_add_point(b1, b2.max);
}
