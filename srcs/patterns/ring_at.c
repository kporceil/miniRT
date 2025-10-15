/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring_at.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:43:41 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/15 21:43:48 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "patterns.h"

t_color	ring_at(t_pattern pat, t_tuple p)
{
	if ((int)(floor(sqrt(p.x * p.x + p.z * p.z) + 0.0001)) % 2)
		return (pat.b);
	return (pat.a);
}
