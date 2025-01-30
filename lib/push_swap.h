/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:50:47 by carlopez          #+#    #+#             */
/*   Updated: 2025/01/30 16:35:19 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../printf/ft_printf.h"

typedef struct list
{
	struct list	*prev;
	struct list	*next;
	int			data;
	int			chunk;
	int			index;
	int			delimiter;
}	t_list;
void	rotate(t_list **stack);
void	pass(t_list **stack_a, int moves, int flag);
void	move_back(t_list **stack_a, t_list **stack_b);
void	sort_three(t_list **stack_a);
void	make_movement(t_list **stack_a, t_list **stack_b, int moves, int flag);
int		check_lowest(t_list **stackb, t_list **stack_a);
void	nosecomollamar(int data, t_list **stack_b, t_list **stack_a);
void	sort_five(t_list **stack_a, t_list **stack_b);
void	sort_four(t_list **stack_a, t_list **stack_b);
t_list	*lowest(t_list **stack);
int		is_ordered(t_list **stack_a);
int		is_smallest(t_list **stack, int data);
void	cheaper_movement(t_list **stack_a, t_list *first, t_list *second);
void	choose_objects(t_list **stack_a, t_list **stack_b, int i, int delimiter);
void	sort(t_list **stack_a, t_list **stack_b, int chunks);
void	update_index(t_list **stack_a, t_list **stack_b);
void	check_order(t_list **stack_a, t_list **stack_b);
void	special_sort(t_list **stack_a, t_list **stack_b, int size);
int		search_chunk(t_list **stack_a, int i);
int		ft_strlen(char *str);
void	reverse_rotate(t_list **stack);
void	fill_index(t_list **stack);
void	swap(t_list **stack);
void	push(t_list **dest_stack, t_list **src_stack);
void	final_moves_to_b(int *a_moves, t_list **stack_a, t_list **stack_b);
void	put_first_back(t_list **stack_a, t_list **stack_b, t_list *object);
int		list_size(t_list **stack);
long	ft_atol(char *str);
t_list	*lstnew(int num);
t_list	*look_for_tmp(t_list **stack_a, int chunk, int start);
t_list	*find_low_closer(t_list *object, t_list **stack_b);
int		is_repeated(t_list **stack_a, int num);
int		is_int(long num);
int		check_str(char *str);
int		check_length(char *str);
int		fill_stack_a(t_list **stack_a, char **argv, int argc);
void	connect_list(t_list **stack_a, t_list *object);
int		assign_chunks(t_list **stack_a, int num, int size);
int		set_chunks(t_list **stack_a, t_list **stack_b);
//look fo, puedo cambiarlo por fin
t_list	*look_for_min(t_list **stack_a);

//free
void	free_list(t_list **stack_a, t_list **stack_b);
//calculate moves
int		calculate_movements(t_list **stack, t_list *object);
int		sum_movements(t_list **a, t_list **b, t_list *object);
//final moves
void	final_moves_to_a(int moves, t_list *object, t_list **a, t_list **b);
//funciones find
void	find_top_three_except(t_list **first, t_list **second, t_list **third, t_list *object);
void	find_biggest_except2(t_list **stack, t_list **object, t_list **except, t_list **except_2);
void	find_biggest_except(t_list **stack, t_list **object, t_list **except);
void	find_top_three(t_list **stack, t_list **first, t_list **second, t_list **third);
int		find_delimiter(int chunk, t_list **stack);
t_list	*find_lowest(t_list **stack);
t_list	*find_biggest(t_list **stack);
t_list	*find_last(t_list **stack_a);
void	order_a(t_list	**a, t_list **b);
void	put_first_back(t_list **a, t_list **b, t_list *object);
//funciones check
int		check_swap(t_list **stack);

//funciones choose
t_list	*choose_cheaper(t_list **a, t_list **b, t_list *first, t_list *second);

int		bigger_or_lower(t_list **stack_b, int delimiter);

//movimientos
void	ss(t_list **stack_a, t_list **stack_b);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_b, t_list **stack_a);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

#endif
