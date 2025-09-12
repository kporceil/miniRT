/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_assert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:51:08 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/26 17:57:13 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"
#include "color.h"
#include "matrix.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

void	assert_tuple_equal(t_tuple a, t_tuple b)
{
	assert_double_equal(a.x, b.x, 0.0001);
	assert_double_equal(a.y, b.y, 0.0001);
	assert_double_equal(a.z, b.z, 0.0001);
	assert_double_equal(a.w, b.w, 0.0001);
}

void	assert_color_equal(t_color a, t_color b)
{
	assert_double_equal(a.red, b.red, 0.0001);
	assert_double_equal(a.green, b.green, 0.0001);
	assert_double_equal(a.blue, b.blue, 0.0001);
}

void	assert_matrix_equal(t_matrix a, t_matrix b)
{
	assert_int_equal(a.size, b.size);
	for (uint_fast8_t	i = 0; i < a.size; ++i)
		for (uint_fast8_t j = 0; j < a.size; ++j)
			assert_double_equal(a.matrix[i][j], b.matrix[i][j], 0.0001);
}
