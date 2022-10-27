/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:46:24 by sciftci           #+#    #+#             */
/*   Updated: 2022/10/27 22:12:10 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl/get_next_line.h"
#include "push_swap.h"

static int	is_valid_cmd(char *cmd)
{
	if (!cmd)
		return (1);
	if (ft_strlen(cmd) == 4)
	{
		if (ft_strncmp("rrr", cmd, 3) == 0 || ft_strncmp("rra", cmd, 3) == 0
			|| ft_strncmp("rrb", cmd, 3) == 0)
			return (1);
	}
	else if (ft_strlen(cmd) == 3)
	{
		if (ft_strncmp("rr", cmd, 2) == 0 || ft_strncmp("ra", cmd, 2) == 0
			|| ft_strncmp("rb", cmd, 2) == 0 || ft_strncmp("ss", cmd, 2) == 0
			|| ft_strncmp("sa", cmd, 2) == 0 || ft_strncmp("sb", cmd, 2) == 0
			|| ft_strncmp("pa", cmd, 2) == 0 || ft_strncmp("pb", cmd, 2) == 0)
			return (1);
	}
	return (0);
}

static void	execute_cmd(t_stack **stack_a, t_stack **stack_b, char *cmd)
{
	if (cmd == NULL)
		return ;
	if (cmd[2] == 'r')
		rev_rotate(stack_a, stack_b, NULL, 1);
	else if (cmd[2] == 'a')
		rev_rotate(stack_a, NULL, NULL, 0);
	else if (cmd[2] == 'b')
		rev_rotate(stack_b, NULL, NULL, 0);
	else if (cmd[1] == 'r')
		rotate(stack_a, stack_b, NULL, 1);
	else if (cmd[0] == 'r' && cmd[1] == 'a')
		rotate(stack_a, NULL, NULL, 0);
	else if (cmd[0] == 'r' && cmd[1] == 'b')
		rotate(stack_b, NULL, NULL, 0);
	else if (cmd[1] == 's')
		swap(stack_a, stack_b, NULL, 1);
	else if (cmd[0] == 's' && cmd[1] == 'a')
		swap(stack_a, NULL, NULL, 0);
	else if (cmd[0] == 's' && cmd[1] == 'b')
		swap(stack_b, NULL, NULL, 0);
	else if (cmd[1] == 'a')
		push(stack_b, stack_a, NULL);
	else if (cmd[1] == 'b')
		push(stack_a, stack_b, NULL);
}

static void	wait_for_input(t_stack **stack_a, t_stack **stack_b)
{
	char	*inst;

	while (1)
	{
		inst = get_next_line(STDIN_FILENO);
		if (!inst && !(is_sorted(*stack_a) && get_stack_size(*stack_b) == 0))
		{
			ft_putstr("KO\n");
			break ;
		}
		else if (!is_valid_cmd(inst))
			exit_error(stack_a, stack_b);
		execute_cmd(stack_a, stack_b, inst);
		if (!inst && is_sorted(*stack_a) && get_stack_size(*stack_b) == 0)
		{
			ft_putstr("OK\n");
			break ;
		}
		free(inst);
	}
}

static t_stack	*parse_fill_a(int ac, char **av)
{
	t_stack	*stack_a;
	char	**nums;

	if (ac == 2)
	{
		nums = ft_split(av[1], ' ');
		ac = count_words(av[1], ' ');
		if (!is_valid_input(nums))
			exit_error(NULL, NULL);
		stack_a = fill_stack_a(ac, nums);
		while (--ac >= 0)
			free(nums[ac]);
		free(nums);
	}
	else
	{
		if (!is_valid_input(av + 1))
			exit_error(NULL, NULL);
		stack_a = fill_stack_a(ac - 1, av + 1);
	}
	return (stack_a);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	stack_a = parse_fill_a(ac, av);
	stack_b = NULL;
	wait_for_input(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
