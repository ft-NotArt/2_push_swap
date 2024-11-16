/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 02:42:07 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/17 00:15:29 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_ps_list **top)
{
	t_ps_list	*second ;

	if (!(*top) || !(*top)->next)
		return ;
	second = (*top)->next ;
	(*top)->next = second->next ;
	second->next = (*top);
	(*top) = second ;
}

void	check_sa(t_ps_list **top_a)
{
	swap(top_a);
}

void	check_sb(t_ps_list **top_b)
{
	swap(top_b);
}

void	check_ss(t_ps_list **top_a, t_ps_list **top_b)
{
	swap(top_a);
	swap(top_b);
}
