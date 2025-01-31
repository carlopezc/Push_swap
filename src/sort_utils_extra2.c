/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_extra2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:35:20 by carlopez          #+#    #+#             */
/*   Updated: 2025/01/31 15:05:33 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

void	put_first_back(t_list **a, t_list **b, t_list *object)
{
	int		b_moves;
	int		flag;
	t_list	*a_top;
	t_list	*next;

	update_index(a, b);
	b_moves = calculate_movements(b, object);
	a_top = *a;
	flag = 0;
	if (a_top && object && a_top->next && a_top->data < object->data
		&& (a_top->next)->data > object->data)
		flag = 1;
	else if (a_top && object && a_top->next && a_top->data < object->data
		&& (a_top->next)->data < object->data)
	{
		flag = 2;
		next = choose_next_object(a, b, object);
		if (next && next->index > (list_size(b) / 2))
			flag = 3;
	}
	final_moves_to_a(b_moves, object, a, b);
	make_movements(a, b, flag, object);
	check_lowest(b, a);
	return ;
}

int	calculate_movements(t_list **stack, t_list *object)
{
	int	moves;
	int	size;

	size = list_size(stack);
	moves = 0;
	if (object && object->index <= (size / 2))
		moves = object->index;
	else if (object)
		moves = size - object->index;
	return (moves);
}

int	sum_movements(t_list **a, t_list **b, t_list *object)
{
	int		b_moves;
	int		moves;
	t_list	*a_top;

	b_moves = calculate_movements(b, object);
	a_top = *a;
	moves = 0;
	if (a_top && a_top->next && object && a_top->data < object->data
		&& (a_top->next)->data < object->data)
		moves = 2;
	else if (a_top && a_top->next && object && a_top->data < object->data
		&& (a_top->next)->data < object->data)
		moves = 4;
	moves = moves + b_moves;
	return (moves);
}

t_list	*choose_cheaper(t_list **a, t_list **b, t_list *first, t_list *second)
{
	int	first_moves;
	int	second_moves;

	first_moves = -1;
	second_moves = -1;
	update_index(a, b);
	if (first)
		first_moves = sum_movements(a, b, first);
	if (second)
		second_moves = sum_movements(a, b, second);
	if (first && ((first_moves <= second_moves
				&& first_moves != -1) || !second))
		return (first);
	else if (second && ((second_moves <= first_moves
				&& second_moves != -1) || !first))
		return (second);
	return (NULL);
}

void	put_null(t_list *best, t_list **first, t_list **second, t_list **third)
{
	if (best && first && best == *first)
		*first = NULL;
	else if (best && second && best == *second)
		*second = NULL;
	else if (best && third && best == *third)
		*third = NULL;
	return ;
}
