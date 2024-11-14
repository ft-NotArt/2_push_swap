/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 02:42:07 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/13 21:53:23 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **top)
{
	t_list	*second ;

	if (!(*top) || !(*top)->next)
		return ;
	second = (*top)->next ;
	(*top)->next = second->next ;
	second->next = (*top) ;
	(*top) = second ;
}

void	sa(t_list **top_a)
{
	swap(top_a);
	ft_printf("sa\n");
}

void	sb(t_list **top_b)
{
	swap(top_b);
	ft_printf("sb\n");
}

void	ss(t_list **top_a, t_list **top_b)
{
	swap(top_a);
	swap(top_b);
	ft_printf("ss\n");
}
