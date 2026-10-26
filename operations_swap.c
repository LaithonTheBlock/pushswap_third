/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnazzal <lnazzal@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 15:51:42 by lnazzal           #+#    #+#             */
/*   Updated: 2026/10/26 18:05:22 by oalroyei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	temp;

	if (!stack || !stack->next)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
}

void	sa(t_stack *stack_a, int *counter)
{
	swap(stack_a);
	(*counter)++;
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b, int *counter)
{
	swap(stack_b);
	(*counter)++;
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b, int *counter)
{
	swap(stack_a);
	swap(stack_b);
	(*counter)++;
	write(1, "ss\n", 3);
}
