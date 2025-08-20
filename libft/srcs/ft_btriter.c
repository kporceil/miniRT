/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btriter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 09:50:15 by kporceil          #+#    #+#             */
/*   Updated: 2025/05/19 16:50:13 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btriter(t_btree *btree, void (*f)(void *))
{
	if (btree)
	{
		ft_btriter(btree->left, f);
		ft_btriter(btree->right, f);
		f(btree->container);
	}
}
