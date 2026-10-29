/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnazzal <lnazzal@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 17:42:14 by lnazzal           #+#    #+#             */
/*   Updated: 2026/10/29 17:42:21 by lnazzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	print_disorder(double disorder)
{
	int	i;
	int	frac;

	i = disorder * 10000 + 0.5;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(i / 100, 2);
	write(2, ".", 1);
	frac = i % 100;
	if (frac < 10)
		write(2, "0", 1);
	ft_putnbr_fd(frac, 2);
	write(2, "%\n", 2);
}

void	print_total(int total)
{
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(total, 2);
	write(2, "\n", 1);
}

static char	*mode_name(t_strategy s)
{
	if (s == SIMPLE)
		return ("Simple");
	if (s == MEDIUM)
		return ("Medium");
	if (s == COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

static char	*complexity(t_strategy s)
{
	if (s == SIMPLE)
		return ("O(n²)");
	if (s == MEDIUM)
		return ("O(n√n)");
	return ("O(n log n)");
}

void	print_strategy(t_flags *f)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(mode_name(f->strategy), 2);
	write(2, " / ", 3);
	ft_putstr_fd(complexity(f->chosen), 2);
	write(2, "\n", 1);
}
