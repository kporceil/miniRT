/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:36:20 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/29 14:12:37 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "tuples.h"
# include "spheres.h"
# include "color.h"

typedef struct s_plight
{
	t_tuple	pos;
	t_color	intensity;
}				t_plight;

t_tuple		normal_at(t_sphere s, t_tuple p);
t_tuple		reflect(t_tuple in, t_tuple normal);
t_plight	point_light(t_tuple pos, t_color intensity);
t_color		lighting(t_material m, t_plight light, t_tuple point, t_tuple eye_nor[2]);

#endif
