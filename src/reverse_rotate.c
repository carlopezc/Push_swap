/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:53:54 by carlopez          #+#    #+#             */
/*   Updated: 2025/01/11 20:32:50 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*tmp_last;
	t_list	*tmp_first;

	if (list_size(stack) < 2)
		return ;
	tmp_first = *stack;
	tmp_last = *stack;
	while (tmp_last->next)
		tmp_last = tmp_last->next;
	(tmp_last->prev)->next = NULL;
	*stack = tmp_last;
	tmp_last->prev = NULL;
	tmp_last->next = tmp_first;
	tmp_first->prev = tmp_last;
	return ;
}

void	rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
	return ;
}

void	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
	return ;
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
	return ;
}
