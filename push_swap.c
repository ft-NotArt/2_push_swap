/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 02:31:30 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/15 18:57:32 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	const int	nb_elem = argc - 1 ;
	t_stacks	*stacks ;

	if (argc == 1)
		return (0);
	if (!parsing(argc, argv))
		return (ft_printf("Error\a\n"), 1);
	stacks = stacks_init(nb_elem, argv);
	if (!stacks)
		return (1);
	if (!is_sorted(stacks->a))
		magic_algorithm(stacks, nb_elem);
	stacks_free(stacks);
	return (0);
}
