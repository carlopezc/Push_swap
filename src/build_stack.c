/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:01:27 by carlopez          #+#    #+#             */
/*   Updated: 2025/01/31 10:56:08 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

t_list	*lstnew(int num)
{
	t_list	*object;

	object = (t_list *)malloc(sizeof(t_list));
	if (!object)
		return (NULL);
	object->index = 0;
	object->data = num;
	object->prev = NULL;
	object->next = NULL;
	object->chunk = 0;
	object->delimiter = 0;
	return (object);
}

void	connect_list(t_list **stack_a, t_list *object)
{
	t_list	*tmp;

	tmp = *stack_a;
	if (!*stack_a)
	{
		*stack_a = object;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = object;
	object->prev = tmp;
	return ;
}

int	fill_stack_a(t_list **stack_a, char **argv, int argc)
{
	int		i;
	long	num;
	t_list	*object;

	i = 1;
	while (i < argc)
	{
		if (!check_str(argv[i]))
			return (0);
		num = atol(argv[i]);
		if (is_repeated(stack_a, num) || !is_int(num))
			return (0);
		object = lstnew(num);
		connect_list(stack_a, object);
		i++;
	}
	return (1);
}
