/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:49:15 by kporceil          #+#    #+#             */
/*   Updated: 2025/09/25 22:55:02 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include <stddef.h>
# include "matrix.h"
# include "material.h"

typedef enum e_tshape
{
	SPHERE,
	PLANE,
	CYLINDER,
	CUBE,
}				t_tshape;

typedef struct s_shape
{
	t_tshape	type;
	t_matrix	transformation;
	t_matrix	inverted;
	t_material	material;
	size_t		id;
}				t_shape;

t_shape		plane(size_t id);
t_shape		sphere(size_t id);
void		shape_set_matrix(t_shape *s, t_matrix m);

#endif
