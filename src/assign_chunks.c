/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_chunks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:49:57 by carlopez          #+#    #+#             */
/*   Updated: 2025/01/23 17:12:58 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

t_list	*look_for_min(t_list **stack_a)
{
	int		min;
	t_list	*min_tmp;
	t_list	*tmp;

	tmp = *stack_a;
	min = tmp->data;
	min_tmp = tmp;
	while (tmp)
	{
		if (tmp->chunk != 0 && tmp->data == min && tmp->next)
		{
			tmp = tmp->next;
			min = tmp->data;
			min_tmp = tmp;
		}
		else if (tmp->chunk == 0 && tmp->data < min)
		{
			min = tmp->data;
			min_tmp = tmp;
			tmp = tmp->next;
		}
		else
			tmp = tmp->next;
	}
	return (min_tmp);
}

void	assign_last(t_list **stack)
{
	t_list	*tmp;
	t_list	*higher;
	int	i;

	tmp = *stack;
	higher = *stack;
	i = 0;
	while (i < 5)
	{
		tmp = *stack;
		if ((*stack)->chunk == 0)
			higher = *stack;
		else
		{
			while (tmp && tmp->chunk != 0)
				tmp = tmp->next;
			higher = tmp;
		}
		tmp = *stack;
		while (tmp)
		{
			if (tmp->data > higher->data && tmp->chunk == 0)
				higher = tmp;
			tmp = tmp->next;
		}
		higher->chunk = -1;
		i++;
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
	while (tmp)
	{
		if (tmp->chunk == 0)
			tmp->chunk = i - 1;
		tmp = tmp->next;
	}
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
	else if(size > 5 && size <= 100)
		chunks = assign_chunks(stack_a, 4, size);
	/*
	else if (size > 100 && size <= 500)
		chunks = assign_chunks(stack_a, 7, size);
	else if (size > 500)
		chunks = assign_chunks(stack_a, 11, size);
	*/
	else
		chunks = assign_chunks(stack_a, 8, size);
	//tenia puesto 5 y 11
	return (chunks);
}
