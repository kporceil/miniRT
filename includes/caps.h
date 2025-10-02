/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caps.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:22:06 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/02 13:35:47 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAPS_H
# define CAPS_H

# include "shape.h"
# include "ray.h"

void	intersect_caps(t_shape *cyl, t_ray r, t_intersections *xs);

#endif
