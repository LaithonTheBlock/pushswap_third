/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalroyei <oalroyei@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 20:24:56 by oalroyei          #+#    #+#             */
/*   Updated: 2026/10/26 20:03:42 by lnazzal          ###   ########.fr       */
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

	if (argc > 1)
	{
		numbers = parse_args(argc, argv, &size);
		if (!numbers)
		{
			printf("Error\n");
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
		index_stack(head);
		size = stack_size(head);
		if (stack_sorted(head));
		else if (size == 2) sa(head);
		else if (size == 3) tiny_sort(&head);
		else if (size <= 5) selection_sort(&head, &stack_b);
		else
			chunk_sort(&head, &stack_b);
		current = head;
		/*while (current)
		{
			printf("%d\n", current->value);
			current = current->next;
		}*/
		if (stack_sorted(head))
			printf("sorted");
		else
			printf("not sorted");
		free(numbers);
		stack_free(&head);
	}
	return (0);
}
