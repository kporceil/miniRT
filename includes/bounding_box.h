/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounding_box.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:36:27 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/08 17:58:58 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOUNDING_BOX_H
# define BOUNDING_BOX_H

# include <stdbool.h>
# include "tuples.h"
# include "shape.h"

# ifndef T_RAY
#  define T_RAY

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	dir;
}				t_ray;

# endif

# ifndef T_BOUNDING_BOX
#  define T_BOUNDING_BOX

typedef struct s_bounding_box	t_bounding_box;

struct s_bounding_box
{
	t_tuple	min;
	t_tuple	max;
};

# endif

t_bounding_box	bounding_box(_Bool points, t_tuple min, t_tuple max);
void			bb_add_point(t_bounding_box *box, t_tuple point);
t_bounding_box	bb_bounds_of(t_shape s);
void			bb_add(t_bounding_box *b1, t_bounding_box b2);
_Bool			bb_contains_point(t_bounding_box b, t_tuple p);
_Bool			bb_contains_box(t_bounding_box b1, t_bounding_box b2);
t_bounding_box	bb_transform(t_bounding_box b, t_matrix m);
t_bounding_box	bb_parent_space_bounds_of(t_shape *s);
_Bool			bb_intersect(t_bounding_box b, t_ray r);
void			bb_split_bounds(t_bounding_box b, t_bounding_box *left, t_bounding_box *right);
void			partition_children(t_shape *g);

#endif
