/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:17:38 by carlopez          #+#    #+#             */
/*   Updated: 2025/01/30 12:41:48 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

void	order_a(t_list	**a, t_list **b)
{
	t_list	*lowest;
	int	moves;
	int	size;

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
	if (!search_chunk(b, chunk))
	{
		if (search_chunk(b, chunk - 1))
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
//	int	chunk;
//
	update_index(a, b);
	/*
	chunk = choose_chunk(b, object);
	if (chunk == -1)
		return (NULL);
		*/
	first = NULL;
	best = NULL;
	//first = NULL;
	second = NULL;
	third = NULL;
//	print_data(a, b);
	find_biggest_except2(b, &first, &object, NULL);
	find_biggest_except2(b, &second, &first, &object);
	find_biggest_except2(b, &third, &second, &first);
	/*
	if (first)
		ft_printf("next first es %i\n", first->data);
	if (second)
		ft_printf("next second es %i\n", second->data);
	if (third)
		ft_printf("next third es %i\n", third->data);
		*/
	best = choose_cheaper(a, b, first, second);
	best = choose_cheaper(a, b, best, third);
	/*
	if (best)
		ft_printf("Next best es %i\n", best->data);
		*/
	return (best);
}

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
		/*
		if (next)
			ft_printf("Next sigue siendo %i\n", next->data);
		//falta el choose_next_object
		ft_printf("comprueba index\n");
		*/
		//print_data(a, b);
		if (next && next->index > (list_size(b) / 2))
			rrr(a, b);
		else
			flag = 2;
	}
	if (flag == 2)
		rra(a);
	return ;
}

void	put_first_back(t_list **a, t_list **b, t_list *object)
{
	int		b_moves;
	int		flag;
	t_list	*a_top;
	t_list	*next;

	//print_data(a, b);
	update_index(a, b);
	b_moves = calculate_movements(b, object);
	//ft_printf("moves son %i\n", b_moves);
	/*
	if (object)
		ft_printf("Object es %i\n", object->data);
		*/
	a_top = *a;
	flag = 0;
	if (a_top && object && a_top->next && a_top->data < object->data
		&& (a_top->next)->data > object->data)
	{
		//ft_printf("flag 1\n");
		flag = 1;
	}
	else if (a_top && object && a_top->next && a_top->data < object->data
		&& (a_top->next)->data < object->data)
	{
		flag = 2;
		next = choose_next_object(a, b, object);
		/*
		if (next)
			ft_printf("Next es %i\n", next->data);
			*/
		if (next && next->index > (list_size(b) / 2))
		{
			//ft_printf("usa next\n");
			flag = 3;
		}
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

void	move_back_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;
	t_list	*best;
	int	i;

	first = NULL;
	second = NULL;
	third = NULL;
	i = 0;
	while (stack_b && *stack_b)
	{
		update_index(stack_a, stack_b);
		if (!check_lowest(stack_b, stack_a))
		{
			find_top_three(stack_b, &first, &second, &third);
			best = first;
			while (best)
			{
				best = NULL;
				/*
				if (first)
					ft_printf("First %i\n", first->data);
				if (second)
					ft_printf("Second %i\n", second->data);
				if (third)
					ft_printf("Third %i\n", third->data);
					*/
				best = choose_cheaper(stack_a, stack_b, first, second);
				best = choose_cheaper(stack_a, stack_b, best, third);
				if (!best)
					break ;
				/*
				if (best)
					ft_printf("best es %i\n", best->data);
					*/
				put_first_back(stack_a, stack_b, best);
				put_null(best, &first, &second, &third);
				//print_data(stack_a, stack_b);
			}
		}
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
	while (*stack_a && search_chunk(stack_a, i))
	{
		if ((*stack_a)->chunk == i)
			put_first(stack_a, stack_b, i, delimiter);
		else
			ra(stack_a);
	}
	return ;
}

void	sort(t_list **stack_a, t_list **stack_b, int chunks)
{
	int	i;
	int	delimiter;

	i = 1;
	while (i <= chunks)
	{
		delimiter = find_delimiter(i, stack_a);
		while (search_chunk(stack_a, i))
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
