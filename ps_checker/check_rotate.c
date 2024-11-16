/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:12:18 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/17 00:15:14 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_ps_list **top)
{
	t_ps_list	*second;

	if (!(*top) || !(*top)->next)
		return ;
	second = (*top)->next ;
	ps_lstlast(*top)->next = (*top);
	(*top)->next = NULL ;
	(*top) = second ;
}

void	check_ra(t_ps_list **top_a)
{
	rotate(top_a);
}

void	check_rb(t_ps_list **top_b)
{
	rotate(top_b);
}

void	check_rr(t_ps_list **top_a, t_ps_list **top_b)
{
	rotate(top_a);
	rotate(top_b);
}
