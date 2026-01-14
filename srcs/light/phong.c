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
#include "patterns.h"
#include "material.h"
#include "tuples.h"
#include "light.h"
#include "color.h"

static inline t_color	set_color(t_lighting l)
{
	if (l.m.pat.type != NO)
		return (pattern_at_object(l.m.pat, *l.obj, l.p));
	return (l.m.color);
}

#ifdef MANDATORY

t_color	lighting(t_lighting l)
{
	t_color			ambient;
	t_color			diffuse;
	const t_color	obj_color = set_color(l);

	l.eff_color = color_mult(obj_color, l.light.intensity);
	ambient = color_mult(l.eff_color, l.ambient);
	if (l.in_shadow)
		return (ambient);
	l.lightv = normalize(tuple_substract(l.light.pos, l.p));
	l.light_dot_norm = dot(l.lightv, l.normalv);
	l.ref_dot_eye = dot(reflect(tuple_negate(l.lightv), l.normalv), l.eyev);
	diffuse = color_scalar_mult(color_scalar_mult(l.eff_color, l.m.diffuse),
			l.light_dot_norm);
	return (color_add(ambient, diffuse));
}

#endif

#ifdef BONUS

t_color	lighting(t_lighting l)
{
	t_color			ambient;
	t_color			specular;
	t_color			diffuse;
	const t_color	obj_color = set_color(l);

	l.eff_color = color_mult(obj_color, l.light.intensity);
	ambient = color_mult(l.eff_color, l.ambient);
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

#endif
