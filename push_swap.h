/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 02:31:42 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/15 19:01:41 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

/**
 * @struct A classic linked list,
 * but that can only take int as a content
 */
typedef struct s_ps_list
{
	int					value;
	struct s_ps_list	*next;
}					t_ps_list;

/**
 * @struct A single struct to keep track of both stacks
 */
typedef struct s_stacks
{
	t_ps_list	*a;
	t_ps_list	*b;
	int			*sorted;
	int			start;
	int			end;
}					t_stacks;

void		sa(t_ps_list **top_a);
void		sb(t_ps_list **top_b);
void		ss(t_ps_list **top_a, t_ps_list **top_b);
void		pa(t_ps_list **top_b, t_ps_list **top_a);
void		pb(t_ps_list **top_a, t_ps_list **top_b);
void		ra(t_ps_list **top_a);
void		rb(t_ps_list **top_b);
void		rr(t_ps_list **top_a, t_ps_list **top_b);
void		rra(t_ps_list **top_a);
void		rrb(t_ps_list **top_b);
void		rrr(t_ps_list **top_a, t_ps_list **top_b);

int			parsing(int argc, char *argv[]);

t_stacks	*stacks_init(int argc, char *argv[]);
void		set_start(t_stacks *stacks, int size, int offset);
void		set_end(t_stacks *stacks, int size, int offset);
void		stacks_free(t_stacks *stacks);

t_ps_list	*ps_lstnew(int value);
int			ps_lstsize(t_ps_list *lst);
t_ps_list	*ps_lstlast(t_ps_list *lst);
t_ps_list	*ps_lstsecond_to_last(t_ps_list *lst);
void		ps_lstadd_back(t_ps_list **lst, t_ps_list *new);
void		ps_lstclear(t_ps_list **lst);

int			*init_sorted_array(t_stacks *stacks, size_t size);

bool		is_sorted(t_ps_list *list);
void		magic_algorithm(t_stacks *stacks, int nb_elem);
int			set_offset(int size);
bool		chunk_part(int value, int *sorted_array, int start, int end);
int			lst_get_index(t_ps_list *list, int value);

#endif