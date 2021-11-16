/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:48:13 by ifluxa-c          #+#    #+#             */
/*   Updated: 2021/11/16 12:41:25 by ifluxa-c         ###   ########.fr       */
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
int		size_ls(char ***l);
void	free_aux(char ***l);

//push_swap_aux.c
int		atoi(char *str, char ***l);

//push.c
void	push_a(t_stack *stack);
void	push_b(t_stack *stack);

#endif