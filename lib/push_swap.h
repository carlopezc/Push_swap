/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:50:47 by carlopez          #+#    #+#             */
/*   Updated: 2025/02/04 14:29:15 by carlopez         ###   ########.fr       */
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
char	*get_next_line(int fd);
int		check_and_make(t_list **a, t_list **b);
int		ft_strlen(char *str);
int		find_chunk(t_list **stack_a, int i);
int		check_str(char *str);
int		is_repeated(t_list **stack_a, int num);
int		is_int(long num);
int		list_size(t_list **stack);
int		is_ordered(t_list **stack_a);
int		is_smallest(t_list **stack, int data);
int		check_swap(t_list **stack);
int		check_lowest(t_list **stackb, t_list **stack_a);
int		calculate_movements(t_list **stack, t_list *object);
int		bigger_or_lower(t_list **stack_b, int delimiter);
int		find_delimiter(int chunk, t_list **stack);
int		fill_stack_a(t_list **stack_a, char **argv, int argc);
int		set_chunks(t_list **stack_a, t_list **stack_b);
t_list	*look_for_min(t_list **stack_a);
t_list	*find_lowest(t_list **stack);
t_list	*find_biggest(t_list **stack);
t_list	*find_last(t_list **stack_a);
t_list	*choose_cheaper(t_list **a, t_list **b, t_list *first, t_list *second);
t_list	*choose_next_object(t_list **a, t_list **b, t_list *object);
void	free_list(t_list **stack);
void	put_null(t_list *best, t_list **first, t_list **second, t_list **third);
void	order_a(t_list	**a, t_list **b);
void	update_index(t_list **stack_a, t_list **stack_b);
void	advance_tmp(t_list **stack, t_list **tmp, t_list **exc, t_list **exc2);
void	special_sort(t_list **stack_a, t_list **stack_b, int size);
void	sort_three(t_list **stack_a);
void	sort_four(t_list **stack_a, t_list **stack_b);
void	sort_five(t_list **stack_a, t_list **stack_b);
void	find_two_exc(t_list **stack, t_list **obj, t_list **exc, t_list **exc2);
void	find_top_three(t_list **stack,
			t_list **first, t_list **second, t_list **third);
void	final_moves_to_a(int moves, t_list *object, t_list **a, t_list **b);
void	make_movements(t_list **a, t_list **b, int flag, t_list *object);
void	pass_ordered(t_list **stack_b, t_list **stack_a);
void	fill_index(t_list **stack);
void	put_first_back(t_list **a, t_list **b, t_list *object);
void	sort(t_list **stack_a, t_list **stack_b);
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
