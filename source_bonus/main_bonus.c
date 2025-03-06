/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:36:16 by marvin            #+#    #+#             */
/*   Updated: 2025/03/04 13:36:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ft_exit_with_error(char *message, t_list *stack, char **splited)
{
	t_list	*temp;
	char	**tmp;

	ft_putstr_fd(message, 2);
	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	if (splited)
	{
		tmp = splited;
		while (*tmp)
			free(*tmp++);
		free(splited);
	}
	exit(1);
	return ;
}

static int	ft_init_stack_a_utils(t_list **stack_a, char *splited_ptr)
{
	long	data;

	if (!ft_check_if_digits(splited_ptr))
		return (0);
	data = ft_atol(splited_ptr);
	if (data < INT_MIN || data > INT_MAX)
		return (0);
	if (!ft_check_for_duplicates(*stack_a, (int)data))
		return (0);
	ft_lstadd_back(stack_a, ft_lstnew((int)data));
	return (1);
}

static void	ft_init_stack_a(t_list **stack_a, int argc, char **argv)
{
	char	**splited;
	char	**splited_ptr;
	int		index;

	index = 1;
	while (index < argc)
	{
		splited = ft_split(*(argv + index), ' ');
		if (!splited || !*splited)
			ft_exit_with_error("Error\n", *stack_a, splited);
		splited_ptr = splited;
		while (*splited_ptr)
		{
			if (!ft_init_stack_a_utils(stack_a, *splited_ptr))
				ft_exit_with_error("Error\n", *stack_a, splited);
			splited_ptr++;
		}
		ft_free_splited(splited);
		index++;
	}
	return ;
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac < 2)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	ft_init_stack_a(&stack_a, ac, av);
	if (!ft_check_instructions(&stack_a, &stack_b))
	{
		ft_free_stack(stack_b);
		ft_exit_with_error("Error\n", stack_a, NULL);
	}
	if (ft_check_if_sorted(stack_a) && !stack_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
