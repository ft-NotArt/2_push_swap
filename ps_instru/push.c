/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 03:37:48 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/15 19:20:35 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_ps_list **top_b, t_ps_list **top_a)
{
	t_ps_list	*second_b;

	if (!(*top_b))
		return ;
	second_b = (*top_b)->next ;
	(*top_b)->next = (*top_a);
	(*top_a) = (*top_b);
	(*top_b) = second_b ;
	ft_printf("pa\n");
}

void	pb(t_ps_list **top_a, t_ps_list **top_b)
{
	t_ps_list	*second_a;

	if (!(*top_a))
		return ;
	second_a = (*top_a)->next ;
	(*top_a)->next = (*top_b);
	(*top_b) = (*top_a);
	(*top_a) = second_a ;
	ft_printf("pb\n");
}
