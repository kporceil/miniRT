/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:08:19 by kporceil          #+#    #+#             */
/*   Updated: 2025/09/25 18:16:58 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERNS_H
# define PATTERNS_H

# include "color.h"
# include "tuples.h"

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
	t_color	a;
	t_color	b;
}				t_pattern;

static inline t_pattern	pattern(t_patype type, t_color a, t_color b)
{
	return ((t_pattern){type, a, b});
}

t_color	pattern_at(t_pattern pat, t_tuple p);

#endif
