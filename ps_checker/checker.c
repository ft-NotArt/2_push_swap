/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:11:03 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/16 21:55:59 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	*get_all_lines(int fd)
{
	char	*instructions ;
	char	*gnl ;
	char	*tmp ;

	instructions = ft_strdup("");
	gnl = get_next_line(fd);
	while (gnl)
	{
		tmp = ft_strjoin(instructions, gnl);
		free(instructions);
		free(gnl);
		instructions = tmp ;
		gnl = get_next_line(fd);
	}
	return (instructions);
}

static bool	is_only_instructions(char *instructions)
{
	bool	res;

	res = true ;
	while (res && *instructions)
	{
		if (!ft_strncmp(instructions, "pa\n", 3)
			|| !ft_strncmp(instructions, "pb\n", 3)
			|| !ft_strncmp(instructions, "sa\n", 3)
			|| !ft_strncmp(instructions, "sb\n", 3)
			|| !ft_strncmp(instructions, "ss\n", 3)
			|| !ft_strncmp(instructions, "ra\n", 3)
			|| !ft_strncmp(instructions, "rb\n", 3)
			|| !ft_strncmp(instructions, "rr\n", 3)
			|| !ft_strncmp(instructions, "rra\n", 4)
			|| !ft_strncmp(instructions, "rrb\n", 4)
			|| !ft_strncmp(instructions, "rrr\n", 4))
			instructions = ft_strchr((const char *) instructions, '\n') + 1;
		else
			res = false ;
	}
	return (res);
}

static void	choose_instruction(t_stacks *stacks, char *instructions)
{
	if (!ft_strncmp(instructions, "pa\n", 3))
		pa(&stacks->b, &stacks->a);
	if (!ft_strncmp(instructions, "pb\n", 3))
		pb(&stacks->a, &stacks->b);
	if (!ft_strncmp(instructions, "sa\n", 3))
		sa(&stacks->a);
	if (!ft_strncmp(instructions, "sb\n", 3))
		sb(&stacks->b);
	if (!ft_strncmp(instructions, "ss\n", 3))
		ss(&stacks->a, &stacks->b);
	if (!ft_strncmp(instructions, "ra\n", 3))
		ra(&stacks->a);
	if (!ft_strncmp(instructions, "rb\n", 3))
		rb(&stacks->b);
	if (!ft_strncmp(instructions, "rr\n", 3))
		rr(&stacks->a, &stacks->b);
	if (!ft_strncmp(instructions, "rra\n", 4))
		rra(&stacks->a);
	if (!ft_strncmp(instructions, "rrb\n", 4))
		rrb(&stacks->b);
	if (!ft_strncmp(instructions, "rrr\n", 4))
		rrr(&stacks->a, &stacks->b);
}

static void	do_instructions(t_stacks *stacks, char *instructions)
{
	while (*instructions)
	{
		choose_instruction(stacks, instructions);
		instructions = ft_strchr((const char *) instructions, '\n') + 1;
	}
}

int	main(int argc, char *argv[])
{
	const int	nb_elem = argc - 1 ;
	t_stacks	*stacks ;
	char		*instructions ;

	if (argc == 1)
		return (0);
	if (!parsing(argc, argv))
		return (ft_printf("Error\a\n"), 1);
	stacks = stacks_init(nb_elem, argv);
	if (!stacks)
		return (1);
	instructions = get_all_lines(STDIN_FILENO);
	if (!is_only_instructions(instructions))
		ft_printf("gaga\a\n");
	else
	{
		do_instructions(stacks, instructions);
		if (is_sorted(stacks->a) && !stacks->b)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	free(instructions);
	stacks_free(stacks);
	return (0);
}
