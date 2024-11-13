/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 03:37:48 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/13 03:47:29 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" //FIXME: maybe could work with only the adress of the pointer to the head

void	pb(t_list **list_a, t_list *top_a, t_list **list_b)
{
	if (!top_a)
		return ;
	*list_a = top_a->next ;
	top_a->next = *list_b ;
	*list_b = top_a ;
	ft_printf("pb\n") ;
}

void	pa(t_list **list_b, t_list *top_b, t_list **list_a)
{
	if (!top_b)
		return ;
	*list_b = top_b->next ;
	top_b->next = *list_a ;
	*list_a = top_b ;
	ft_printf("pa\n") ;
}
