/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 02:42:07 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/13 03:47:33 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **list_a, t_list *top_a, bool print_sa)
{
	t_list	*second ;

	if (!top_a || !top_a->next)
		return ;
	second = top_a->next ;
	top_a->next = second->next ;
	second->next = top_a ;
	*list_a = second ;
	if (print_sa)
		ft_printf("sa\n") ;
}

void	sb(t_list **list_b, t_list *top_b, bool print_sb)
{
	t_list	*second ;

	if (!top_b || !top_b->next)
		return ;
	second = top_b->next ;
	top_b->next = second->next ;
	second->next = top_b ;
	*list_b = second ;
	if (print_sb)
		ft_printf("sb\n") ;
}

void	ss(t_list **list_a, t_list **list_b, t_list *top_a, t_list *top_b)
{
	sa(list_a, top_a, false) ;
	sb(list_b, top_b, false) ;
	ft_printf("ss\n") ;
}
