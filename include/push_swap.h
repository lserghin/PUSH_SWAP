/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:47:27 by lserghin          #+#    #+#             */
/*   Updated: 2025/02/05 20:47:27 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

int		ft_check_for_duplicates(t_list *stack, int data);
int		ft_check_if_sorted(t_list *stack);
int		ft_check_if_digits(char *str);

void	ft_free_splited(char **splited);
void	ft_free_stack(t_list *stack);

void	ft_sa(t_list **stack_a);
void	ft_sb(t_list **stack_b);
void	ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_a, t_list **stack_b);
void	ft_ra(t_list **stack_a);
void	ft_rb(t_list **stack_b);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_rra(t_list **stack_a);
void	ft_rrb(t_list **stack_b);
void	ft_rrr(t_list **stack_a, t_list **stack_b);

void	ft_final_rotate(t_list **stack_a);
t_list	*ft_find_smallest(t_list *stack);
t_list	*ft_find_biggest(t_list *stack);

void	ft_get_target_node(t_list *stack_a, t_list *stack_b);
void	ft_get_push_cost(t_list *stack_a, t_list *stack_b);
t_list	*ft_get_smallest_cost_node(t_list *stack_b);
void	ft_get_position(t_list *stack);
void	ft_get_index(t_list *stack);

void	ft_push_back_to_a_utils1(t_list **a, t_list **b, t_list *c);
void	ft_push_back_to_a_utils2(t_list **a, t_list **b, t_list *c);
void	ft_push_swap(t_list **stack_a, t_list **stack_b);

#endif
