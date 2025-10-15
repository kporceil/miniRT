/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:43:17 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/15 21:43:24 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "patterns.h"

t_color	gradient_at(t_pattern pat, t_tuple p)
{
	int	x;

	x = floor(p.x + 0.0001);
	return (color_add(pat.a, color_scalar_mult(color_substract(pat.b, pat.a),
				p.x - x)));
}
