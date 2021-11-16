#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack stack;
	if (argc = 1)
		exit(0);
	create_list(&stack, argc, argv);
}

void create_list(t_stack *stack, int argc, char **argv)
{
	char ***l;
	int i;
	int j;

	l = NULL;
	i = -1;
	j = 0;

	l = malloc(sizeof(char**) * argc);
	while (i++ < argc - 1)
	{
		argv = argv + 1;
		l[i] = ft_split((char *)argv, ' ');
	}
	stack->a = malloc(sizeof(int) * size_l(l));
	stack->b = malloc(sizeof(int) * size_l(l));
	while (j++ < argc - 1)
	{
		i = 0;
		while (i++)
		{
			l[j] = atoi(l);
		}
	}
}

int size_ls(char ***l)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (l[i])
	{
		j = 0;
		while (l[i][j])
		{
			j++;
			count++;
		}
		i++;
	}
	return (count);
}

int atoi(char *str, char ***l)
{
	int		i;
	int	num;
	int signo;

	i = 0;
	num = 0;
	signo = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signo++;
		i++;
	}
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	free_aux(l);
	if ((num == 2147483647) || (num == -2147483648))
		exit(0);

	return (signo * num);
}

void free_aux(char ***l)
{
	int i;
	int j;

	i = 0;
	while (l[i])
	{
		j = 0;
		while (l[i][j])
		{
			free(l[i][j]);
			j++;
		}
		free(l[i]);
		i++;
	}
	free(l);
}
