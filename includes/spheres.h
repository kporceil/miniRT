/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:49:15 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/29 20:50:32 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERES_H
# define SPHERES_H

# include <stddef.h>
# include "matrix.h"
# include "material.h"

typedef struct s_sphere
{
	t_matrix	transformation;
	t_matrix	inverted;
	t_material	material;
	size_t		id;
}				t_sphere;

t_sphere	sphere(size_t id);
void		sphere_set_matrix(t_sphere *s, t_matrix m);

#endif
