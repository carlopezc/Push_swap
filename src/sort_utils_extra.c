/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:30:46 by carlopez          #+#    #+#             */
/*   Updated: 2025/01/31 15:07:25 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

void	final_moves_to_a(int moves, t_list *object, t_list **a, t_list **b)
{
	int	size;

	update_index(a, b);
	size = list_size(b);
	if (moves > 0)
	{
		while (moves-- > 0)
		{
			if (object && object->index <= (size / 2))
			{
				rb(b);
				if (check_lowest(b, a))
					moves--;
			}
			else
				rrb(b);
		}
	}
	return ;
}

void	make_movements(t_list **a, t_list **b, int flag, t_list *object)
{
	t_list	*next;

	update_index(a, b);
	if (flag == 2 || flag == 3)
		ra(a);
	pa(a, b);
	if (flag != 0)
	{
		if (check_swap(b))
			ss(a, b);
		else
			sa(a);
	}
	if (flag == 3)
	{
		next = choose_next_object(a, b, object);
		if (next && next->index > (list_size(b) / 2))
			rrr(a, b);
		else
			flag = 2;
	}
	if (flag == 2)
		rra(a);
	return ;
}

void	order_a(t_list	**a, t_list **b)
{
	t_list	*lowest;
	int		moves;
	int		size;

	lowest = find_lowest(a);
	size = list_size(a);
	update_index(a, b);
	if (lowest && lowest->index > (size / 2))
	{
		moves = size - lowest->index;
		while (moves-- > 0)
			rra(a);
	}
	else
	{
		moves = lowest->index;
		while (moves-- > 0)
			ra(a);
	}
	return ;
}

int	choose_chunk(t_list **b, t_list *object)
{
	int	chunk;

	if (!object)
		return (-1);
	chunk = object->chunk;
	if (!find_chunk(b, chunk))
	{
		if (find_chunk(b, chunk - 1))
			chunk = chunk - 1;
		else
			return (-1);
	}
	return (chunk);
}

t_list	*choose_next_object(t_list **a, t_list **b, t_list *object)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;
	t_list	*best;

	update_index(a, b);
	first = NULL;
	best = NULL;
	second = NULL;
	third = NULL;
	find_two_exc(b, &first, &object, NULL);
	find_two_exc(b, &second, &first, &object);
	find_two_exc(b, &third, &second, &first);
	best = choose_cheaper(a, b, first, second);
	best = choose_cheaper(a, b, best, third);
	return (best);
}
