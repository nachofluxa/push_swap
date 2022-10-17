/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:03:29 by ifluxa-c          #+#    #+#             */
/*   Updated: 2022/10/17 12:33:27 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int	*a;
	int	*b;
	int *shorted;
	int chunk_size;
	int	size_a;
	int	size_b;
}t_stack;

//aux.c
int		found_min(int *list, int size);
int		found_max(int *list, int size);
int		check_nbr(char **str);
int		size_stack(t_stack *stack, int aux);

//errors.c
void	check_repeat_numbers(t_stack *stack);
void	check_argv(char *argv);
void	error_message(void);

//mount_stack.c
void	mount_stack2(t_stack *stack);
void	mount_stack3(t_stack *stack);
void	mount_stack4(t_stack *stack);
void	mount_stack5(t_stack *stack);

//push_or_swap.c
void	swap_a(t_stack *stack, int w);
void	swap_b(t_stack *stack, int w);
void	swap_a_b(t_stack *stack);

//push_swap.c
void	mount_stack(int argc, char **argv, t_stack *stack);
void	nbr_arg(t_stack *stack, int argc);
int		get_nbrs(char *aux);

//reverse_rotate.c
void	reverse_rotate_a(t_stack *stack, int w);
void	reverse_rotate_b(t_stack *stack, int w);
void	reverse_rotate_a_b(t_stack *stack);

//rotate.c
void	rotate_a(t_stack *stack, int w);
void	rotate_b(t_stack *stack, int w);
void	rotate_a_b(t_stack *stack);
void	push_a(t_stack *stack);
void	push_b(t_stack *stack);

//short_big_stack.c
void	short_big_stack(t_stack *stack);

#endif