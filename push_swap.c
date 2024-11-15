/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 02:31:30 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/15 02:36:18 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stacks_visu(t_ps_list *list_a, t_ps_list *list_b)
{
	t_ps_list	*ca = list_a;
	t_ps_list	*cb = list_b;

	while (ca && cb)
	{
		ft_printf("\t%d", ca->value);
		ft_printf("\t%d\n", cb->value);
		ca = ca->next ;
		cb = cb->next ;
	}

	while (ca)
	{
		ft_printf("\t%d\n", ca->value);
		ca = ca->next ;
	}

	while (cb)
	{
		ft_printf("\t\t%d\n", cb->value);
		cb = cb->next ;
	}
	ft_printf("\tA\tB\n");
}

void visu()
{
	t_ps_list	*a1 = ps_lstnew(1) ;
	t_ps_list	*a2 = ps_lstnew(540) ;
	a1->next = a2 ;
	t_ps_list	*a3 = ps_lstnew(3) ;
	a2->next = a3 ;

	t_ps_list	*b1 = ps_lstnew(1) ;
	t_ps_list	*b2 = ps_lstnew(2) ;
	b1->next = b2 ;

	t_stacks	*heads = malloc(sizeof(t_stacks));
	heads->a = a1 ;
	heads->b = b1 ;

	stacks_visu((heads->a), (heads->b)) ;
	ft_printf("\n\n") ;
	sa(&(heads->a));
	sb(&(heads->b));
	stacks_visu((heads->a), (heads->b)) ;
	ft_printf("\n\n") ;
	ss(&(heads->a), &(heads->b));
	stacks_visu((heads->a), (heads->b)) ;
	ft_printf("\n\n") ;
	pa(&(heads->b), &(heads->a));
	stacks_visu((heads->a), (heads->b)) ;
	ft_printf("\n\n") ;
	pb(&(heads->a), &(heads->b));
	pb(&(heads->a), &(heads->b));
	stacks_visu((heads->a), (heads->b)) ;
	pa(&(heads->b), &(heads->a));

	ft_printf("\n\n") ;
	ft_printf("\n\n") ;

	t_ps_list	*naze = NULL;

	pa(&naze, &(heads->a)) ;
	pb(&naze, &(heads->b)) ;
	sa(&naze) ;
	sb(&naze) ;
	ss(&naze, &naze) ;

	stacks_visu((heads->a), (heads->b)) ;

	ft_printf("\n\n") ;
	ft_printf("\n\n") ;

	ra(&(heads->a)) ;
	rb(&(heads->b)) ;
	stacks_visu((heads->a), (heads->b)) ;
	ft_printf("\n\n") ;
	rr(&(heads->a), &(heads->b)) ;
	stacks_visu((heads->a), (heads->b)) ;
	ra(&(heads->a)) ;
	stacks_visu((heads->a), (heads->b)) ;

	ft_printf("\n\n") ;
	ft_printf("\n\n") ;


	rra(&(heads->a)) ;
	rrb(&(heads->b)) ;
	stacks_visu((heads->a), (heads->b)) ;
	ft_printf("\n\n") ;
	rrr(&(heads->a), &(heads->b)) ;
	stacks_visu((heads->a), (heads->b)) ;
	rra(&(heads->a)) ;
	stacks_visu((heads->a), (heads->b)) ;
}

int main(int argc, char *argv[])
{
	t_stacks	*stacks ;

	if (argc == 1)
		return (0);
	if (!parsing(argc, argv))
		return (ft_printf("Error\a\n"), 1);
	stacks = stacks_init(argc, argv);
	if (!stacks)
		return (1);
	
	stacks_visu(stacks->a, stacks->b) ;
	
	magic_algorithm(stacks);
	
	stacks_visu(stacks->a, stacks->b) ;


	stacks_free(stacks);
	return (0);
}
