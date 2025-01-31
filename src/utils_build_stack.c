/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_build_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:10:03 by carlopez          #+#    #+#             */
/*   Updated: 2025/01/31 10:56:39 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

int	is_int(long num)
{
	if (num < -2147483648 || num > 2147483647)
		return (0);
	return (1);
}

int	check_length(char *str)
{
	int	i;

	i = 0;
	while (str && str[i + 1] != '\0' && str[i] == '0')
		i++;
	str = str + i;
	if ((str[0] == '-' && ft_strlen(str) > 11)
		|| (str[0] != '-' && ft_strlen(str) > 10))
		return (0);
	return (1);
}

int	check_str(char *str)
{
	int	i;

	if (!str || !check_length(str))
		return (0);
	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

long	ft_atol(char *str)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - '0');
	return (num * sign);
}

int	is_repeated(t_list **stack_a, int num)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (num == tmp->data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
