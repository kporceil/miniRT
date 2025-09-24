/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canva.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 00:28:09 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/22 00:34:58 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "canvas.h"
#include "color.h"

t_canva	canva(size_t width, size_t height)
{
	return ((t_canva){width, height, ft_calloc(sizeof(t_color),
			width * height)});
}
