/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:56:54 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/15 18:29:10 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool search_max(t_stacks *stacks, int size, int pos, int second_value)
{
	bool	found_second ;

	// ft_printf("pos : %d, size : %d, second_value : %d\n", pos, size, second_value) ;
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
			// else
			rrb(&stacks->b);
		}
	}
	return (found_second);
}

static void	sort_chunks(t_stacks *stacks, int size)
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

static void	sort_three_nodes(t_stacks *stacks)
{
	if ((stacks->a->next->next->value > stacks->a->value
		&& stacks->a->next->next->value < stacks->a->next->value)
		|| (stacks->a->next->next->value < stacks->a->value
		&& stacks->a->next->next->value > stacks->a->next->value))
		rra(&stacks->a);
	if ((stacks->a->next->value < stacks->a->value
		&& stacks->a->next->value < stacks->a->next->next->value)
		|| (stacks->a->value > stacks->a->next->value
		&& stacks->a->value > stacks->a->next->next->value))
		sa(&stacks->a);
	if (stacks->a->next->next->value < stacks->a->value
		&& stacks->a->next->next->value < stacks->a->next->value)
		rra(&stacks->a);
}

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
			stacks->start, (stacks->start + stacks->end) / 2))
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

static void	sort_by_chunks(t_stacks *stacks, int size)
{
	const int	offset = (size / set_offset(size));
	int			to_start ;
	int			to_end ;

	stacks->start = (size / 2) - offset ;
	if (stacks->start < 0)
		stacks->start = 0 ;
	stacks->end = (size / 2) + offset ;
	if (stacks->end > (size - 1))
		stacks->end = (size - 1);
	to_start = (size / 2) ;
	to_end = (size / 2) ;
	while (stacks->a->next->next->next)
	{
		// printf("\nto_start : %d, start : %d | to_end : %d, end : %d\n", to_start, stacks->start, to_end, stacks->end);
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

void	magic_algorithm(t_stacks *stacks, int nb_elem)
{
	sort_by_chunks(stacks, nb_elem);
	sort_three_nodes(stacks);
	sort_chunks(stacks, nb_elem - 3);
}
