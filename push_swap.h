/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 02:31:42 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/14 01:49:17 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "libft/printf/ft_printf.h" //TODO: replace relative paths by only header names and put -Ilibft -Iprintf in Makefile
// # include <stdbool.h>

void	sa(t_list **top_a);
void	sb(t_list **top_b);
void	ss(t_list **top_a, t_list **top_b);
void	pa(t_list **top_b, t_list **top_a);
void	pb(t_list **top_a, t_list **top_b);
void	ra(t_list **top_a);
void	rb(t_list **top_b);
void	rr(t_list **top_a, t_list **top_b);
void	rra(t_list **top_a);
void	rrb(t_list **top_b);
void	rrr(t_list **top_a, t_list **top_b);

#endif