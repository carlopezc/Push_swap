/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:50:58 by carlopez          #+#    #+#             */
/*   Updated: 2025/02/03 17:22:56 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"


int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc == 1)
		return (0);
	stack_a = (t_list **)malloc(sizeof(t_list *));
	if (!stack_a)
		return (-1);
	*stack_a = NULL;
	if (!fill_stack_a(stack_a, argv, argc))
		return (free_list(stack_a, NULL), write(2, "Error\n", 6), -1);
	else if (argc == 2)
		return (free_list(stack_a, NULL), 0);
	if (is_ordered(stack_a))
		return (free_list(stack_a, NULL), write(1, "OK\n", 3), 0);
	stack_b = (t_list **)malloc(sizeof(t_list *));
	if (!stack_b)
		return (free_list(stack_a, NULL), -1);
	*stack_b = NULL;
	if (!check_and_make(stack_a, stack_b))
		return (free_list(stack_a, stack_b), write(2, "KO\n", 4), -1);
	if (is_ordered(stack_a) && !(*stack_b))
		return (free_list(stack_a, stack_b), write(1, "OK\n", 4), 0);
	return (free_list(stack_a, stack_b), write(2, "KO\n", 4), -1);
}
