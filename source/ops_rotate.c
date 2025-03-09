/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:07:12 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/09 23:07:13 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list **stack_a)
{
	t_list	*stack_top;
	t_list	*stack_bottom;
	t_list	*temp;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	stack_top = *stack_a;
	stack_bottom = ft_lstlast(*stack_a);
	temp = stack_top->next;
	stack_bottom->next = stack_top;
	stack_top->next = NULL;
	*stack_a = temp;
	ft_printf("ra\n");
	return ;
}

void	ft_rb(t_list **stack_b)
{
	t_list	*stack_top;
	t_list	*stack_bottom;
	t_list	*temp;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	stack_top = *stack_b;
	stack_bottom = ft_lstlast(*stack_b);
	temp = stack_top->next;
	stack_bottom->next = stack_top;
	stack_top->next = NULL;
	*stack_b = temp;
	ft_printf("rb\n");
	return ;
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*stack_top;
	t_list	*stack_bottom;
	t_list	*temp;

	if (!stack_a || !*stack_a || !(*stack_a)->next
		||!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	stack_top = *stack_a;
	stack_bottom = ft_lstlast(*stack_a);
	temp = stack_top->next;
	stack_bottom->next = stack_top;
	stack_top->next = NULL;
	*stack_a = temp;
	stack_top = *stack_b;
	stack_bottom = ft_lstlast(*stack_b);
	temp = stack_top->next;
	stack_bottom->next = stack_top;
	stack_top->next = NULL;
	*stack_b = temp;
	ft_printf("rr\n");
	return ;
}
