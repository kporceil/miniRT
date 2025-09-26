/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:29:23 by kporceil          #+#    #+#             */
/*   Updated: 2025/09/25 23:12:44 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "patterns.h"
#include "material.h"

t_material	material(void)
{
	return ((t_material){(t_pattern){NO, color(0, 0, 0), color(0, 0, 0),
		identity_matrix(4), identity_matrix(4)},
			(t_color){1, 1, 1}, 0.1, 0.9, 0.9, 200});
}
