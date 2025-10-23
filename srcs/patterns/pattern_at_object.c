/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_at_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 23:03:47 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/20 14:13:12 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "patterns.h"
#include "shape.h"
#include "matrix.h"

t_color	pattern_at_object(t_pattern pat, t_shape obj, t_tuple p)
{
	p = matrix_tuple_mult(obj.final_inverted, p);
	p = matrix_tuple_mult(pat.inverted, p);
	return (pattern_at(pat, p));
}
