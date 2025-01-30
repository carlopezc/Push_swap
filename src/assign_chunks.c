/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_chunks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:49:57 by carlopez          #+#    #+#             */
/*   Updated: 2025/01/30 16:34:23 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

t_list	*assign_last_utils(t_list **stack, t_list *tmp, t_list *higher)
{
	if (tmp && tmp->chunk == 0)
		higher = *stack;
	else
	{
		while (tmp && tmp->chunk != 0)
			tmp = tmp->next;
		higher = tmp;
	}
	while (tmp)
	{
		if (tmp->data > higher->data && tmp->chunk == 0)
			higher = tmp;
		tmp = tmp->next;
	}
	return (higher);
}

void	assign_last(t_list **stack)
{
	t_list	*tmp;
	t_list	*higher;
	int		i;

	tmp = *stack;
	higher = *stack;
	i = 0;
	while (i < 5)
	{
		tmp = *stack;
		higher = assign_last_utils(stack, tmp, higher);
		higher->chunk = -1;
		i++;
	}
	return ;
}

void	add_last_chunk(t_list *tmp, int i)
{
	while (tmp)
	{
		if (tmp->chunk == 0)
			tmp->chunk = i - 1;
		tmp = tmp->next;
	}
	return ;
}

int	assign_chunks(t_list **stack_a, int num, int size)
{
	int		rank;
	int		i;
	t_list	*tmp;

	i = 1;
	tmp = *stack_a;
	assign_last(stack_a);
	while (i <= num)
	{
		rank = size / num;
		while (rank > 0)
		{
			tmp = look_for_min(stack_a);
			tmp->chunk = i;
			if (rank == (size / num) / 2)
				tmp->delimiter = 1;
			rank--;
		}
		i++;
	}
	tmp = *stack_a;
	add_last_chunk(tmp, i);
	return (i - 1);
}

int	set_chunks(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	chunks;

	if (!*stack_a)
		return (0);
	chunks = 0;
	size = list_size(stack_a);
	if (size <= 5)
		return (special_sort(stack_a, stack_b, size), -1);
	size = list_size(stack_a) - 5;
	if (size <= 5)
		chunks = assign_chunks(stack_a, size, size);
	else if (size > 5 && size <= 100)
		chunks = assign_chunks(stack_a, 4, size);
	else
		chunks = assign_chunks(stack_a, 8, size);
	return (chunks);
}
