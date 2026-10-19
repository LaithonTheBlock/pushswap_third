/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalroyei <oalroyei@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 18:50:17 by oalroyei          #+#    #+#             */
/*   Updated: 2026/10/19 21:10:30 by oalroyei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	disorder(t_stack *stack)
{
	t_stack	*outer;
	t_stack	*inner;
	int		inversions;
	int		n;

	n = stack_size(stack);
	inversions = 0;
	if (stack == NULL || stack->next == NULL)
		return (0);
	outer = stack;
	while (outer->next != NULL)
	{
		inner = outer->next;
		while (inner != NULL)
		{
			if (outer->value > inner->value)
				inversions++;
			inner = inner->next;
		}
		outer = outer->next;
	}
	return ((double)inversions / (n * (n - 1) / 2));
}
