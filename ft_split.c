/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalroyei <oalroyei@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 11:36:13 by oalroyei          #+#    #+#             */
/*   Updated: 2026/10/12 16:11:39 by oalroyei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	word_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			while (*s != c && *s)
				s++;
			count++;
		}
	}
	return (count);
}

static void	*free_strings(char **new, size_t i)
{
	while (i > 0)
		free(new[--i]);
	free(new);
	return (NULL);
}

static char	**fill_strings(char **new, char const *s, char c)
{
	size_t	i;
	size_t	length;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		length = 0;
		while (s[length] && s[length] != c)
			length++;
		if (length > 0)
		{
			new[i] = ft_substr(s, 0, length);
			if (!new[i])
				return (free_strings(new, i));
			i++;
		}
		s += length;
	}
	new[i] = NULL;
	return (new);
}

char	**ft_split(char const *s, char c)
{
	char	**new;

	if (s == NULL)
		return (NULL);
	new = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!new)
		return (NULL);
	return (fill_strings(new, s, c));
}
