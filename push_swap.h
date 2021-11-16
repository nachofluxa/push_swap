#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int *a;
	int *b;
	int size_a;
	int size_b;
	int max;
	int min;
}t_stack;

//push_swap.c
void	create_list(t_stack *stack, int argc, char **argv);
int 	size_ls(char ***l);
void	free_aux(char ***l);
int		atoi(char *str, char ***l);




#endif