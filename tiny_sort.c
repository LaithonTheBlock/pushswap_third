/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalroyei <oalroyei@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 18:04:52 by oalroyei          #+#    #+#             */
/*   Updated: 2026/10/26 19:23:25 by oalroyei         ###   ########.fr       */
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

t_stack	*find_lowest(t_stack *stack_a)
{
	t_stack	*lowest;

	lowest = stack_a;
	while (stack_a)
	{
		if (stack_a->value < lowest->value)
			lowest = stack_a;
		stack_a = stack_a->next;
	}
	return (lowest);
}

int	find_position(t_stack *stack_a)
{
	t_stack	*lowest;
	int		pos;

	pos = 0;
	lowest = find_lowest(stack_a);
	while (stack_a != lowest)
	{
		stack_a = stack_a->next;
		pos++;
	}
	return (pos);
}

void	tiny_sort(t_stack **a, int *counter)
{
	t_stack	*highest;

	highest = find_highest(*a);
	if (*a == highest)
		ra(a, counter);
	else if ((*a)->next == highest)
		rra(a, counter);
	if ((*a)->value > (*a)->next->value)
		sa(*a, counter);
}
