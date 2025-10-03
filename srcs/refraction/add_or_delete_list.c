/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:28:58 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/02 17:31:52 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "refract.h"
#include "ray.h"
#include <stdlib.h>
#include <unistd.h>

static void	remove_to_lst(t_objlist **first, t_objlist **last, t_objlist *to_remove)
{
	t_objlist	*current;

	if (to_remove == *first)
	{
		if (to_remove == *last)
			*last = NULL;
		*first = to_remove->next;
		to_remove->next = NULL;
		to_remove->obj = NULL;
		return ;
	}
	current = *first;
	while (current->next != to_remove)
		current = current->next;
	if (to_remove == *last)
		*last = current;
	current->next = to_remove->next;
	to_remove->next = NULL;
	to_remove->obj = NULL;
}

static void	add_to_lst(t_lstbuf mem, t_objlist **first, t_objlist **last, t_inter *inter)
{
	t_objlist	*new;
	size_t		i;

	i = 0;
	while (i < mem.size)
	{
		if (mem.lst[i].obj == NULL)
			break ;
		++i;
	}
	new = mem.lst + i;
	new->next = NULL;
	new->obj = inter->s;
	if (!(*first))
		*first = new;
	if (*last)
		(*last)->next = new;
	*last = new;
}

void	insert_or_delete_inter(t_lstbuf mem, t_objlist **first, t_objlist **last, t_inter *inter)
{
	t_objlist	*current;

	current = *first;
	while (current)
	{
		if (current->obj == inter->s)
		{
			remove_to_lst(first, last, current);
			return ;
		}
		current = current->next;
	}
	add_to_lst(mem, first, last, inter);
}
