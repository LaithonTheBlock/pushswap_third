/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnazzal <lnazzal@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 16:40:05 by lnazzal           #+#    #+#             */
/*   Updated: 2026/10/26 19:23:09 by oalroyei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	reverse(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	prev = *stack;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **stack_a, int *counter)
{
	reverse(stack_a);
	(*counter)++;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b, int *counter)
{
	reverse(stack_b);
	(*counter)++;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int *counter)
{
	reverse(stack_a);
	reverse(stack_b);
	(*counter)++;
	write(1, "rrr\n", 4);
}
