/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:56:54 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/15 03:34:18 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	n_set(int size) //TODO: play with different n values to see what would be more efficient
{
	if (size <= 5)
		return (1);
	if (size <= 10)
		return (5);
	if (size <= 150)
		return (8);
	else
		return (18);
}

static void	push_chunk(t_stacks *stacks, int *sorted_array, int start, int end)
{
	const int	elem_in_a = ps_lstsize(stacks->a);
	int			i ;

	i = 0 ;
	while (i < elem_in_a)
	{
		if (stacks->a->value >= sorted_array[start] // should it be >= or > ?
			&& stacks->a->value <= sorted_array[end])
		{
			pb(&stacks->a, &stacks->b);
			if (stacks->b->value >= sorted_array[(start + end) / 2] // should it be >= or > ?
				&& stacks->b->value <= sorted_array[end])
				rb(&stacks->b);
		}
		else
			ra(&stacks->a);
		i++ ;
	}
}

static void	sort_by_chunks(t_stacks *stacks, int size, int *sorted_array)
{
	const int	n = n_set(size); // is stocking n even useful ?
	const int	middle = (size / 2);
	const int	offset = (size / n);
	int			start ;
	int			end ;

	start = middle - offset ; // when initializing and changing those values,
	if (start < 0)
		start = 0 ;
	end = middle + offset ; // beware of not setting start under 0 and end after size
	if (end > (size - 1)) // It is size - 1 right ?
		end = (size - 1);
	while (stacks->a)
	{
		ft_printf("\n\t\t-- n : %d, size : %d, middle : %d, offset : %d, start : %d, end : %d\n", n, size, middle, offset, start, end);
		push_chunk(stacks, sorted_array, start, end);
		start -= offset ;
		if (start < 0)
			start = 0 ;
		end += offset ;
		if (end > (size - 1)) // It is size - 1 right ?
			end = (size - 1);
	}
}

void	magic_algorithm(t_stacks *stacks)
{
	const int	a_size = ps_lstsize(stacks->a);
	int			*sorted_array ;

	sorted_array = init_sorted_array(stacks, a_size);

	for (int i = 0; i < a_size; i++)
		ft_printf(">%d\n", sorted_array[i]);

	sort_by_chunks(stacks, a_size, sorted_array);
	
	free(sorted_array);
}
