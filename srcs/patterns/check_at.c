/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:42:48 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/15 21:42:55 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "patterns.h"

t_color	checker_at(t_pattern pat, t_tuple p)
{
	int	x;
	int	y;
	int	z;

	x = floor(p.x + 0.0001);
	y = floor(p.y + 0.0001);
	z = floor(p.z + 0.0001);
	if ((x + y + z) % 2)
		return (pat.b);
	return (pat.a);
}
