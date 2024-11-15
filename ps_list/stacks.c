/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 05:40:36 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/15 19:01:13 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_start(t_stacks *stacks, int size, int offset)
{
	stacks->start = (size / 2) - offset ;
	if (stacks->start < 0)
		stacks->start = 0 ;
}

void	set_end(t_stacks *stacks, int size, int offset)
{
	stacks->end = (size / 2) + offset ;
	if (stacks->end > (size - 1))
		stacks->end = (size - 1);
}

t_stacks	*stacks_init(int nb_elem, char *argv[])
{
	t_stacks	*stacks ;
	t_ps_list	*current ;
	int			i ;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	i = 1 ;
	current = ps_lstnew(ft_atoi(argv[i++]));
	stacks->a = current ;
	while (i <= nb_elem)
	{
		current->next = ps_lstnew(ft_atoi(argv[i++]));
		current = current->next ;
	}
	stacks->b = NULL ;
	stacks->sorted = init_sorted_array(stacks, nb_elem);
	stacks->start = 0 ;
	stacks->end = 0 ;
	return (stacks);
}

void	stacks_free(t_stacks *stacks)
{
	ps_lstclear(&stacks->a);
	ps_lstclear(&stacks->b);
	free(stacks->sorted);
	free(stacks);
}
