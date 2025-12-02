/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contains_box.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 09:45:56 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/02 09:48:33 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bounding_box.h"

_Bool	bb_contains_box(t_bounding_box b1, t_bounding_box b2)
{
	return (bb_contains_point(b1, b2.min) && bb_contains_point(b1, b2.max));
}
