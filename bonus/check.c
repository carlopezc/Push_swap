/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:01:41 by carlopez          #+#    #+#             */
/*   Updated: 2025/02/03 17:59:03 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

int	ft_strncmp(char *a, char *b, int size)
{
	int	i;

	if (!a || !b)
		return (-1);
	i = 0;
	while (a[i] && b[i] && i < size )
	{
		if (a[i] != b[i])
		{
			ft_printf("Devuelvo %i\n", a[i] - b[i]);
			return (a[i] - b[i]);
		}
		i++;
	}
	ft_printf("Devuelvo %i, la primera %i, la segunda %i\n", a[i] - b[i], a[i], b[i]);
	if (!a[i] && !b[i])
		return (0);
	return (a[i] - b[i]);
}

int	aux_make(t_list **a, t_list **b, char *instruction)
{
	ft_printf("instruction es %s\n", instruction);
	if (ft_strncmp(instruction, "ra", ft_strlen(instruction)) == 0)
		return (ra(a), 1);
	else if (ft_strncmp(instruction, "rb", ft_strlen(instruction)) == 0)
		return (rb(b), 1);
	else if (ft_strncmp(instruction, "rr", ft_strlen(instruction)) == 0)
		return (rr(a, b), 1);
	else if (ft_strncmp(instruction, "rra", ft_strlen(instruction)) == 0)
		return (rra(a), 1);
	else if (ft_strncmp(instruction, "rrb", ft_strlen(instruction)) == 0)
		return (rrb(b), 1);
	else if (ft_strncmp(instruction, "rrr", ft_strlen(instruction)) == 0)
		return (rrr(a, b), 1);
	return (write(2, "Error\n", 6), -1);
}

int	make(t_list **a, t_list **b, char *instruction)
{
	if (ft_strlen(instruction) < 2)
		return (write(2, "Error\n", 6), -1);
	if (ft_strncmp(instruction, "sa", ft_strlen(instruction)) == 0)
		return (sa(a), 1);
	else if (ft_strncmp(instruction, "sb", ft_strlen(instruction)) == 0)
		return (sb(b), 1);
	else if (ft_strncmp(instruction, "ss", ft_strlen(instruction)) == 0)
		return (ss(a, b), 1);
	else if (ft_strncmp(instruction, "pa", ft_strlen(instruction)) == 0)
		return (pa(a, b), 1);
	else if (ft_strncmp(instruction, "pb", ft_strlen(instruction)) == 0)
		return (pb(b, a), 1);
	return (aux_make(a, b, instruction));
}

int	check_and_make(t_list **a, t_list **b)
{
	char	*instruction;

	instruction = get_next_line(1);
	if (!instruction || !make(a, b, instruction))
		return (-1);
	while (instruction)
	{
		instruction = get_next_line(1);
		if (!instruction || !make(a, b, instruction))
			return (-1);
	}
	return (1);
}

