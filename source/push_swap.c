/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 02:09:04 by marvin            #+#    #+#             */
/*   Updated: 2025/03/04 02:09:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_small_sort(t_list **stack)
{
	t_list	*biggest;

	if (!stack || !*stack)
		return ;
	biggest = ft_find_biggest(*stack);
	if (*stack == biggest)
		ft_ra(stack);
	else if ((*stack)->next == biggest)
		ft_rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		ft_sa(stack);
	return ;
}

void	ft_push_to_b(t_list **stack_a, t_list **stack_b, int chunk_size)
{
	int (chunk), (pushed), (max_to_push);
	max_to_push = ft_lstsize(*stack_a) - 3;
	chunk = 0;
	while (ft_lstsize(*stack_a) > 3)
	{
		pushed = 0;
		while (pushed < chunk_size && ft_lstsize(*stack_a) > 3)
		{
			if ((*stack_a)->index <= ((chunk + 1) * chunk_size)
				&& (*stack_a)->index < max_to_push)
			{
				ft_pb(stack_a, stack_b);
				pushed++;
				if ((*stack_b)->index < (chunk * chunk_size) + (chunk_size / 2))
					ft_rb(stack_b);
			}
			else
				ft_ra(stack_a);
		}
		chunk++;
	}
	ft_small_sort(stack_a);
	return ;
}

void	ft_push_back_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest_node;

	while (*stack_b)
	{
		ft_get_position(*stack_a);
		ft_get_position(*stack_b);
		ft_get_target_node(*stack_a, *stack_b);
		ft_get_push_cost(*stack_a, *stack_b);
		cheapest_node = ft_get_smallest_cost_node(*stack_b);
		ft_push_back_to_a_utils1(stack_a, stack_b, cheapest_node);
		ft_push_back_to_a_utils2(stack_a, stack_b, cheapest_node);
		ft_pa(stack_a, stack_b);
	}
	ft_last_sort(stack_a);
	return ;
}

void	ft_push_swap(t_list **stack_a, t_list **stack_b)
{
	int	chunk_size;

	if (ft_lstsize(*stack_a) <= 3)
		ft_small_sort(stack_a);
	else
	{
		if (ft_lstsize(*stack_a) <= 100)
			chunk_size = ft_lstsize(*stack_a) / 2;
		else if (ft_lstsize(*stack_a) <= 500)
			chunk_size = ft_lstsize(*stack_a) / 4;
		else
			chunk_size = ft_lstsize(*stack_a) / 8;
		ft_get_index(*stack_a);
		ft_push_to_b(stack_a, stack_b, chunk_size);
		ft_push_back_to_a(stack_a, stack_b);
	}
	return ;
}
