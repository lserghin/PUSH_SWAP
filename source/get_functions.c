/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 02:09:13 by marvin            #+#    #+#             */
/*   Updated: 2025/03/04 02:09:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_index(t_list *stack)
{
	t_list	*current;
	t_list	*compare;
	int		index;

	current = stack;
	while (current)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (current->value > compare->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
	return ;
}

void	ft_get_position(t_list *stack)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		stack->pos = pos;
		stack = stack->next;
		pos++;
	}
	return ;
}

void	ft_get_target_node(t_list *stack_a, t_list *stack_b)
{
	t_list	*current_a;
	t_list	*target;
	int		best_match;

	while (stack_b)
	{
		current_a = stack_a;
		best_match = INT_MAX;
		while (current_a)
		{
			if (current_a->value > stack_b->value
				&& current_a->value <= best_match)
			{
				best_match = current_a->value;
				target = current_a;
			}
			current_a = current_a->next;
		}
		stack_b->target = target;
		stack_b = stack_b->next;
	}
	return ;
}

void	ft_get_push_cost(t_list *stack_a, t_list *stack_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(stack_a);
	size_b = ft_lstsize(stack_b);
	while (stack_b)
	{
		if (stack_b->pos > size_b / 2)
			stack_b->cost = size_b - stack_b->pos;
		else
			stack_b->cost = stack_b->pos;
		if (stack_b->target->pos <= size_a / 2)
			stack_b->cost += stack_b->target->pos;
		else
			stack_b->cost += size_a - stack_b->target->pos;
		stack_b = stack_b->next;
	}
	return ;
}

t_list	*ft_get_smallest_cost_node(t_list *stack_b)
{
	t_list	*smallest_node;
	int		smallest_cost;

	smallest_node = stack_b;
	smallest_cost = smallest_node->cost;
	while (stack_b)
	{
		if (stack_b->cost < smallest_cost)
		{
			smallest_cost = stack_b->cost;
			smallest_node = stack_b;
		}
		stack_b = stack_b->next;
	}
	return (smallest_node);
}
