/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:39:47 by carlopez          #+#    #+#             */
/*   Updated: 2025/03/06 12:22:48 by carlopez         ###   ########.fr       */
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
		return (free_list(stack_a), write(2, "en fill stack Error\n", 30), -1);
	else if (argc == 2)
		return (free_list(stack_a), 0);
	fill_index(stack_a);
	if (is_ordered(stack_a))
		return (free_list(stack_a), 0);
	stack_b = (t_list **)malloc(sizeof(t_list *));
	if (!stack_b)
		return (free_list(stack_a), -1);
	*stack_b = NULL;
	sort(stack_a, stack_b);
	return (free_list(stack_a), free_list(stack_b), 0);
}
