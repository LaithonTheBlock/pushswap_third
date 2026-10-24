/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalroyei <oalroyei@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 18:04:52 by oalroyei          #+#    #+#             */
/*   Updated: 2026/10/22 21:54:12 by oalroyei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_highest(t_stack *stack_a)
{
	t_stack	*highest;

	highest = stack_a;
	while (stack_a)
	{
		if (stack_a->value > highest->value)
			highest = stack_a;
		stack_a = stack_a->next;
	}
	return (highest);
}

void	tiny_sort(t_stack **a)
{
	t_stack	*highest;

	highest = find_highest(*a);
	if (*a == highest)
		ra(*a);
	else if ((*a)->next == highest)
		rra(*a);
	if ((*a)->value > (*a)->next->value)
		sa(*a);
}
