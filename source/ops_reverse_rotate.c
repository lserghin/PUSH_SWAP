/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:07:08 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/09 23:07:09 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_list **stack_a)
{
	t_list	*stack_top;
	t_list	*stack_bottom;
	t_list	*temp;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	stack_top = *stack_a;
	stack_bottom = ft_lstlast(*stack_a);
	temp = stack_top;
	while (temp->next->next)
		temp = temp->next;
	stack_bottom->next = stack_top;
	temp->next = NULL;
	*stack_a = stack_bottom;
	ft_printf("rra\n");
	return ;
}

void	ft_rrb(t_list **stack_b)
{
	t_list	*stack_top;
	t_list	*stack_bottom;
	t_list	*temp;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	stack_top = *stack_b;
	stack_bottom = ft_lstlast(*stack_b);
	temp = stack_top;
	while (temp->next->next)
		temp = temp->next;
	stack_bottom->next = stack_top;
	temp->next = NULL;
	*stack_b = stack_bottom;
	ft_printf("rrb\n");
	return ;
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*stack_top;
	t_list	*stack_bottom;
	t_list	*temp;

	if (!stack_a || !*stack_a || !(*stack_a)->next
		|| !stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	stack_top = *stack_a;
	stack_bottom = ft_lstlast(*stack_a);
	temp = stack_top;
	while (temp->next->next)
		temp = temp->next;
	stack_bottom->next = stack_top;
	temp->next = NULL;
	*stack_a = stack_bottom;
	stack_top = *stack_b;
	stack_bottom = ft_lstlast(*stack_b);
	temp = stack_top;
	while (temp->next->next)
		temp = temp->next;
	stack_bottom->next = stack_top;
	temp->next = NULL;
	*stack_b = stack_bottom;
	ft_printf("rrr\n");
	return ;
}
