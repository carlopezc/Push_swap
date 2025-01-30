/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_chunks_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:33:17 by carlopez          #+#    #+#             */
/*   Updated: 2025/01/30 16:34:11 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

t_list	*look_for_min(t_list **stack_a)
{
	int		min;
	t_list	*min_tmp;
	t_list	*tmp;

	tmp = *stack_a;
	min = tmp->data;
	min_tmp = tmp;
	while (tmp)
	{
		if (tmp->chunk != 0 && tmp->data == min && tmp->next)
		{
			tmp = tmp->next;
			min = tmp->data;
			min_tmp = tmp;
		}
		else if (tmp->chunk == 0 && tmp->data < min)
		{
			min = tmp->data;
			min_tmp = tmp;
			tmp = tmp->next;
		}
		else
			tmp = tmp->next;
	}
	return (min_tmp);
}
