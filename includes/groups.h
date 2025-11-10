/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:33:55 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/23 15:35:35 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GROUPS_H
# define GROUPS_H

# include "shape.h"

t_shape		group(size_t id, size_t group_size);
int			group_add_shape(t_shape *g, t_shape s);
void		group_set_matrix(t_shape *g, t_matrix m);
void		group_set_material(t_shape *g, t_material m);

#endif
