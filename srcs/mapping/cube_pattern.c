/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_pattern.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:38:14 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/15 21:38:19 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "patterns.h"

t_pattern	cube_pattern(t_uvpat face[6])
{
	return ((t_pattern){.type = CUBE_UV, .transform = identity_matrix(4),
		.inverted = identity_matrix(4),
		.faces = {face[0], face[1], face[2], face[3], face[4], face[5]}});
}
