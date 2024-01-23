/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:32:32 by ifluxa-c          #+#    #+#             */
/*   Updated: 2023/09/08 11:17:56 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_object
{
	int		value;
	ssize_t	order;
}t_object;

//aux.c
t_list		*remove_first(t_list **list);
t_list		*remove_last(t_list **list);
char		**aux_split(char *to_split);
void		set_final_order(t_list **list);
void		aux_order(t_list **a, t_list **b, int size, ssize_t order);

//auxII.c
t_object	*new_obj(int value, ssize_t order);
void		set_order(t_list *list, ssize_t order);
int			obj_value(t_list *list);
ssize_t		obj_order(t_list *list);
ssize_t		set_orders(t_list **list);

//errors_aux.c
long		ft_getsign(const char *p, unsigned long *i);
size_t		ps_atoi(const char *str);
int			is_number(char *str);
void		check_two_args(char **aux);
void		check_3_numbers(t_list **list);

//errors.c
int			is_ordered(t_list **a, t_list **b);
int			check_just_one(t_list **list);
void		check_aux_list(t_list **list, t_list **aux);
void		error_message(int type);
void		check_argv(int argc, char *argv[]);

//order_list.c
void		order_3(t_list **a);
void		order_4(t_list **a, t_list **b);
void		help_order_5(t_list **a, int size, ssize_t order);
void		order_radix(t_list **a, t_list **b, ssize_t radix);
void		ini_radix(t_list **a, t_list **b, ssize_t max_order);

//push_swap.c
void		mount_two_args(char **argv);
void		free_two_args(t_list **list, char **aux, char *to_split);
void		mount_multiple_args(int argc, char **argv);

//reverse_rotate.c
void		reverse_rotate_a(t_list **a, int type);
void		reverse_rotate_b(t_list **b, int type);
void		reverse_rotate_a_b(t_list **a, t_list **b);

//rotate.c
void		rotate_a(t_list **a, int type);
void		rotate_b(t_list **b, int type);
void		rotate_a_b(t_list **a, t_list **b);

//swap.c
void		swap_a(t_list **a, int type);
void		swap_b(t_list **b, int type);
void		swap_a_b(t_list **a, t_list **b);
void		push_a(t_list **a, t_list **b);
void		push_b(t_list **a, t_list **b);

#endif