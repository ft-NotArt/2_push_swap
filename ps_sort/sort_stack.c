/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:56:54 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/15 19:15:15 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	magic_algorithm(t_stacks *stacks, int nb_elem)
{
	if (nb_elem == 2)
		sa(&stacks->a);
	else
	{
		sort_by_chunks(stacks, nb_elem);
		sort_three_nodes(stacks);
		sort_chunks(stacks, nb_elem - 3);
	}
}
