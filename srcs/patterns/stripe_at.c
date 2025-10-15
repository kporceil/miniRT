/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stripe_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:44:13 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/15 21:44:20 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "patterns.h"

t_color	stripe_at(t_pattern pat, t_tuple p)
{
	int	x;

	x = floor(p.x + 0.0001);
	if (x % 2)
		return (pat.b);
	return (pat.a);
}
