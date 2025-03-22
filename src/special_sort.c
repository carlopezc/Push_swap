/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:45:12 by carlopez          #+#    #+#             */
/*   Updated: 2025/02/03 10:47:37 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

void	special_sort(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 2)
		return (sa(stack_a));
	else if (size == 3)
		return (sort_three(stack_a));
	else if (size == 4)
		return (sort_four(stack_a, stack_b));
	else if (size == 5)
		return (sort_five(stack_a, stack_b));
}

void	sort_three(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (!*stack_a)
		return ;
	first = *stack_a;
	second = first->next;
	third = second->next;
	if (is_ordered(stack_a))
		return ;
	if (first->data > second->data && third->data > second->data)
	{
		if (first->data < third->data)
			return (sa(stack_a));
		return (ra(stack_a));
	}
	else if (second->data > first->data && second->data > third->data)
	{
		if (first->data > third->data)
			return (rra(stack_a));
		return (sa(stack_a), ra(stack_a));
	}
	return (ra(stack_a), sa(stack_a));
}

void	aux_sort_five(t_list **stack_a, t_list **stack_b, t_list **first)
{
	int	moves;

	update_index(stack_a, stack_b);
	*first = find_lowest(stack_a);
	if (*first && (*first)->index > (list_size(stack_a) / 2))
	{
		moves = (list_size(stack_a) - (*first)->index);
		while (moves-- > 0)
			rra(stack_a);
	}
	else
	{
		moves = (*first)->index;
		while (moves-- > 0)
			ra(stack_a);
	}
	return ;
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	t_list	*first;

	aux_sort_five(stack_a, stack_b, &first);
	if (is_ordered(stack_a))
		return (pa(stack_a, stack_b));
	pb(stack_b, stack_a);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	return ;
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*first;

	aux_sort_five(stack_a, stack_b, &first);
	if (is_ordered(stack_a))
		return ;
	pb(stack_b, stack_a);
	aux_sort_five(stack_a, stack_b, &first);
	if (is_ordered(stack_a))
		return (pa(stack_a, stack_b));
	pb(stack_b, stack_a);
	return (sort_three(stack_a), pa(stack_a, stack_b), pa(stack_a, stack_b));
}
