/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:44:55 by carlopez          #+#    #+#             */
/*   Updated: 2025/01/11 20:28:33 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*tmp_last;
	t_list	*tmp_second;
	t_list	*tmp;

	if (list_size(stack) < 2)
		return ;
	tmp = *stack;
	tmp_last = *stack;
	tmp_second = tmp->next;
	*stack = tmp_second;
	tmp_second->prev = NULL;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = tmp_last;
	tmp_last->prev = tmp;
	tmp_last->next = NULL;
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
	return ;
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
	return ;
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
	return ;
}
