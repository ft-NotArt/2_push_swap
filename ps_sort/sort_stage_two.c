/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stage_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:14:00 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/15 19:17:16 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_nodes(t_stacks *stacks)
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
