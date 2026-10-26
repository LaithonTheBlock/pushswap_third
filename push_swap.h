/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalroyei <oalroyei@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:06:52 by oalroyei          #+#    #+#             */
/*   Updated: 2026/10/26 20:37:28 by oalroyei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct stack
{
	int				value;
	int				current;
	struct stack	*next;
}	t_stack;

typedef struct flags
{
	int	strategy;
	int	bench_mode;

	strategy = 0;
	bench = 0;
}

char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
int		is_valid_number(char *str);
int		is_int_range(long n);
int		stack_size(t_stack *stack);
int		has_duplicates(int *arr, int size);
int		count_tokens(char **tab);
int		count_numbers(int argc, char **argv);
int		fill_tokens(int *arr, char **tab, int *k);
int		find_position(t_stack *stack_a);
int		*parse_args(int argc, char **argv, int *size);
t_stack	*stack_new(int value);
t_stack	*stack_last(t_stack *stack);
t_stack	*find_highest(t_stack *stack_a);
t_stack	*find_lowest(t_stack *stack_a);
void	free_split(char **tab);
void	stack_add_back(t_stack **stack, t_stack *new);
void	stack_free(t_stack **stack);
void	sa(t_stack *stack_a, int *counter);
void	sb(t_stack *stack_b, int *counter);
void	ss(t_stack *stack_a, t_stack *stack_b, int *counter);
void	pa(t_stack **stack_a, t_stack **stack_b, int *counter);
void	pb(t_stack **stack_a, t_stack **stack_b, int *counter);
void	ra(t_stack **stack_a, int *counter);
void	rb(t_stack **stack_b, int *counter);
void	rr(t_stack **stack_a, t_stack **stack_b, int *counter);
void	rra(t_stack **stack_a, int *counter);
void	rrb(t_stack **stack_b, int *counter);
void	rrr(t_stack **stack_a, t_stack **stack_b, int *counter);
void	tiny_sort(t_stack **a, int *counter);
void	index_stack(t_stack *a);
void	selection_sort(t_stack **a, t_stack **b, int *counter);
void	radix_sort(t_stack **a, t_stack **b, int *counter);
void	chunk_sort(t_stack **a, t_stack **b, int *counter);
bool	stack_sorted(t_stack *stack);
long	ft_atol(char *str);
size_t	ft_strlen(const char *s);
double	disorder(t_stack *stack);

#endif
