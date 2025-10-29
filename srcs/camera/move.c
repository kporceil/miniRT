/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:15:03 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/29 16:34:59 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "tuples.h"
#include <stdbool.h>

void	move_camera(t_camera *c, t_tuple translation, _Bool *should_render)
{
	c->pos = tuple_add(c->pos, translation);
	c->look_at = tuple_add(c->look_at, translation);
	*should_render = true;
}
