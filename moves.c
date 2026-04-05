/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-had <abel-had@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:14:32 by abel-had          #+#    #+#             */
/*   Updated: 2025/01/12 17:10:02 by abel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_list **a, t_list **b)
{
	t_list	*new_node;

	new_node = *a;
	if (!a || !*a)
		error_exit();
	*a = (*a)->next;
	new_node->next = *b;
	*b = new_node;
	ft_printf("pb\n");
}

void	push_a(t_list **b, t_list **a)
{
	t_list	*new_node;

	if (!b)
		error_exit();
	new_node = *b;
	*b = (*b)->next;
	new_node->next = *a;
	*a = new_node;
	ft_printf("pa\n");
}

void	rotate(t_list **stack, char *op)
{
	t_list	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = NULL;
	ft_printf("%s\n", op);
}

void	reverse_rotate(t_list **stack, char *op)
{
	t_list	*second_last;
	t_list	*last;

	second_last = NULL;
	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
	ft_printf("%s\n", op);
}

void	swap(t_list **stack, char *op)
{
	t_list	*first;
	t_list	*second;

	first = *stack;
	second = first->next;
	if (!*stack || !(*stack)->next)
		return ;
	first->next = second->next;
	second->next = first;
	*stack = second;
	ft_printf("%s\n", op);
}
