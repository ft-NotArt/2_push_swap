/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 02:31:30 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/14 01:51:44 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stacks_visu(t_list *list_a, t_list *list_b)
{
	t_list	*ca = list_a;
	t_list	*cb = list_b;

	while (ca && cb)
	{
		ft_printf("\t%d", *((int *) ca->content));
		ft_printf("\t%d\n", *((int *) cb->content));
		ca = ca->next ;
		cb = cb->next ;
	}

	while (ca)
	{
		ft_printf("\t%d\n", *((int *) ca->content));
		ca = ca->next ;
	}

	while (cb)
	{
		ft_printf("\t\t%d\n", *((int *) cb->content));
		cb = cb->next ;
	}
	ft_printf("\tA\tB\n");
}

int main()
{
	int	ia1 = 1 ;
	t_list	*a1 = ft_lstnew(&ia1) ;
	int ia2 = 540 ;
	t_list	*a2 = ft_lstnew(&ia2) ;
	a1->next = a2 ;
	int ia3 = 3 ;
	t_list	*a3 = ft_lstnew(&ia3) ;
	a2->next = a3 ;
	t_list	*ha = a1 ;

	int	ib1 = 1 ;
	t_list	*b1 = ft_lstnew(&ib1) ;
	int ib2 = 2 ;
	t_list	*b2 = ft_lstnew(&ib2) ;
	b1->next = b2 ;
	t_list	*hb = b1 ;

	stacks_visu(ha, hb) ;
	ft_printf("\n\n") ;
	sa(&ha);
	sb(&hb);
	stacks_visu(ha, hb) ;
	ft_printf("\n\n") ;
	ss(&ha, &hb);
	stacks_visu(ha, hb) ;
	ft_printf("\n\n") ;
	pa(&hb, &ha);
	stacks_visu(ha, hb) ;
	ft_printf("\n\n") ;
	pb(&ha, &hb);
	pb(&ha, &hb);
	stacks_visu(ha, hb) ;
	pa(&hb, &ha);

	ft_printf("\n\n") ;
	ft_printf("\n\n") ;

	t_list	*naze = NULL;

	pa(&naze, &ha) ;
	pb(&naze, &hb) ;
	sa(&naze) ;
	sb(&naze) ;
	ss(&naze, &naze) ;

	stacks_visu(ha, hb) ;

	ft_printf("\n\n") ;
	ft_printf("\n\n") ;

	ra(&ha) ;
	rb(&hb) ;
	stacks_visu(ha, hb) ;
	ft_printf("\n\n") ;
	rr(&ha, &hb) ;
	stacks_visu(ha, hb) ;
	ra(&ha) ;
	stacks_visu(ha, hb) ;

	ft_printf("\n\n") ;
	ft_printf("\n\n") ;


	rra(&ha) ;
	rrb(&hb) ;
	stacks_visu(ha, hb) ;
	ft_printf("\n\n") ;
	rrr(&ha, &hb) ;
	stacks_visu(ha, hb) ;
	rra(&ha) ;
	stacks_visu(ha, hb) ;
}
