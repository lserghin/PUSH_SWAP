/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:08:49 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/09 23:08:57 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_check_if_digits(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	ft_check_for_duplicates(t_list *stack, int data)
{
	while (stack)
	{
		if (stack->value == data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_check_if_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_free_splited(char **splited)
{
	char	**free_ptr;

	free_ptr = splited;
	while (*free_ptr)
		free(*free_ptr++);
	free(splited);
	return ;
}

void	ft_free_stack(t_list *stack)
{
	t_list	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
