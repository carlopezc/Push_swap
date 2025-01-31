/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:43:22 by carlopez          #+#    #+#             */
/*   Updated: 2025/01/31 15:34:00 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

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
	advance_tmp(stack, &tmp, exc, exc2);
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
