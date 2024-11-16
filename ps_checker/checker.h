/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 02:31:42 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/17 00:18:14 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

void	check_sa(t_ps_list **top_a);
void	check_sb(t_ps_list **top_b);
void	check_ss(t_ps_list **top_a, t_ps_list **top_b);
void	check_pa(t_ps_list **top_b, t_ps_list **top_a);
void	check_pb(t_ps_list **top_a, t_ps_list **top_b);
void	check_ra(t_ps_list **top_a);
void	check_rb(t_ps_list **top_b);
void	check_rr(t_ps_list **top_a, t_ps_list **top_b);
void	check_rra(t_ps_list **top_a);
void	check_rrb(t_ps_list **top_b);
void	check_rrr(t_ps_list **top_a, t_ps_list **top_b);

#endif