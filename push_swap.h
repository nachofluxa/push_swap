/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:03:29 by ifluxa-c          #+#    #+#             */
/*   Updated: 2022/11/11 13:17:08 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	*sorted;
	int	chunk_size;
	int	size_a;
	int	size_b;
}t_stack;

//aux.c
int		found_min(int *list, int size);
int		found_max(int *list, int size);
int		check_nbr(char **str);
int		size_stack(t_stack *stack, int aux);
void	free_stack(t_stack *stack);

//errors.c
void	check_repeat_numbers(t_stack *stack);
void	check_argv(char *argv);
void	error_message(void);
int		check_if_sorted(t_stack *stack);

//ft_radix.c
void	radix_sort(t_stack *stack);

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
int		try_nbr(int a, int *sorted, int size);
void	booble_sort(t_stack *stack);
void	rotate_and_push_a(int aux, t_stack *stack);
void	rotate_and_push_b(int aux, t_stack *stack);
void	sort_big_stack(t_stack *stack);

//short_big_stack_aux.c
int		side_of_nbr(int aux, int *stack, int size);
int		best_nbr(t_stack *stack, int compare[]);
int		any_chunk_left(int *stack, int size, int compare[], int *sorted);

#endif