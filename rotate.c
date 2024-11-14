/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:12:18 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/13 21:53:08 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **top)
{
	t_list	*second;

	if (!(*top) || !(*top)->next)
		return ;
	second = (*top)->next ;
	ft_lstlast(*top)->next = (*top);
	(*top)->next = NULL ;
	(*top) = second ;
}

void	ra(t_list **top_a)
{
	rotate(top_a);
	ft_printf("ra\n");
}

void	rb(t_list **top_b)
{
	rotate(top_b);
	ft_printf("rb\n");
}

void	rr(t_list **top_a, t_list **top_b)
{
	rotate(top_a);
	rotate(top_b);
	ft_printf("rr\n") ;
}
