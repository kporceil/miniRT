/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:52:24 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/29 14:17:37 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "material.h"
#include "tuples.h"
#include "light.h"
#include "color.h"

t_color	lighting(t_material m, t_plight light, t_tuple point, t_tuple eye_nor[2])
{
	const t_color	eff_color = color_mult(m.color, light.intensity);
	const t_tuple	lightv = normalize(tuple_substract(light.pos, point));
	const t_color	ambient = color_scalar_mult(eff_color, m.ambient);
	const double	light_dot_normal = dot(lightv, eye_nor[1]);
	const double	reflect_dot_eye = dot(reflect(tuple_negate(lightv), eye_nor[1]), eye_nor[0]);
	const double	factor = pow(reflect_dot_eye, m.shininess);
	t_color			diffuse;
	t_color			specular;

	if (light_dot_normal < 0)
	{
		diffuse = color(0, 0, 0);
		specular = diffuse;
	}
	else
	{
		diffuse = color_scalar_mult(color_scalar_mult(eff_color, m.diffuse), light_dot_normal);
		if (reflect_dot_eye <= 0)
			specular = color(0, 0, 0);
		else
			specular = color_scalar_mult(color_scalar_mult(light.intensity, m.specular), factor);
	}
	return (color_add(color_add(ambient, diffuse), specular));
}
