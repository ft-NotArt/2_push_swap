/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 22:22:09 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/14 07:05:45 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_lstadd_back(t_ps_list **lst, t_ps_list *new)
{
	if (!lst)
		return ;
	if (!*lst)
		*lst = new ;
	else
		ps_lstlast(*lst)->next = new ;
}
