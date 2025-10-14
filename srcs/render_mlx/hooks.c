/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:50:07 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/13 16:04:34 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>
#include "display_mlx.h"

int	key_hooks(int keycode, t_loop_params *p)
{
	if (keycode == XK_Escape)
		mlx_loop_end(p->display.mlx_ptr);
	return (0);
}
