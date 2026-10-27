/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnazzal <lnazzal@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 18:31:04 by lnazzal           #+#    #+#             */
/*   Updated: 2026/10/27 20:10:07 by oalroyei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	get_chunk_size(int size)
{
	if (size <= 100)
		return (size / 5 + 1);
	return (size / 11 + 1);
}

static void	push_chunks(t_stack **a, t_stack **b, int total, t_count *c)
{
	int	pushedd;

	pushedd = 0;
	while (*a)
	{
		if ((*a)->current <= pushedd)
		{
			pb(a, b, c);
			rb(b, c);
			pushedd++;
		}
		else if ((*a)->current <= pushedd + total)
		{
			pb(a, b, c);
			pushedd++;
		}
		else
			ra(a, c);
	}
}

static int	get_pos(t_stack *s, int target)
{
	int	pos;

	pos = 0;
	while (s && s->current != target)
	{
		s = s->next;
		pos++;
	}
	return (pos);
}

static void	push_back(t_stack **a, t_stack **b, t_count *counter)
{
	int	size;
	int	pos;

	while (*b)
	{
		size = stack_size(*b);
		pos = get_pos(*b, size - 1);
		if (pos <= size / 2)
			while (pos-- > 0)
				rb(b, counter);
		else
		{
			pos = size - pos;
			while (pos-- > 0)
				rrb(b, counter);
		}
		pa(a, b, counter);
	}
}

void	chunk_sort(t_stack **a, t_stack **b, t_count *counter)
{
	push_chunks(a, b, get_chunk_size(stack_size(*a)), counter);
	push_back(a, b, counter);
}
