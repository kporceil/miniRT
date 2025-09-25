/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:08:19 by kporceil          #+#    #+#             */
/*   Updated: 2025/09/25 23:12:07 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERNS_H
# define PATTERNS_H

# include "color.h"
# include "tuples.h"
# include "matrix.h"

typedef struct s_shape t_shape;

typedef enum e_patype
{
	NO,
	STRIPED,
	GRADIENT,
	RING,
	CHECKER,
}				t_patype;

typedef struct s_pattern
{ 
	t_patype	type;
	t_color		a;
	t_color		b;
	t_matrix	transform;
	t_matrix	inverted;
}				t_pattern;

static inline t_pattern	pattern(t_patype type, t_color a, t_color b)
{
	return ((t_pattern){type, a, b, identity_matrix(4), identity_matrix(4)});
}

static inline void	pattern_set_transform(t_pattern *pat, t_matrix transform)
{
	pat->transform = transform;
	pat->inverted = matrix_invert(transform);
}

t_color	pattern_at(t_pattern pat, t_tuple p);
t_color	pattern_at_object(t_pattern pat, t_shape obj, t_tuple p);

#endif
