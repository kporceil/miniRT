/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:30:52 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/16 14:14:57 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMAL_H
# define NORMAL_H

# include "tuples.h"
# include "shape.h"

t_tuple	world_to_object(t_shape *s, t_tuple p);
t_tuple	normal_to_world(t_shape *s, t_tuple n);

#endif
