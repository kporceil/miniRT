/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounding_box.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:36:27 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/01 19:16:11 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOUNDING_BOX_H
# define BOUNDING_BOX_H

# include <stdbool.h>
# include "tuples.h"
# include "shape.h"

typedef struct s_bounding_box	t_bounding_box;

struct s_bounding_box
{
	t_tuple	min;
	t_tuple	max;
};

t_bounding_box	bounding_box(_Bool points, t_tuple min, t_tuple max);
void			bb_add_point(t_bounding_box *box, t_tuple point);
t_bounding_box	bb_bounds_of(t_shape s);
void	bb_add(t_bounding_box *b1, t_bounding_box b2);

#endif
