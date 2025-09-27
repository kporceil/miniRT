/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:25:16 by kporceil          #+#    #+#             */
/*   Updated: 2025/09/27 02:09:50 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "color.h"
# include "patterns.h"

typedef struct s_material
{
	t_pattern	pat;
	t_color		color;
	double		ambient;
	double		diffuse;
	double		specular;
	double		shininess;
	double		reflective;
}				t_material;

t_material	material(void);

#endif
