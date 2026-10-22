/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalroyei <oalroyei@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 20:24:56 by oalroyei          #+#    #+#             */
/*   Updated: 2026/10/19 22:35:15 by lnazzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*head;
	int		*numbers;
	int		size;
	int		i;

	if (argc > 1)
	{
		numbers = parse_args(argc, argv, &size);
		if (!numbers)
		{
			printf("fuck duplicates");
			return (0);
		}
		head = stack_new(numbers[0]);
		if (!head)
			return (0);
		i = 1;
		while (i < size)
		{
			stack_add_back(&head, stack_new(numbers[i]));
			i++;
		}
		free(numbers);
		stack_free(&head);
	}
	return (0);
}
