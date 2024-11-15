/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 05:40:36 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/15 01:46:12 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*stacks_init(int argc, char *argv[])
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
	while (i < argc)
	{
		current->next = ps_lstnew(ft_atoi(argv[i++]));
		current = current->next ;
	}
	stacks->b = NULL ;
	return (stacks);
}

void	stacks_free(t_stacks *stacks)
{
	ps_lstclear(&stacks->a);
	ps_lstclear(&stacks->b);
	free(stacks);
}