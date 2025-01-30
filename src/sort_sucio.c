/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sucio.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:58:31 by carlopez          #+#    #+#             */
/*   Updated: 2025/01/27 13:47:57 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

//la uso
/*
int	*calculate_movements(t_list **stack, t_list *object)
{
	int	*moves;
	int	i;
	int	size;

	//0 es ra
	//1 es rra
	i = 0;
	size = list_size(stack);
	moves = (int *)malloc(2 * sizeof(int));
	if (!moves)
		return (NULL);
	while (i < 2)
		moves[i++] = 0;
	if (!object)
		return (moves);
	if (object->index <= (size / 2))
		moves[0] = object->index;
	else
	{
		moves[0] = size - object->index;
		moves[1] = 1;
	}
	return (moves);
}

int     sum_movements_back(t_list **stack_a, t_list **stack_b, t_list *object)
{
        int     *b_moves;
        int     moves;
	t_list	*a;

        b_moves = calculate_movements(stack_b, object);
	a = *stack_a;
	moves = 0;
	//pa y sa
	if (a && a->next && object && a->data < object->data && (a->next)->data > object->data)
		moves = 2;
	//ra, pa, sa, rra
	else if (a && a->next && object && a->data < object->data && (a->next)->data < object->data)
		moves = 4;
	moves = moves + b_moves[0];
        return (free(b_moves), moves);
}
xx
void    final_moves_to_a(int *b_moves, int moves, t_list **stack_a, t_list **stack_b)
{
        b_moves[0] = b_moves[0] - moves;
        update_index(stack_a, stack_b);
        if (b_moves[0] > 0)
        {
                while (b_moves[0]-- > 0)
                {
                        if (b_moves[1] == 0)
			{
                                rb(stack_b);
				if (check_lowest(stack_b, stack_a))
					b_moves[0]--;
			}
                        else
                                rrb(stack_b);
                }
        }
        return ;
}
*/
//la uso

void	choose_cheaper_back(t_list **stack_a, t_list **stack_b, t_list *first, t_list *second, t_list *third)
{
	int	first_moves;
	int	second_moves;
	int	third_moves;

	first_moves = -1;
	second_moves = -1;
	third_moves = -1;
	update_index(stack_a, stack_b);
	if (first)
		first_moves = sum_movements_back(stack_a, stack_b, first);
	if (second)
		second_moves = sum_movements_back(stack_a, stack_b, second);
	if (third)
		third_moves = sum_movements_back(stack_a, stack_b, third);
	//comprobaciones
	if (first && ((first_moves <= second_moves && first_moves != -1) || !second))
	{
		if (first && ((first_moves <= third_moves && first_moves != -1) || !third))
		{
			put_first_back(stack_a, stack_b, first);
			choose_cheaper_back(stack_a, stack_b, NULL, second, third);
		}
		else if (third)
		{
			put_first_back(stack_a, stack_b, third);
			choose_cheaper_back(stack_a, stack_b, first, second, NULL);
		}
	}
	else if (second && ((second_moves <= third_moves && second_moves != -1) || !third))
	{
			put_first_back(stack_a, stack_b, second);
			choose_cheaper_back(stack_a, stack_b, first, NULL, third);
	}
	else if (third)
	{
		put_first_back(stack_a, stack_b, third);
		choose_cheaper_back(stack_a, stack_b, first, second, NULL);
	}
	return ;
}
*/
void	select_objects(t_list **stack_a, t_list **stack_b, t_list *object, t_list **uno, t_list **dos, t_list **tres)
{
	t_list	*tmp;
	t_list	*higher;
	int	chunk;

	(void)stack_a;
	chunk = object->chunk;
	//compruebo si quedan mas del mismo chunk y que si no pase al siguiente
	if (!search_chunk(stack_b, chunk))
	{
		if (search_chunk(stack_b, chunk - 1))
			chunk = chunk - 1;
		else
			return ;
	}
	tmp = *stack_b;
	if (tmp == object)
		tmp = tmp->next;
	higher = *stack_b;
 	while (tmp && higher)
        {
                if (tmp->data > higher->data && tmp->chunk == chunk && tmp != object)
                        higher = tmp;
                tmp = tmp->next;
        }
	if (uno)
        	*uno = higher;
        tmp = *stack_b;
        higher = *stack_b;
	if (tmp == object)
		tmp = tmp->next;
        while (tmp && uno)
        {
		if (higher == (*uno))
			higher = tmp;
                if ((tmp->data > higher->data) && (tmp->data != (*uno)->data) && (tmp->chunk == (*uno)->chunk) && tmp != object)
                        higher = tmp;
                tmp = tmp->next;
        }
	if (dos)
        	*dos = higher;
        //comparo entre dos para pasar el mas grande y voy pasando por chunks
        if (dos && *dos && uno && *uno)
        {
                if ((*dos)->chunk != (*uno)->chunk)
                        *dos = NULL;
        }
        tmp = *stack_b;
        higher = *stack_b;
	if (tmp == object)
		tmp = tmp->next;
        while (tmp && uno && dos)
        {
                if (higher == (*uno) || higher == (*dos))
                        higher = tmp;
                if ((tmp->data > higher->data) && (tmp->data != (*uno)->data) && (tmp->chunk == (*uno)->chunk) && tmp != object)
                {
                        if (dos && tmp->data != (*dos)->data)
                                higher = tmp;
                }
                tmp = tmp->next;
        }
	if (tres)
        	*tres = higher;
        //comparo entre dos para pasar el mas grande y voy pasando por chunks
        if (tres && *tres && uno && *uno)
        {
                if ((*tres)->chunk != (*uno)->chunk)
                        *tres = NULL;
        }
	return ;
}

