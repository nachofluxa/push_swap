/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 09:38:22 by ifluxa-c          #+#    #+#             */
/*   Updated: 2023/09/06 13:46:10 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_getsign(const char *p, unsigned long *i)
{
	char	c;

	while (*(p + *i))
	{
		c = *(p + *i);
		*i = *i + 1;
		if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\r'
			|| c == '\f')
			continue ;
		if (c == '+' || c == '-')
			return ((c - 44) * (-1));
		if (ft_isdigit((int)c))
		{
			*i = *i - 1;
			return (1);
		}
		break ;
	}
	return (0);
}

size_t	ps_atoi(const char *str)
{
	unsigned long	i;
	long			sign;
	long long int	n;

	i = 0;
	sign = ft_getsign(str, &i);
	if (!sign)
		return (0);
	n = 0;
	while (ft_isdigit(str[i]))
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	if ((n >= 2147483648 || n < -2147483648) && sign == 1)
		return (6666666666);
	else if ((n > 2147483648 || n < -2147483648) && sign == -1)
		return (6666666666);
	return (sign * n);
}

int	is_number(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	if (str[0] == '-' && !str[1])
		return (0);
	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}

void	check_two_args(char **aux)
{
	int		i;
	int		j;
	long	n;

	i = -1;
	while (aux[++i])
	{
		n = ft_strlen(aux[i]);
		if (!n)
			continue ;
		if (!is_number((char *)aux[i]))
			error_message(0);
		if (ps_atoi(aux[i]) == 6666666666)
			error_message(0);
		j = i;
		while (aux[++j])
			if (n == (long)ft_strlen(aux[j]) && !ft_strncmp(aux[i],
					aux[j], n))
				error_message(0);
	}
}

void	check_3_numbers(t_list **list)
{
	if (check_just_one(list) == 0)
		order_3(list);
	else
		error_message(1);
}
