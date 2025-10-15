/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:49:15 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/15 10:19:04 by lcesbron         ###   ########lyon.fr   */
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
	CONE,
	GROUP,
}				t_tshape;

typedef struct s_shape
{
	t_tshape	type;
	t_matrix	transformation;
	t_matrix	inverted;
	t_material	material;
	t_shape		*parent;
	t_shape		*child;
	size_t		nb_members;
	int			cyl_closed;
	double		cyl_min;
	double		cyl_max;
	size_t		id;
}				t_shape;

t_shape		plane(size_t id);
t_shape		cube(size_t id);
t_shape		sphere(size_t id);
t_shape		cylinder(size_t id);
t_shape		cone(size_t id);
t_shape		group(size_t id, size_t nb_members);
void		shape_set_matrix(t_shape *s, t_matrix m);

#endif
