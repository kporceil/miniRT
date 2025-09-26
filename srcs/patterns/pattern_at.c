/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:00:52 by kporceil          #+#    #+#             */
/*   Updated: 2025/09/26 01:29:36 by kporceil         ###   ########lyon.fr   */
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

static inline t_color	ring_at(t_pattern pat, t_tuple p)
{
	if ((int)(floor(sqrt(p.x * p.x + p.z * p.z))) % 2)
		return (pat.b);
	return (pat.a);
}

static inline t_color	gradient_at(t_pattern pat, t_tuple p)
{
	return (color_add(pat.a, color_scalar_mult(color_substract(pat.b, pat.a),
				p.x - floor(p.x))));
}

static inline t_color	checker_at(t_pattern pat, t_tuple p)
{
	if ((int)(floor(p.x) + round(p.y) + floor(p.z)) % 2)
		return (pat.b);
	return (pat.a);
}

t_color	pattern_at(t_pattern pat, t_tuple p)
{
	if (pat.type == STRIPED)
		return (stripe_at(pat, p));
	if (pat.type == RING)
		return (ring_at(pat, p));
	if (pat.type == GRADIENT)
		return (gradient_at(pat, p));
	if (pat.type == CHECKER)
		return (checker_at(pat, p));
	return (color(-1, -1, -1));
}
