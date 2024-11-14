/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:00:14 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/14 01:50:19 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **top)
{
	t_list *second_to_last ;

	if (!(*top) || !(*top)->next)
		return ;
	second_to_last = ft_lstsecond_to_last(*top);
	second_to_last->next->next = (*top);
	(*top) = second_to_last->next ;
	second_to_last->next = NULL ;
}

void	rra(t_list **top_a)
{
	reverse_rotate(top_a);
	ft_printf("rra\n");
}

void	rrb(t_list **top_b)
{
	reverse_rotate(top_b);
	ft_printf("rrb\n");
}

void	rrr(t_list **top_a, t_list **top_b)
{
	reverse_rotate(top_a);
	reverse_rotate(top_b);
	ft_printf("rrr\n") ;
}