/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnazzal <lnazzal@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:36:34 by lnazzal           #+#    #+#             */
/*   Updated: 2026/10/29 19:25:12 by lnazzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_strategy	choose_strategy(t_stack **a, t_flags *f, double disorder)
{
	if (f->strategy != ADAPTIVE)
		return (f->strategy);
	if (stack_size(*a) <= 5)
		return (SIMPLE);
	if (disorder < 0.2)
		return (SIMPLE);
	if (disorder < 0.5)
		return (MEDIUM);
	return (COMPLEX);
}

void	sort_stack(t_stack **a, t_stack **b, t_count *c, t_flags *f)
{
	if (stack_size(*a) == 3)
		return (tiny_sort(a, c));
	if (f->chosen == SIMPLE)
		selection_sort(a, b, c);
	else if (f->chosen == MEDIUM)
		chunk_sort(a, b, c);
	else
		radix_sort(a, b, c);
}
