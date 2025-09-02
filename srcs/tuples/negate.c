/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 19:38:22 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/20 19:39:25 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

inline t_tuple	tuple_negate(t_tuple t)
{
	return (tuple_substract((t_tuple){0, 0, 0, 0}, t));
}
