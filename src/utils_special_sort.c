/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_special_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:39:46 by carlopez          #+#    #+#             */
/*   Updated: 2025/01/31 15:39:01 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

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
