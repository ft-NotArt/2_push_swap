/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:00:14 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/17 00:15:48 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_ps_list **top)
{
	t_ps_list	*second_to_last ;

	if (!(*top) || !(*top)->next)
		return ;
	second_to_last = ps_lstsecond_to_last(*top);
	second_to_last->next->next = (*top);
	(*top) = second_to_last->next ;
	second_to_last->next = NULL ;
}

void	check_rra(t_ps_list **top_a)
{
	reverse_rotate(top_a);
}

void	check_rrb(t_ps_list **top_b)
{
	reverse_rotate(top_b);
}

void	check_rrr(t_ps_list **top_a, t_ps_list **top_b)
{
	reverse_rotate(top_a);
	reverse_rotate(top_b);
}
