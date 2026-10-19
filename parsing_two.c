/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalroyei <oalroyei@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 13:05:26 by oalroyei          #+#    #+#             */
/*   Updated: 2026/10/19 21:14:09 by oalroyei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_tokens(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	count_numbers(int argc, char **argv)
{
	char	**tab;
	int		i;
	int		total;

	i = 1;
	total = 0;
	while (i < argc)
	{
		tab = ft_split(argv[i], ' ');
		if (tab == NULL)
			return (-1);
		if (tab[0] == NULL)
		{
			free_split(tab);
			return (-1);
		}
		total += count_tokens(tab);
		free_split(tab);
		i++;
	}
	return (total);
}

int	fill_tokens(int *arr, char **tab, int *k)
{
	long	n;
	long	i;

	i = 0;
	while (tab[i])
	{
		if (!is_valid_number(tab[i]))
			return (0);
		n = ft_atol(tab[i]);
		if (!is_int_range(n))
			return (0);
		arr[*k] = (int)n;
		(*k)++;
		i++;
	}
	return (1);
}

static int	*free_null(char **tab, int *arr)
{
	free_split(tab);
	free(arr);
	return (0);
}

int	*parse_args(int argc, char **argv, int *size)
{
	char	**tab;
	int		*arr;
	int		i;
	int		k;

	*size = count_numbers(argc, argv);
	if (*size == -1)
		return (NULL);
	arr = malloc (*size * sizeof(int));
	if (!arr)
		return (NULL);
	i = 1;
	k = 0;
	while (i < argc)
	{
		tab = ft_split(argv[i], ' ');
		if (!tab || !fill_tokens(arr, tab, &k))
			return (free_null(tab, arr));
		free_split(tab);
		i++;
	}
	if (has_duplicates(arr, *size))
		return (free_null(NULL, arr));
	return (arr);
}
