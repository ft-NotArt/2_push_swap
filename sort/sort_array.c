/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:54:02 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/15 02:28:29 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Taken straight back from C01 */
void	ft_sort_int_tab(int *tab, int size)
{
	int	pos1;
	int	pos2;
	int	pos_min;
	int	tmp;

	pos1 = 0;
	while (pos1 < size - 1)
	{
		pos_min = pos1;
		pos2 = pos1 + 1;
		while (pos2 < size)
		{
			if (tab[pos2] < tab[pos_min])
			{
				pos_min = pos2;
			}
			pos2++;
		}
		tmp = tab[pos_min];
		tab[pos_min] = tab[pos1];
		tab[pos1] = tmp;
		pos1++;
	}
}

int	*init_sorted_array(t_stacks *stacks, size_t size)
{
	int			*sorted_array ;
	t_ps_list	*current ;
	int			i ;

	sorted_array = malloc(size * sizeof(int));
	i = 0 ;
	current = stacks->a ;
	while (current)
	{
		sorted_array[i++] = current->value ;
		current = current->next ;
	}
	ft_sort_int_tab(sorted_array, size);
	return (sorted_array);
}
