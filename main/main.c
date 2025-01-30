/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:39:47 by carlopez          #+#    #+#             */
/*   Updated: 2025/01/30 16:05:13 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

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
		return (free_list(stack_a, NULL), write(2, "Error\n", 6), -1);
	fill_index(stack_a);
	if (is_ordered(stack_a))
		return (free_list(stack_a, NULL), 0);
	stack_b = (t_list **)malloc(sizeof(t_list *));
	if (!stack_b)
		return (free_list(stack_a, NULL), -1);
	*stack_b = NULL;
	chunks = set_chunks(stack_a, stack_b);
	if (chunks == -1)
		return (free_list(stack_a, stack_b), 0);
	sort(stack_a, stack_b, chunks);
	free_list(stack_a, stack_b);
	return (0);
}
