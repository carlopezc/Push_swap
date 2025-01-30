/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:39:47 by carlopez          #+#    #+#             */
/*   Updated: 2025/01/21 20:13:30 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

void	print_data(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp_b;

	tmp = *stack_a;
	tmp_b = *stack_b;
	ft_printf("\n\nSTACK_A			STACK_B		\n\n");
	while (tmp || tmp_b)
	{
		if (tmp && tmp_b)
		{
			//ft_printf("Apunta a: %p\n", tmp);
			//ft_printf("Su prev es: %p\n", tmp->prev);
			//ft_printf("Su next es: %p\n", tmp->next);
			ft_printf("Su index es: %i		Su index es: %i\n", tmp->index, tmp_b->index);
			ft_printf("Su data es: %i		Su data es: %i\n", tmp->data, tmp_b->data);
			ft_printf("Su chunk es: %i		Su chunk es: %i\n", tmp->chunk, tmp_b->chunk);
			ft_printf("Su delimiter es: %i	Su delimiter es: %i\n\n", tmp->delimiter, tmp_b->delimiter);
			tmp = tmp->next;
			tmp_b = tmp_b->next;
		}
		else if (tmp)
		{
			ft_printf("Su index es: %i\n", tmp->index);
			ft_printf("Su data es: %i\n", tmp->data);
			ft_printf("Su chunk es: %i\n", tmp->chunk);
			ft_printf("Su delimiter es: %i\n\n", tmp->delimiter);
			tmp = tmp->next;
		}
		else if (tmp_b)
		{
			ft_printf("			Su index es: %i\n", tmp_b->index);
			ft_printf("			Su data es: %i\n", tmp_b->data);
			ft_printf("			Su chunk es: %i\n", tmp_b->chunk);
			ft_printf("			Su delimiter es: %i\n\n", tmp_b->chunk);
			tmp_b = tmp_b->next;
		}
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		chunks;

	if (argc < 2)
		return (write(2, "Error\n", 6), -1);
	stack_a = (t_list **)malloc(sizeof(t_list *));
	if (!stack_a)
		return (-1);
	*stack_a = NULL;
	if (!fill_stack_a(stack_a, argv, argc))
		return (free_list(stack_a), write(2, "Error\n", 6), -1);
	fill_index(stack_a);
	if (is_ordered(stack_a))
		return (free_list(stack_a), 0);
	stack_b = (t_list **)malloc(sizeof(t_list *));
	if (!stack_b)
		return (free_list(stack_a), -1);
	*stack_b = NULL;
	chunks = set_chunks(stack_a, stack_b);
	//print_data(stack_a, stack_b);
	if (chunks == -1)
		return (free_list(stack_a), free_list(stack_b), 0);
	sort(stack_a, stack_b, chunks);
	free_list(stack_a);
	free_list(stack_b);
	return (0);
}
