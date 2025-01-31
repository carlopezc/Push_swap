/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_utils_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:12:24 by carlopez          #+#    #+#             */
/*   Updated: 2025/01/31 13:44:38 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

t_list	*find_lowest(t_list **stack)
{
	t_list	*tmp;
	t_list	*lowest;

	tmp = *stack;
	lowest = *stack;
	while (tmp)
	{
		if (tmp->data < lowest->data)
			lowest = tmp;
		tmp = tmp->next;
	}
	return (lowest);
}

t_list	*find_biggest(t_list **stack)
{
	t_list	*tmp;
	t_list	*biggest;

	biggest = *stack;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->data > biggest->data)
			biggest = tmp;
		tmp = tmp->next;
	}
	return (biggest);
}

t_list	*find_last(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	find_chunk(t_list **stack_a, int i)
{
	t_list	*tmp;
	int		count;

	tmp = *stack_a;
	count = 0;
	while (tmp)
	{
		if (tmp->chunk == i)
			count++;
		tmp = tmp->next;
	}
	return (count);
}
