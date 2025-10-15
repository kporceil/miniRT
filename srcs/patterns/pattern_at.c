/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:00:52 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/09 15:52:22 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "tuples.h"
#include "patterns.h"

t_color	uv_cube_pattern_at(t_pattern pat, t_tuple p)
{
	const int	face = face_from_point(p);
	double		u;
	double		v;

	if (face == FRONTF)
		cubic_map_front(p, &u, &v);
	else if (face == BACKF)
		cubic_map_back(p, &u, &v);
	else if (face == RIGHTF)
		cubic_map_right(p, &u, &v);
	else if (face == LEFTF)
		cubic_map_left(p, &u, &v);
	else if (face == UPF)
		cubic_map_up(p, &u, &v);
	else
		cubic_map_down(p, &u, &v);
	return (uv_pattern_at(pat.faces[face], u, v));
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
	if (pat.type == UV)
		return (uv_pattern_at_point(pat, p));
	if (pat.type == CUBE_UV)
		return (uv_cube_pattern_at(pat, p));
	return (color(-1, -1, -1));
}
