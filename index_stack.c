/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnazzal <lnazzal@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 21:16:25 by lnazzal           #+#    #+#             */
/*   Updated: 2026/10/22 21:26:39 by lnazzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	index_stack(t_stack *a)
{
	int		index;
	t_stack	*stack;
	t_stack	*temp;

	stack = a;
	while (stack)
	{
		index = 0;
		temp = a;
		while (temp)
		{
			if (temp->value < stack->value)
				index++;
			temp = temp->next;
		}
		stack->current = index;
		stack = stack->next;
	}
}
