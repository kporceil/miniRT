/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:49:15 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/26 15:42:12 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include <stddef.h>
# include "matrix.h"
# include "material.h"
# include "stdbool.h"

typedef enum e_tshape
{
	SPHERE,
	PLANE,
	CYLINDER,
	CUBE,
	CONE,
	GROUP,
	TRIANGLE,
	SMOOTH_TRIANGLE
}				t_tshape;

typedef struct s_shape
{
	t_tshape	type;
	t_matrix	local_transformation;
	t_matrix	final_transformation;
	t_matrix	final_inverted;
	t_material	material;
	t_tuple		tri_p1;
	t_tuple		tri_p2;
	t_tuple		tri_p3;
	t_tuple		tri_e1;
	t_tuple		tri_e2;
	t_tuple		tri_normal;
	t_tuple		tri_n1;
	t_tuple		tri_n2;
	t_tuple		tri_n3;
	t_shape		*parent;
	t_shape		*child;
	size_t		group_size;
	size_t		nb_members;
	int			cyl_closed;
	double		cyl_min;
	double		cyl_max;
	size_t		id;
	bool		skybox;
}				t_shape;

t_shape		plane(size_t id);
t_shape		cube(size_t id);
t_shape		sphere(size_t id);
t_shape		cylinder(size_t id);
t_shape		cone(size_t id);
t_shape		triangle(size_t id, t_tuple p1, t_tuple p2, t_tuple p3);
t_shape		smooth_triangle(size_t id, t_tuple p[3], t_tuple n[3]);
void		shape_set_matrix(t_shape *s, t_matrix m);

#endif
