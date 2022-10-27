/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:44:17 by sciftci           #+#    #+#             */
/*   Updated: 2022/10/27 22:04:01 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				order;
	int				index;
	int				target_index;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

/* Initialization */

t_stack				*fill_stack_a(int ac, char **av);
void				assign_order(t_stack *stack_a, int ac);

/* Sorting Algorithms */

void				sort_three(t_stack **stack);
void				sort(t_stack **stack_a, t_stack **stack_b);

/* Index */

int					get_lowest_order_index(t_stack **stack);
void				assign_target_index(t_stack **stack_a, t_stack **stack_b);

/* Cost */

void				get_cost(t_stack **stack_a, t_stack **stack_b);
void				move_cheapest(t_stack **stack_a, t_stack **stack_b);

/* Instructions */

void				rev_rotate(t_stack **stack_a, t_stack **stack_b, char *cmd,
						int flag);
void				rotate(t_stack **stack_a, t_stack **stack_b, char *cmd,
						int flag);
void				swap(t_stack **stack_a, t_stack **stack_b, char *cmd,
						int flag);
void				push(t_stack **src, t_stack **dest, char *cmd);

/* Stack Functions */

t_stack				*get_stack_bottom(t_stack *stack);
t_stack				*get_stack_before_bottom(t_stack *stack);
t_stack				*stack_new(int value);
void				stack_add_bottom(t_stack **stack, t_stack *new);
int					get_stack_size(t_stack *stack);

/* Utils */

int					is_sorted(t_stack *stack);
void				free_stack(t_stack **stack);
long int			ft_atoi(const char *str);
void				ft_putstr(char *str);
int					ft_abs(int nb);
unsigned int		count_words(const char *str, char sep);
char				**ft_split(char const *str, char c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

/* Error */

void				exit_error(t_stack **stack_a, t_stack **stack_b);

/* Input Check */

int					is_valid_input(char **av);

#endif