/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:17:38 by carlopez          #+#    #+#             */
/*   Updated: 2025/03/06 11:37:26 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

void	aux_move_back_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;
	t_list	*best;

	find_top_three(stack_b, &first, &second, &third);
	best = first;
	while (best)
	{
		best = choose_cheaper(stack_a, stack_b, first, second);
		best = choose_cheaper(stack_a, stack_b, best, third);
		if (!best)
			break ;
		put_first_back(stack_a, stack_b, best);
		put_null(best, &first, &second, &third);
	}
	return ;
}

void	move_back_to_a(t_list **stack_a, t_list **stack_b)
{
	while (stack_b && *stack_b)
	{
		update_index(stack_a, stack_b);
		if (!check_lowest(stack_b, stack_a))
			aux_move_back_a(stack_a, stack_b);
	}
	return ;
}

void	put_first(t_list **stack_a, t_list **stack_b, int chunk, int delimiter)
{
	t_list	*object;

	object = *stack_a;
	if (!object)
		return ;
	if (object->data < delimiter && object->next
		&& (object->next)->chunk != chunk && list_size(stack_a) > 6)
	{
		if (bigger_or_lower(stack_b, delimiter))
			return (pb(stack_b, stack_a));
		return (pb(stack_b, stack_a), rr(stack_a, stack_b));
	}
	if (object->data < delimiter)
	{
		if (bigger_or_lower(stack_b, delimiter))
			return (pb(stack_b, stack_a));
		return (pb(stack_b, stack_a), rb(stack_b));
	}
	return (pb(stack_b, stack_a));
}

void	choose_objects(t_list **stack_a, t_list **stack_b, int i, int delimiter)
{
	while (*stack_a && find_chunk(stack_a, i))
	{
		if ((*stack_a)->chunk == i)
			put_first(stack_a, stack_b, i, delimiter);
		else
			ra(stack_a);
	}
	return ;
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	delimiter;
	int	chunks;

	chunks = set_chunks(stack_a, stack_b);
	if (chunks == -1)
		return ;
	i = 1;
	while (i <= chunks)
	{
		delimiter = find_delimiter(i, stack_a);
		while (find_chunk(stack_a, i))
		{
			update_index(stack_a, stack_b);
			choose_objects(stack_a, stack_b, i, delimiter);
		}
		i++;
	}
	update_index(stack_a, stack_b);
	sort_five(stack_a, stack_b);
	move_back_to_a(stack_a, stack_b);
	order_a(stack_a, NULL);
	return ;
}
