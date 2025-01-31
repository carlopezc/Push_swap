/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:23:27 by carlopez          #+#    #+#             */
/*   Updated: 2025/01/31 13:26:14 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

int	check_lowest(t_list **stack_b, t_list **stack_a)
{
	t_list	*last;

	last = find_last(stack_a);
	if ((find_lowest(stack_b) == *stack_b)
		&& (list_size(stack_b) > 2)
		&& (last == find_biggest(stack_a) || last->data < (*stack_b)->data))
		return (pa(stack_a, stack_b), ra(stack_a), 1);
	return (0);
}

int	check_swap(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	if (tmp && tmp->next)
	{
		if (tmp->data < (tmp->next)->data && tmp->chunk == (tmp->next)->chunk)
			return (1);
		return (0);
	}
	return (0);
}

int	check_chunk(t_list **stack, int *chunk)
{
	if (!find_chunk(stack, *chunk) || find_chunk(stack, *chunk) == 1)
	{
		if (find_chunk(stack, *chunk - 1))
		{
			*chunk = *chunk - 1;
			return (1);
		}
		else
			return (0);
	}
	return (1);
}

void	advance_tmp(t_list **stack, t_list **tmp, t_list **exc, t_list **exc2)
{
	*tmp = *stack;
	if (exc && *exc && tmp && ((*tmp)->data >= (*exc)->data))
		(*tmp) = (*tmp)->next;
	if (exc2 && *exc2 && (*tmp) && ((*tmp)->data >= (*exc2)->data))
		(*tmp) = (*tmp)->next;
	return ;
}

int	bigger_or_lower(t_list **stack_b, int delimiter)
{
	if (!(*stack_b) || (*stack_b && (*stack_b)->data < delimiter))
		return (1);
	return (0);
}
