/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_caps.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:22:06 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/06 10:19:24 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONE_CAPS_H
# define CONE_CAPS_H

# include "shape.h"
# include "ray.h"

void	intersect_cone_caps(t_shape *cyl, t_ray r, t_intersections *xs);

#endif
