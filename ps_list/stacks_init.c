/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 05:40:36 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/14 07:23:08 by anoteris         ###   ########.fr       */
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
