/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnazzal <lnazzal@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:36:52 by lnazzal           #+#    #+#             */
/*   Updated: 2026/10/29 19:13:47 by lnazzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*build_stack(int *arr, int size)
{
	t_stack	*a;
	t_stack	*node;
	int		i;

	a = NULL;
	i = 0;
	while (i < size)
	{
		node = stack_new(arr[i]);
		if (!node)
		{
			stack_free(&a);
			return (NULL);
		}
		node->w = 1;
		stack_add_back(&a, node);
		i++;
	}
	return (a);
}

static void	init_count(t_count *c)
{
	int	*p;
	int	i;

	p = (int *)c;
	i = 0;
	while (i < 12)
	{
		p[i] = 0;
		i++;
	}
}

static int	run(int *arr, int size, t_flags *f, t_count *c)
{
	t_stack	*a;
	t_stack	*b;
	double	d;

	a = build_stack(arr, size);
	free(arr);
	if (!a)
		return (write(2, "Error\n", 6), 1);
	b = NULL;
	d = disorder(a);
	f->strategy = choose_strategy(&a, f, d);
	f->chosen = choose_strategy(&a, f, d);
	if (!stack_sorted(a))
	{
		index_stack(a);
		sort_stack(&a, &b, c, f);
	}
	if (f->bench)
		print_bench(f, c, d);
	stack_free(&a);
	stack_free(&b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_flags	f;
	t_count	c;
	int		*arr;
	int		size;
	int		n;

	if (argc < 2)
		return (0);
	n = parse_flags(argc, argv, &f);
	if (n < 2)
		return (0);
	arr = parse_args(n, argv, &size);
	if (!arr)
		return (write(2, "Error\n", 6), 1);
	init_count(&c);
	return (run(arr, size, &f, &c));
}
