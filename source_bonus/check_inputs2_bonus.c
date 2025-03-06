/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_outputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:37:19 by marvin            #+#    #+#             */
/*   Updated: 2025/03/04 13:37:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	ft_check_instructions_utils(t_list **a, t_list **b, char *inst)
{
	if (!ft_strncmp(inst, "pa\n", 3))
		ft_pa(a, b);
	else if (!ft_strncmp(inst, "pb\n", 3))
		ft_pb(a, b);
	else if (!ft_strncmp(inst, "sa\n", 3))
		ft_sa(a);
	else if (!ft_strncmp(inst, "sb\n", 3))
		ft_sb(b);
	else if (!ft_strncmp(inst, "ss\n", 3))
		ft_ss(a, b);
	else if (!ft_strncmp(inst, "ra\n", 3))
		ft_ra(a);
	else if (!ft_strncmp(inst, "rb\n", 3))
		ft_rb(b);
	else if (!ft_strncmp(inst, "rr\n", 3))
		ft_rr(a, b);
	else if (!ft_strncmp(inst, "rra\n", 4))
		ft_rra(a);
	else if (!ft_strncmp(inst, "rrb\n", 4))
		ft_rrb(b);
	else if (!ft_strncmp(inst, "rrr\n", 4))
		ft_rrr(a, b);
	else
		return (0);
	return (1);
}

int	ft_check_instructions(t_list **stack_a, t_list **stack_b)
{
	char	*instruction;

	instruction = get_next_line(0);
	while (instruction != NULL)
	{
		if (!ft_check_instructions_utils(stack_a, stack_b, instruction))
			return (free(instruction), 0);
		free(instruction);
		instruction = get_next_line(0);
	}
	return (1);
}
