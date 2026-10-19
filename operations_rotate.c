/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnazzal <lnazzal@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 18:00:04 by lnazzal           #+#    #+#             */
/*   Updated: 2026/10/19 19:21:11 by lnazzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ra(t_stack *stack_a)
{
	int		temp;
	t_stack	*last;

	if (!stack_a || !stack_a->next)
		return ;
	temp = stack_a->value;
	last = stack_last(stack_a);
	while (stack_a->next != last)
	{
		stack_a->value = stack_a->next->value;
		stack_a = stack_a->next;
	}
	last->value = temp;
}

void	rb(t_stack *stack_b)
{
	int		temp;
	t_stack	*last;

	if (!stack_b || !stack_b->next)
		return ;
	temp = stack_b->value;
	last = stack_last(stack_b);
	while (stack_b->next != last)
	{
		stack_b->value = stack_b->next->value;
		stack_b = stack_b->next;
	}
	last->value = temp;
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
