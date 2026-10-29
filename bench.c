/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnazzal <lnazzal@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:44:18 by lnazzal           #+#    #+#             */
/*   Updated: 2026/10/29 17:46:22 by lnazzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	print_op(char *name, int count, char sep)
{
	ft_putstr_fd(name, 2);
	write(2, ": ", 2);
	ft_putnbr_fd(count, 2);
	write(2, &sep, 1);
}

static void	print_rots(t_count *c)
{
	ft_putstr_fd("[bench] ", 2);
	print_op("ra", c->ra, ' ');
	print_op("rb", c->rb, ' ');
	print_op("rr", c->rr, ' ');
	print_op("rra", c->rra, ' ');
	print_op("rrb", c->rrb, ' ');
	print_op("rrr", c->rrr, '\n');
}

static void	print_ops(t_count *c)
{
	ft_putstr_fd("[bench] ", 2);
	print_op("sa", c->sa, ' ');
	print_op("sb", c->sb, ' ');
	print_op("ss", c->ss, ' ');
	print_op("pa", c->pa, ' ');
	print_op("pb", c->pb, '\n');
}

void	print_bench(t_flags *f, t_count *c, double disorder)
{
	c->total = c->sa + c->sb + c->ss + c->pa + c->pb + c->ra
		+ c->rb + c->rr + c->rra + c->rrb + c->rrr;
	print_disorder(disorder);
	print_strategy(f);
	print_total(c->total);
	print_ops(c);
	print_rots(c);
}
