/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_align_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:39:34 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/15 21:40:02 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "patterns.h"

t_uvpat	uv_align_check(t_color colors[5])
{
	return ((t_uvpat){.type = ALIGN, .colors.main = colors[0],
		.colors.ul = colors[1], .colors.ur = colors[2],
		.colors.bl = colors[3], .colors.br = colors[4]});
}
