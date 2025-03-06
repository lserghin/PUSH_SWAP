/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 02:08:58 by marvin            #+#    #+#             */
/*   Updated: 2025/03/04 02:08:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_find_biggest(t_list *stack)
{
	t_list	*biggest;

	biggest = stack;
	while (stack)
	{
		if (stack->value > biggest->value)
			biggest = stack;
		stack = stack->next;
	}
	return (biggest);
}

t_list	*ft_find_smallest(t_list *stack)
{
	t_list	*smallest;

	smallest = stack;
	while (stack)
	{
		if (stack->value < smallest->value)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}

void	ft_push_back_to_a_utils1(t_list **a, t_list **b, t_list *c)
{
	if (c->pos <= ft_lstsize(*b) / 2
		&& c->target->pos <= ft_lstsize(*a) / 2)
	{
		while (*b != c && *a != c->target)
			ft_rr(a, b);
	}
	else if (c->pos > ft_lstsize(*b) / 2
		&& c->target->pos > ft_lstsize(*a) / 2)
	{
		while (*b != c && *a != c->target)
			ft_rrr(a, b);
	}
	return ;
}

void	ft_push_back_to_a_utils2(t_list **a, t_list **b, t_list *c)
{
	if (c->pos <= ft_lstsize(*b) / 2)
	{
		while (*b != c)
			ft_rb(b);
	}
	else
	{
		while (*b != c)
			ft_rrb(b);
	}
	if (c->target->pos <= ft_lstsize(*a) / 2)
	{
		while (*a != c->target)
			ft_ra(a);
	}
	else
	{
		while (*a != c->target)
			ft_rra(a);
	}
	return ;
}

void	ft_final_rotate(t_list **stack_a)
{
	t_list	*smallest;

	smallest = ft_find_smallest(*stack_a);
	if (smallest->pos <= ft_lstsize(*stack_a) / 2)
	{
		while (*stack_a != smallest)
			ft_ra(stack_a);
	}
	else
	{
		while (*stack_a != smallest)
			ft_rra(stack_a);
	}
	return ;
}
