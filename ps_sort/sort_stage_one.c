/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stage_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:13:04 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/17 00:26:10 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_node(t_stacks *stacks, int *to_start, int *to_end, int size)
{
	if (chunk_part(stacks->a->value, stacks->sorted,
			stacks->start, stacks->end)
		&& stacks->a->value != stacks->sorted[size - 1]
		&& stacks->a->value != stacks->sorted[size - 2]
		&& stacks->a->value != stacks->sorted[size - 3])
	{
		pb(&stacks->a, &stacks->b);
		if (chunk_part(stacks->b->value, stacks->sorted,
				stacks->start, (stacks->start + stacks->end) / 2)
			&& stacks->b->next)
		{
			(*to_start)-- ;
			if (stacks->a && !chunk_part(stacks->a->value, stacks->sorted,
					stacks->start, stacks->end))
				rr(&stacks->a, &stacks->b);
			else
				rb(&stacks->b);
		}
		else
			(*to_end)++ ;
	}
	else
		ra(&stacks->a);
}

void	sort_by_chunks(t_stacks *stacks, int size)
{
	const int	offset = (size / set_offset(size));
	int			to_start ;
	int			to_end ;

	set_start(stacks, size, offset);
	set_end(stacks, size, offset);
	to_start = (size / 2);
	to_end = (size / 2);
	while (stacks->a->next->next->next)
	{
		push_node(stacks, &to_start, &to_end, size);
		if (to_start == stacks->start)
		{
			stacks->start -= offset ;
			if (stacks->start < 0)
				stacks->start = 0 ;
		}
		if (to_end == stacks->end)
		{
			stacks->end += offset ;
			if (stacks->end > (size - 1))
				stacks->end = (size - 1);
		}
	}
}
