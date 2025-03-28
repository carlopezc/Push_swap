/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:48:59 by carlopez          #+#    #+#             */
/*   Updated: 2025/02/04 14:28:53 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

void	fill_index(t_list **stack)
{
	t_list	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->index = i++;
		tmp = tmp->next;
	}
	return ;
}

int	is_ordered(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;

	if (!*stack_a)
		return (0);
	first = *stack_a;
	second = first->next;
	while (first && second)
	{
		if (second->data < first->data)
			return (0);
		first = second;
		second = second->next;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	free_list(t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp_next;

	if (stack)
	{
		tmp = *stack;
		while (tmp)
		{
			tmp_next = tmp->next;
			free(tmp);
			tmp = tmp_next;
		}
		free(stack);
	}
	return ;
}

int	list_size(t_list **stack)
{
	t_list	*tmp;
	int		len;

	tmp = *stack;
	len = 0;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}
