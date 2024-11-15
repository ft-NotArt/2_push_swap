/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:56:54 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/15 07:15:33 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_chunks(t_stacks *stacks, int *sorted_array, int size)
{
	int	target_value ;
	int	pos ;

	while (size)
	{
		target_value = sorted_array[size - 1] ;
		pos = lst_get_index(stacks->b, target_value);
		if (pos == 1)
			sb(&stacks->b);
		else
		{
			if (pos < (size - pos))
				while (pos--)
					rb(&stacks->b);
			else
				while (pos++ < size)
					rrb(&stacks->b);
		}
		pa(&stacks->b, &stacks->a);
		size-- ;
	}
}

static void	push_chunk(t_stacks *stacks, int *sorted_array, int start, int end)
{
	const int	elem_in_a = ps_lstsize(stacks->a);
	int			i ;

	i = -1 ;
	while (++i < elem_in_a)
	{
		if (part_of_chunk(stacks->a->value, sorted_array, start, end))
		{
			pb(&stacks->a, &stacks->b);
			if (part_of_chunk(stacks->b->value, sorted_array,
				start, (start + end) / 2))
			{
				if (i < elem_in_a - 1
					&& !part_of_chunk(stacks->a->value, sorted_array, start, end))
				{
					rr(&stacks->a, &stacks->b);
					i++ ;
				}
				else
					rb(&stacks->b);
			}
		}
		else
			ra(&stacks->a);
	}
}

static void	sort_by_chunks(t_stacks *stacks, int size, int *sorted_array)
{
	const int	n = n_set(size); // is stocking n even useful ?
	const int	middle = (size / 2);
	const int	offset = (size / n);
	int			start ;
	int			end ;

	start = middle - offset ;
	if (start < 0)
		start = 0 ;
	end = middle + offset ;
	if (end > (size - 1))
		end = (size - 1);
	while (stacks->a)
	{
		// ft_printf("\n\t\t-- n : %d, size : %d, middle : %d, offset : %d, start : %d, end : %d\n", n, size, middle, offset, start, end);
		push_chunk(stacks, sorted_array, start, end);
		start -= offset ;
		if (start < 0)
			start = 0 ;
		end += offset ;
		if (end > (size - 1))
			end = (size - 1);
	}
}

void	magic_algorithm(t_stacks *stacks)
{
	const int	nb_elem = ps_lstsize(stacks->a);
	int			*sorted_array ;

	sorted_array = init_sorted_array(stacks, nb_elem);

	sort_by_chunks(stacks, nb_elem, sorted_array);
	sort_chunks(stacks, sorted_array, nb_elem);

	free(sorted_array);
}
