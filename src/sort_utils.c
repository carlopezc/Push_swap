/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:48:55 by carlopez          #+#    #+#             */
/*   Updated: 2025/01/31 13:44:55 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

void	update_index(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		index;

	if (stack_a && *stack_a)
	{
		tmp = *stack_a;
		index = 0;
		while (tmp)
		{
			tmp->index = index++;
			tmp = tmp->next;
		}
	}
	if (stack_b && *stack_b)
	{
		tmp = *stack_b;
		index = 0;
		while (tmp)
		{
			tmp->index = index++;
			tmp = tmp->next;
		}
	}
	return ;
}

int	is_smallest(t_list **stack, int data)
{
	t_list	*tmp;

	if (!*stack)
		return (1);
	tmp = *stack;
	while (tmp)
	{
		if (data > tmp->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	pass_and_swap(int data, int chunk, t_list **stack_b, t_list **stack_a)
{
	t_list	*tmp;
	int		moves;
	int		i;

	if (!*stack_b)
		return ;
	tmp = *stack_b;
	moves = 0;
	while (tmp)
	{
		if (chunk != tmp->chunk)
			break ;
		if (data < tmp->data)
			moves++;
		tmp = tmp->next;
	}
	if (moves == 1)
		return (pb(stack_b, stack_a), sb(stack_b));
	i = 0;
	while (i++ < moves)
		rb(stack_b);
	pb(stack_b, stack_a);
	while (moves-- > 0)
		rrb(stack_b);
	return ;
}

void	check_order(t_list **stack_a, t_list **stack_b)
{
	int	chunk;
	int	data;

	if (!*stack_a)
		return ;
	chunk = (*stack_a)->chunk;
	data = (*stack_a)->data;
	if (find_chunk(stack_b, chunk) < 2 && is_smallest(stack_b, data))
		return (pb(stack_b, stack_a));
	return (pass_and_swap(data, chunk, stack_b, stack_a));
}

void	move_back(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!*stack_b)
		return ;
	tmp = *stack_b;
	while (tmp)
	{
		pa(stack_a, stack_b);
		tmp = *stack_b;
	}
	return ;
}
