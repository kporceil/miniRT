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

t_color	lighting(t_lighting l)
{
	t_color	ambient;
	t_color	specular;
	t_color	diffuse;

	l.eff_color = color_mult(l.m.color, l.light.intensity);
	ambient = color_scalar_mult(l.eff_color, l.m.ambient);
	if (l.in_shadow)
		return (ambient);
	l.lightv = normalize(tuple_substract(l.light.pos, l.p));
	l.light_dot_norm = dot(l.lightv, l.normalv);
	l.ref_dot_eye = dot(reflect(tuple_negate(l.lightv), l.normalv), l.eyev);
	l.factor = pow(l.ref_dot_eye, l.m.shininess);
	specular = color(0, 0, 0);
	if (l.light_dot_norm < 0)
		diffuse = specular;
	else
	{
		diffuse = color_scalar_mult(color_scalar_mult(l.eff_color, l.m.diffuse),
				l.light_dot_norm);
		if (l.ref_dot_eye > 0)
			specular = color_scalar_mult(color_scalar_mult(l.light.intensity,
						l.m.specular), l.factor);
	}
	return (color_add(color_add(ambient, diffuse), specular));
}
