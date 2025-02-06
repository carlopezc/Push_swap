/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:50:58 by carlopez          #+#    #+#             */
/*   Updated: 2025/02/06 12:42:39 by carlopez         ###   ########.fr       */
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
		return (free_list(stack_a), ft_printf("Error\n"), -1);
	else if (argc == 2)
		return (free_list(stack_a), 0);
	stack_b = (t_list **)malloc(sizeof(t_list *));
	if (!stack_b)
		return (free_list(stack_a), -1);
	*stack_b = NULL;
	if (check_and_make(stack_a, stack_b) == 0)
		return (free_list(stack_a), free_list(stack_b), -1);
	if (is_ordered(stack_a) && !(*stack_b))
		return (free_list(stack_a), free_list(stack_b), ft_printf("OK\n"), 0);
	return (free_list(stack_a), free_list(stack_b), ft_printf("KO\n"), -1);
}
