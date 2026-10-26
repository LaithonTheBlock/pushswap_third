/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnazzal <lnazzal@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 18:00:04 by lnazzal           #+#    #+#             */
/*   Updated: 2026/10/26 17:58:34 by oalroyei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	temp = *stack;
	last = stack_last(*stack);
	*stack = (*stack)->next;
	last->next = temp;
	temp->next = NULL;
}

void	ra(t_stack **stack_a, int *counter)
{
	rotate(stack_a);
	(*counter)++;
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b, int *counter)
{
	rotate(stack_b);
	(*counter)++;
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b, int *counter)
{
	rotate(stack_a);
	rotate(stack_b);
	(*counter)++;
	write(1, "rr\n", 3);
}
