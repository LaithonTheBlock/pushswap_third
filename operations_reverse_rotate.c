/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnazzal <lnazzal@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 16:40:05 by lnazzal           #+#    #+#             */
/*   Updated: 2026/10/22 21:51:06 by oalroyei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rra(t_stack *stack_a)
{
	int		temp;
	t_stack	*current;
	t_stack	*last;

	if (!stack_a || !stack_a->next)
		return ;
	last = stack_last(stack_a);
	temp = last->value;
	current = stack_a;
	while (last != stack_a)
	{
		current = stack_a;
		while (current->next != last)
			current = current->next;
		last->value = current->value;
		last = current;
	}
	stack_a->value = temp;
}

void	rrb(t_stack *stack_b)
{
	int		temp;
	t_stack	*current;
	t_stack	*last;

	if (!stack_b || !stack_b->next)
		return ;
	last = stack_last(stack_b);
	temp = last->value;
	current = stack_b;
	while (last != stack_b)
	{
		current = stack_b;
		while (current->next != last)
			current = current->next;
		last->value = current->value;
		last = current;
	}
	stack_b->value = temp;
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
