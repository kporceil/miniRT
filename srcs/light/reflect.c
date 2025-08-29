/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:10:38 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/29 13:12:18 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_tuple	reflect(t_tuple in, t_tuple normal)
{
	return (tuple_substract(in, tuple_scalar_mult(tuple_scalar_mult(normal, 2), dot(in, normal))));
}
