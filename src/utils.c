/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:43:22 by carlopez          #+#    #+#             */
/*   Updated: 2025/01/31 11:25:58 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

int	check_chunk(t_list **stack, int *chunk)
{
	if (!search_chunk(stack, *chunk) || search_chunk(stack, *chunk) == 1)
	{
		if (search_chunk(stack, *chunk - 1))
		{
			*chunk = *chunk - 1;
			return (1);
		}
		else
			return (0);
	}
	return (1);
}

void	find_biggest_except(t_list **stack, t_list **object, t_list **except)
{
	t_list	*biggest;
	t_list	*tmp;

	biggest = *stack;
	if (!except || !*except)
	{
		*object = find_biggest(stack);
		return ;
	}
	tmp = *stack;
	while (tmp && tmp->data >= (*except)->data)
		tmp = tmp->next;
	biggest = tmp;
	while (tmp)
	{
		if (tmp->data > biggest->data && tmp->data < (*except)->data)
			biggest = tmp;
		tmp = tmp->next;
	}
	*object = biggest;
	return ;
}

void	find_two_exc(t_list **stack, t_list **obj, t_list **exc, t_list **exc2)
{
	t_list	*biggest;
	t_list	*tmp;

	biggest = *stack;
	tmp = *stack;
	if (exc && *exc && tmp && (tmp->data >= (*exc)->data))
		tmp = tmp->next;
	if (exc2 && *exc2 && tmp && (tmp->data >= (*exc2)->data))
		tmp = tmp->next;
	biggest = tmp;
	while (tmp)
	{
		if (!exc && tmp->data > biggest->data)
			biggest = tmp;
		if (exc && tmp->data > biggest->data && tmp->data < (*exc)->data)
		{
			if (exc2 && *exc2)
			{
				if (tmp->data < (*exc2)->data)
					biggest = tmp;
			}
			else
				biggest = tmp;
		}
		tmp = tmp->next;
	}
	*obj = biggest;
	return ;
}

void	find_top_three_except(t_list **first,
	t_list **second, t_list **third, t_list *object)
{
	t_list	**b;

	b = first;
	find_two_exc(b, first, &object, NULL);
	find_two_exc(b, second, first, &object);
	find_two_exc(b, third, second, &object);
	return ;
}

void	find_top_three(t_list **stack, t_list **first,
	t_list **second, t_list **third)
{
	find_biggest_except(stack, first, NULL);
	find_biggest_except(stack, second, first);
	find_biggest_except(stack, third, second);
	return ;
}

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

int	bigger_or_lower(t_list **stack_b, int delimiter)
{
	if (!(*stack_b) || (*stack_b && (*stack_b)->data < delimiter))
		return (1);
	return (0);
}

int	find_delimiter(int chunk, t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->chunk == chunk && tmp->delimiter)
			break ;
		tmp = tmp->next;
	}
	if (tmp)
		return (tmp->data);
	return (-1);
}
