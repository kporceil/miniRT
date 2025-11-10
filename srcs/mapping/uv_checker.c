/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:38:53 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/15 21:38:59 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "patterns.h"

t_uvpat	uv_checkers(size_t width, size_t height,
		t_color a, t_color b)
{
	return ((t_uvpat){.type = CHECKERS, .width = width,
		.height = height, .colors.a = a, .colors.b = b});
}
