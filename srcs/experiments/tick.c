/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 21:56:24 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/25 22:20:02 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

void	tick(t_tuple *env, t_tuple *proj)
{
	proj[0] = tuple_add(proj[0], proj[1]);
	proj[1] = tuple_add(tuple_add(proj[1], env[0]), env[1]);
}