t_list	*choose_next_objects(t_list **stack_a, t_list **stack_b, t_list *object)
{
	int     first_moves;
        int     second_moves;
        int     third_moves;
	t_list	*uno;
	t_list	*dos;
	t_list	*tres;

        first_moves = -1;
        second_moves = -1;
        third_moves = -1;
        update_index(stack_a, stack_b);
	uno = NULL;
	dos = NULL;
	tres = NULL;
	select_objects(stack_a, stack_b, object, &uno, &dos, &tres);
        if (uno)
                first_moves = sum_movements_back(stack_a, stack_b, uno);
        if (dos)
                second_moves = sum_movements_back(stack_a, stack_b, dos);
        if (tres)
                third_moves = sum_movements_back(stack_a, stack_b, tres);
        //comprobaciones
        if (uno && ((first_moves <= second_moves && first_moves != -1) || !dos ))
        {
                if (uno && ((first_moves <= third_moves && first_moves != -1) || !tres))
			return (uno);
                else if (tres)
			return (tres);
        }
        else if (dos && ((second_moves <= third_moves && second_moves != -1) || !tres))
		return (dos);
        else if (tres)
		return (tres);
        return (NULL);
}

int	check_swap(t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_b;
	if (tmp && tmp->next)
	{
		if (tmp->data < (tmp->next)->data && tmp->chunk == (tmp->next)->chunk)
			return (1);
		return (0);
	}
	return (0);
}

//la uso
/*
void	put_first_back(t_list **stack_a, t_list **stack_b, t_list *object)
{
	int	*b_moves;
	int	flag;
	t_list	*a;
	t_list	*next;

	b_moves = calculate_movements(stack_b, object);
	a = *stack_a;
	next = NULL;
	flag = 0;
	if (a && object && a->next && a->data < object->data && (a->next)->data > object->data)
		flag = 1;
	else if (a && object && a->next && a->data < object->data && (a->next)->data < object->data)
	{
		flag = 2;
		next = choose_next_objects(stack_a, stack_b, object);
		if (next && next->index > (list_size(stack_b) / 2))
			flag = 4;
	}
        final_moves_to_a(b_moves, 0, stack_a, stack_b);
	if (flag == 4)
		ra(stack_a);
	if (flag == 2)
		ra(stack_a);
        pa(stack_a, stack_b);
	if (flag == 1 || flag == 2 || flag == 4)
	{
		if (check_swap(stack_b))
			ss(stack_a, stack_b);
		else
			sa(stack_a);
	}
	if (flag == 4)
	{
		if (next && next->index > (list_size(stack_b) / 2))
			rrr(stack_a, stack_b);
		else
			flag = 3;
	}
	if (flag == 2 | flag == 3)
		rra(stack_a);
	check_lowest(stack_b, stack_a);
	return (free(b_moves));
}
*/
//la uso
void	move_back_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = NULL;
	second = NULL;
	third = NULL;
	while (*stack_b)
	{
		update_index(stack_a, stack_b);
		if (!check_lowest(stack_b, stack_a))
		{
			find_higher(&first, &second, &third, stack_b);
			choose_cheaper_back(stack_a, stack_b, first, second, third);
		}
	}
	return ;
}

//la uso
void	order_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*lower;
	int	moves;
	int	size;

	tmp = *stack_a;
	lower = *stack_a;
	size = list_size(stack_a);
	while (tmp)
	{
		if (tmp->data < lower->data)
			lower = tmp;
		tmp = tmp->next;
	}
	update_index(stack_a, stack_b);
	if (lower->index > (size / 2))
	{
		moves = size - lower->index;
		while (moves-- > 0)
			rra(stack_a);
	}
	else
	{
		moves = lower->index;
		while (moves-- > 0)
			ra(stack_a);
	}
	return ;
}

//la uso
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
			choose_objects_gm(stack_a, stack_b, i, delimiter);
		}
		i++;
	}
	update_index(stack_a, stack_b);
	sort_five(stack_a, stack_b);
	move_back_to_a(stack_a, stack_b);
	order_a(stack_a, stack_b);
	return ;
}
