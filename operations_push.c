/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnazzal <lnazzal@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 16:37:04 by lnazzal           #+#    #+#             */
/*   Updated: 2026/10/26 17:57:36 by oalroyei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	push(t_stack **first, t_stack **second)
{
	t_stack	*temp;

	if (!*second)
		return ;
	temp = *second;
	*second = (*second)->next;
	temp->next = *first;
	*first = temp;
}

void	pa(t_stack **stack_a, t_stack **stack_b, int *counter)
{
	push(stack_a, stack_b);
	(*counter)++;
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b, int *counter)
{
	push(stack_b, stack_a);
	(*counter)++;
	write(1, "pb\n", 3);
}
