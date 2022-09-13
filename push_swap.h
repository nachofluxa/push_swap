/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:03:29 by ifluxa-c          #+#    #+#             */
/*   Updated: 2022/09/13 12:08:16 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}t_stack;

//push_swap.c
void	mount_stack(int argc, char **argv, t_stack *stack);
void	nbr_arg(int argc, t_stack *stack);

//aux.c
int		found_min(int *list);
int		found_max(int *list);
int		check_nbr(char **str);
int		size_stack(t_stack *stack, int aux);
void	error_message(void);

//mount_stack.c
void	sort_small_stack(t_stack *stack, int w);
void	sort_big_stack(t_stack *stack);

//push_or_swap.c
void	swap_a(t_stack *stack, int w);
void	swap_b(t_stack *stack, int w);
void	swap_a_b(t_stack *stack);

//rotate.c
void	rotate_a(t_stack *stack, int w);
void	rotate_b(t_stack *stack, int w);
void	rotate_a_b(t_stack *stack);
void	push_a(t_stack *stack);
void	push_b(t_stack *stack);

//reverse_rotate.c
void	reverse_rotate_a(t_stack *stack, int w);
void	reverse_rotate_b(t_stack *stack, int w);
void	reverse_rotate_a_b(t_stack *stack);

#endif