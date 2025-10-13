/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_pattern_at.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:01:15 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/09 18:30:51 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "patterns.h"
#include <math.h>

static t_color	align_uv_pattern_at(t_uvpat pat, double u, double v)
{
	if (v > 0.8)
	{
		if (u < 0.2)
			return (pat.colors.ul);
		if (u > 0.8)
			return (pat.colors.ur);
	}
	if (v < 0.2)
	{
		if (u < 0.2)
			return (pat.colors.bl);
		if (u > 0.8)
			return (pat.colors.br);
	}
	return (pat.colors.main);
}

t_color	uv_pattern_at(t_uvpat pat, double u, double v)
{
	size_t	u2;
	size_t	v2;

	if (pat.type == ALIGN || pat.type == SKYBOX)
		return (align_uv_pattern_at(pat, u, v));
	u2 = floor(u * pat.width);
	v2 = floor(v * pat.height);
	if ((u2 + v2) % 2)
		return (pat.colors.b);
	return (pat.colors.a);
}
