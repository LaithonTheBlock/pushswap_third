/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnazzal <lnazzal@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 21:01:01 by lnazzal           #+#    #+#             */
/*   Updated: 2026/10/27 19:25:10 by oalroyei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	bits_max(int size)
{
	int	val;
	int	bits;

	val = size - 1;
	bits = 0;
	while ((val >> bits) > 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, t_count *counter)
{
	int	i;
	int	j;
	int	size;
	int	bits;

	size = stack_size(*stack_a);
	bits = bits_max(size);
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->current >> i) & 1) == 0)
				pb(stack_a, stack_b, counter);
			else
				ra(stack_a, counter);
			j++;
		}
		while (stack_size(*stack_b) > 0)
			pa(stack_a, stack_b, counter);
		i++;
	}
}
