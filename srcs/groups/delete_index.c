/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:07:24 by lcesbron          #+#    #+#             */
/*   Updated: 2025/12/08 11:10:11 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"
#include "groups.h"

int	group_delete_index(t_shape *group, size_t index)
{
	if (vec_delete_index(group->child, index))
		return (1);
	--group->nb_members;
	return (0);
}
