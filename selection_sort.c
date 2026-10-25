/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalroyei <oalroyei@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 21:58:51 by oalroyei          #+#    #+#             */
/*   Updated: 2026/10/24 22:17:13 by oalroyei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort(t_stack **a, t_stack **b)
{
	t_stack	*lowest;

	while (stack_size(*a) > 3)
	{
		lowest = find_lowest(*a);
		if (find_position(*a) <= stack_size(*a) / 2)
			while (*a != lowest)
				ra(a);
		else
			while (*a != lowest)
				rra(a);
		pb(a, b);
	}
	tiny_sort(a);
	while (*b)
		pa(a, b);
}
