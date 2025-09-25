/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stripe_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:00:52 by kporceil          #+#    #+#             */
/*   Updated: 2025/09/25 18:10:27 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "tuples.h"
#include "patterns.h"
#include <math.h>

static inline t_color	stripe_at(t_pattern pat, t_tuple p)
{
	if ((int)floor(p.x) % 2)
		return (pat.b);
	return (pat.a);
}

t_color	pattern_at(t_pattern pat, t_tuple p)
{
	if (pat.type == STRIPED)
		return (stripe_at(pat, p));
	return (stripe_at(pat, p));
}
