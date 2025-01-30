/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:12:26 by carlopez          #+#    #+#             */
/*   Updated: 2025/01/11 21:05:28 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

void	push(t_list **dest_stack, t_list **src_stack)
{
	t_list	*src_first;
	t_list	*src_second;
	t_list	*dest_first;

	if (!*src_stack)
		return ;
	src_first = *src_stack;
	src_second = src_first->next;
	dest_first = *dest_stack;
	*src_stack = src_second;
	*dest_stack = src_first;
	src_first->next = dest_first;
	src_first->prev = NULL;
	if (src_second)
		src_second->prev = NULL;
	if (dest_first)
		dest_first->prev = src_first;
	return ;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
	return ;
}

void	pb(t_list **stack_b, t_list **stack_a)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
	return ;
}
