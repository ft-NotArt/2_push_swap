/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:24:28 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/14 07:05:45 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_list	*ps_lstnew(int value)
{
	t_ps_list	*list;

	list = malloc(sizeof(t_ps_list));
	if (!list)
		return (NULL);
	list->value = value;
	list->next = NULL;
	return (list);
}
