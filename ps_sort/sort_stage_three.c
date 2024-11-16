/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stage_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:14:44 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/15 19:16:51 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	search_max(t_stacks *stacks, int size, int pos, int second_value)
{
	bool	found_second ;

	found_second = false ;
	if (pos < (size - pos))
	{
		while (pos-- > 0)
		{
			if (stacks->b->value == second_value)
				(pa(&stacks->b, &stacks->a), found_second = true);
			else
				rb(&stacks->b);
		}
	}
	else
	{
		while (pos++ < size)
		{
			if (stacks->b->value == second_value)
				(pa(&stacks->b, &stacks->a), found_second = true);
			rrb(&stacks->b);
		}
	}
	return (found_second);
}

void	sort_chunks(t_stacks *stacks, int size)
{
	int		target_value ;
	int		second_value ;
	int		pos ;
	bool	found_second ;

	while (size)
	{
		found_second = false ;
		target_value = stacks->sorted[size - 1];
		pos = lst_get_index(stacks->b, target_value);
		if (size - 1)
			second_value = stacks->sorted[size - 2];
		if (pos == 1)
			sb(&stacks->b);
		else
			found_second = search_max(stacks, size, pos, second_value);
		pa(&stacks->b, &stacks->a);
		if (found_second)
			(sa(&stacks->a), size--);
		size-- ;
	}
}
