/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalroyei <oalroyei@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:06:52 by oalroyei          #+#    #+#             */
/*   Updated: 2026/10/19 21:23:05 by oalroyei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct stack
{
	int				value;
	int				current;
	struct stack	*next;
}	t_stack;

char	**ft_split(char const *s, char c);
int		is_valid_number(char *str);
int		is_int_range(long n);
long	ft_atol(char *str);
int		has_duplicates(int *arr, int size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
void	free_split(char **tab);
int		count_tokens(char **tab);
char	*ft_strdup(const char *s);
int		count_numbers(int argc, char **argv);
int		fill_tokens(int *arr, char **tab, int *k);
int		*parse_args(int argc, char **argv, int *size);
t_stack	*stack_new(int value);
t_stack	*stack_last(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *new);
void	stack_free(t_stack **stack);
int		stack_size(t_stack *stack);
bool	stack_sorted(t_stack *stack);

#endif
