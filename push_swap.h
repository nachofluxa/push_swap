/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:48:13 by ifluxa-c          #+#    #+#             */
/*   Updated: 2021/12/07 16:31:28 by ifluxa-c         ###   ########.fr       */
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
	int	max;
	int	min;
}t_stack;

//push_swap.c
void	create_list(t_stack *stack, int argc, char **argv);
int		size_l(char ***l);
void	free_aux(char ***l);

//push_swap_aux.c
int		atoi2(char *str);
int		size_a(t_stack *stack);
int		size_b(t_stack *stack);
void	error_message(void);
void	is_nbr(int argc, char **argv);

//push_swap_aux2.c
void	nbr_arg(int argc, char **argv);

//push_or_swap.c
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_a_b(t_stack *stack);
void	push_a(t_stack *stack);
void	push_b(t_stack *stack);

//rotate.c
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_a_b(t_stack *stack);

//reverse_rotate.c
void	reverse_rotate_a(t_stack *stack);
void	reverse_rotate_b(t_stack *stack);
void	reverse_rotate_a_b(t_stack *stack);

#endif