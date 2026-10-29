/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnazzal <lnazzal@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:34:33 by lnazzal           #+#    #+#             */
/*   Updated: 2026/10/28 17:35:35 by lnazzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	cmp(const char *a, const char *b)
{
	while (*a && *a == *b)
	{
		a++;
		b++;
	}
	return ((unsigned char)*a - (unsigned char)*b);
}

static int	set_flag(char *arg, t_flags *f)
{
	if (!cmp(arg, "--bench"))
		f->bench = 1;
	else if (!cmp(arg, "--simple"))
		f->strategy = SIMPLE;
	else if (!cmp(arg, "--medium"))
		f->strategy = MEDIUM;
	else if (!cmp(arg, "--complex"))
		f->strategy = COMPLEX;
	else if (!cmp(arg, "--adaptive"))
		f->strategy = ADAPTIVE;
	else
		return (0);
	return (1);
}

int	parse_flags(int argc, char **argv, t_flags *f)
{
	int	i;
	int	j;

	f->bench = 0;
	f->strategy = ADAPTIVE;
	i = 1;
	j = 1;
	while (i < argc)
	{
		if (!set_flag(argv[i], f))
		{
			argv[j] = argv[i];
			j++;
		}
		i++;
	}
	return (j);
}
