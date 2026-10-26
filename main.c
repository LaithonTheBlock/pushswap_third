/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalroyei <oalroyei@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 20:24:56 by oalroyei          #+#    #+#             */
/*   Updated: 2026/10/26 18:15:37 by oalroyei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*current;
	t_stack	*head;
	t_stack	*stack_b;
	int		*numbers;
	int		size;
	int		i;
	int		counter;

	if (argc > 1)
	{
		counter = 0;
		numbers = parse_args(argc, argv, &size);
		if (!numbers)
		{
			write(2, "Error\n", 6);
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
		stack_b = NULL;
		selection_sort(&head, &stack_b, &counter);
		current = head;
		if (stack_sorted(head))
			printf("sorted");
		else
			printf("not sorted");
		printf("\n%d", counter);
		free(numbers);
		stack_free(&head);
	}
	return (0);
}
