/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalroyei <oalroyei@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 18:04:52 by oalroyei          #+#    #+#             */
/*   Updated: 2026/10/24 22:14:47 by oalroyei         ###   ########.fr       */
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
	t_stack *lowest;

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

void	tiny_sort(t_stack **a)
{
	t_stack	*highest;

	highest = find_highest(*a);
	if (*a == highest)
	{	//change
		ra(a);
		write(1, "ra\n", 3);	//change
	}	//change
	else if ((*a)->next == highest)
	{	//change
		rra(a);
		write(1, "rra\n", 4);	//change
	}	//change
	if ((*a)->value > (*a)->next->value)
	{	//change
		sa(*a);
		write(1, "sa\n", 3);	//change
	}	//change
}

void	tiny_sort_improved(t_stack **a, t_stack **b)
{
	t_stack	*lowest;

	while (stack_size(*a) > 3)
	{
		lowest = find_lowest(*a);
		if (find_position(*a) <= stack_size(*a) / 2)
			while (*a != lowest)
			{	//change
				ra(a);
				write(1, "ra\n", 3);	//change
			}	//change
		else
			while (*a != lowest)
			{	//change
				rra(a);
				write(1, "rra\n", 4);	//change
			}	//change
		pb(a, b);
		write(1, "pb\n", 3);
	}
	tiny_sort(a);
	while (*b)
	{	//change
		pa(a, b);
		write(1, "pa\n", 3);	//change
	}	//change
}
