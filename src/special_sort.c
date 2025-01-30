/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:45:12 by carlopez          #+#    #+#             */
/*   Updated: 2025/01/30 16:57:43 by carlopez         ###   ########.fr       */
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

int	is_biggest(int data, t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (data < tmp->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	pass_ordered(t_list **stack_b, t_list **stack_a)
{
	t_list	*tmp_b;
	t_list	*tmp_a;
	int		bigger;

	if (!*stack_b)
		return ;
	tmp_b = *stack_b;
	tmp_a = *stack_a;
	bigger = 0;
	if (is_biggest(tmp_b->data, stack_a))
		return (pa(stack_a, stack_b), ra(stack_a));
	else if (is_smallest(stack_a, tmp_b->data))
		return (pa(stack_a, stack_b));
	while (tmp_a)
	{
		if (tmp_b->data < tmp_a->data)
			bigger++;
		tmp_a = tmp_a->next;
	}
	if (bigger == 2 && list_size(stack_a) == 4)
		return (ra(stack_a), pa(stack_a, stack_b), sa(stack_a), rra(stack_a));
	else if ((bigger == 2 && list_size(stack_a) == 3) || bigger == 3)
		return (ra(stack_a), pa(stack_a, stack_b), rra(stack_a));
	return (rra(stack_a), pa(stack_a, stack_b), ra(stack_a), ra(stack_a));
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	pb(stack_b, stack_a);
	sort_three(stack_a);
	pass_ordered(stack_b, stack_a);
	return ;
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*first;
	int		moves;

	first = find_lowest(stack_a);
	if (first->index > (list_size(stack_a) / 2))
	{
		moves = (list_size(stack_a) - first->index);
		while (moves-- > 0)
			rra(stack_a);
	}
	else
	{
		moves = first->index;
		while (moves-- > 0)
			ra(stack_a);
	}
	pb(stack_b, stack_a);
	first = find_lowest(stack_a);
	update_index(stack_a, stack_b);
	if (first->index > (list_size(stack_a) / 2))
	{
		moves = (list_size(stack_a) - first->index);
		while (moves-- > 0)
			rra(stack_a);
	}
	else
	{
		moves = first->index;
		while (moves-- > 0)
			ra(stack_a);
	}
	if (is_ordered(stack_a))
		return (pa(stack_a, stack_b));
	pb(stack_b, stack_a);
	return (sort_three(stack_a), pa(stack_a, stack_b), pa(stack_a, stack_b));
}
