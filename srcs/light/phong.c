/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:52:24 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/29 21:22:53 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "material.h"
#include "tuples.h"
#include "light.h"
#include "color.h"

t_color	lighting(t_material m, t_plight light, t_tuple p, t_tuple eye_nor[2])
{
	const t_tuple	lightv = normalize(tuple_substract(light.pos, p));
	const t_color	col_ambient[2] = {color_mult(m.color, light.intensity),
		color_scalar_mult(col_ambient[0], m.ambient)};
	const double	ln_re_f[3] = {dot(lightv, eye_nor[1]),
		dot(reflect(tuple_negate(lightv), eye_nor[1]), eye_nor[0]),
		pow(ln_re_f[1], m.shininess)};
	t_color			dif_spec[2];

	if (ln_re_f[0] < 0)
	{
		dif_spec[0] = color(0, 0, 0);
		dif_spec[1] = dif_spec[0];
	}
	else
	{
		dif_spec[0] = color_scalar_mult(color_scalar_mult(col_ambient[0],
					m.diffuse), ln_re_f[0]);
		if (ln_re_f[1] <= 0)
			dif_spec[1] = color(0, 0, 0);
		else
			dif_spec[1] = color_scalar_mult(color_scalar_mult(light.intensity,
						m.specular), ln_re_f[2]);
	}
	return (color_add(color_add(col_ambient[1], dif_spec[0]), dif_spec[1]));
}
