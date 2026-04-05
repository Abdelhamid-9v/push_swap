/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-had <abel-had@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:23:44 by abel-had          #+#    #+#             */
/*   Updated: 2025/01/17 18:32:01 by abel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_bottom(t_list **stack_a, t_list **bottom)
{
	*bottom = *stack_a;
	while ((*bottom)->next)
		*bottom = (*bottom)->next;
}

int	get_position(t_list **stack_b, int target_index)
{
	t_list	*current;
	int		pos;

	current = *stack_b;
	pos = 0;
	while (current && current->index != target_index)
	{
		current = current->next;
		pos++;
	}
	return (pos);
}

static void	push_rotate_optimize(t_list **stack_a, t_list **stack_b,
	t_list **bottom, int max_index)
{
	if (get_position(stack_b, (*stack_a)->index - 1) > stack_size(*stack_b) / 2)
	{
		if ((*bottom)->index < (*stack_b)->index
			|| (*bottom)->index == max_index)
		{
			push_a(stack_b, stack_a);
			rotate(stack_a, "ra");
			get_bottom(stack_a, bottom);
		}
		else if (*stack_b)
			reverse_rotate(stack_b, "rrb");
	}
	else
	{
		if ((*bottom)->index < (*stack_b)->index
			|| (*bottom)->index == max_index)
		{
			push_a(stack_b, stack_a);
			rotate(stack_a, "ra");
			get_bottom(stack_a, bottom);
		}
		else if (*stack_b)
			rotate(stack_b, "rb");
	}
}

void	ft_push_swap(t_list **stack_a, t_list **stack_b)
{
	t_pivots	pivots;

	pivots.size_max = stack_size(*stack_a);
	initialize_pivots(&pivots, stack_a);
	process_stack_a(stack_a, stack_b, &pivots);
	sort_3(stack_a);
	optimize_final_sort(stack_a, stack_b);
}

void	optimize_final_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*bottom;
	int		max_index;

	get_bottom(stack_a, &bottom);
	max_index = bottom->index;
	while (*stack_b)
	{
		while (*stack_b && (*stack_b)->index != (*stack_a)->index - 1)
			push_rotate_optimize(stack_a, stack_b, &bottom, max_index);
		while (*stack_b && (*stack_b)->index == (*stack_a)->index - 1)
			push_a(stack_b, stack_a);
		while (bottom->index == (*stack_a)->index - 1)
		{
			reverse_rotate(stack_a, "rra");
			get_bottom(stack_a, &bottom);
		}
		if (ft_is_ascending(stack_a) && !*stack_b)
			break ;
	}
}
