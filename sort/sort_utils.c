/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 06:04:45 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/15 19:19:26 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_ps_list *list)
{
	t_ps_list	*current ;
	int			value ;

	current = list ;
	value = current->value ;
	while (current->next)
	{
		current = current->next;
		if (current->value < value)
			return (false);
		value = current->value;
	}
	return (true);
}

//TODO: play with different n values to see what would be more efficient
int	set_offset(int size)
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

int	lst_get_index(t_ps_list *list, int value)
{
	t_ps_list	*current ;
	int			i ;

	i = 0 ;
	current = list ;
	while (current && current->value != value)
	{
		i++ ;
		current = current->next ;
	}
	if (!current)
		return (-1);
	return (i);
}

bool	chunk_part(int value, int *sorted_array, int start, int end)
{
	return (value >= sorted_array[start]
		&& value <= sorted_array[end]);
}
