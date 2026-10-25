/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate_correct.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnazzal <lnazzal@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 18:00:04 by lnazzal           #+#    #+#             */
/*   Updated: 2026/10/24 20:37:13 by oalroyei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*last;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	last = 	stack_last(*stack_a);
	*stack_a = (*stack_a)->next;
	last->next = temp;
	temp->next = NULL;
}

void	rb(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*last;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	temp = *stack_b;
	last = stack_last(*stack_b);
	*stack_b = (*stack_b)->next;
	last->next = temp;
	temp->next = NULL;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
