/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:40:58 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/15 21:41:07 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "patterns.h"

t_pattern	texture_map(t_uvpat pat, void (*uvmapper)
		(t_tuple, double *, double *))
{
	return ((t_pattern){.type = UV, .uvpat = pat, .uvmapper = uvmapper,
		.transform = identity_matrix(4), .inverted = identity_matrix(4)});
}
