/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:27:32 by carlopez          #+#    #+#             */
/*   Updated: 2025/01/11 20:09:21 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (list_size(stack) < 2)
		return ;
	first = *stack;
	second = first->next;
	third = second->next;
	*stack = second;
	second->next = first;
	first->next = third;
	second->prev = NULL;
	first->prev = second;
	if (third)
		third->prev = first;
	return ;
}

void	sa(t_list **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
	return ;
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
	return ;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
	return ;
}
