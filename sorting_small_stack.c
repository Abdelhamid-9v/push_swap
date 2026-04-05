/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-had <abel-had@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:21:26 by abel-had          #+#    #+#             */
/*   Updated: 2025/01/17 18:41:56 by abel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ftt_fill(t_list **stack, int a, int b, int c)
{
	if (a > b && b < c && a < c)
		swap(stack, "sa");
	else if (a > b && b > c)
	{
		swap(stack, "sa");
		reverse_rotate(stack, "rra");
	}
	else if (a > b && b < c && a > c)
		rotate(stack, "ra");
	else if (a < b && b > c && a < c)
	{
		swap(stack, "sa");
		rotate(stack, "ra");
	}
	else if (a < b && b > c && a > c)
		reverse_rotate(stack, "rra");
}

void	sort_3(t_list **stack)
{
	int	a;
	int	b;
	int	c;

	if (stack_size(*stack) == 3)
	{
		a = (*stack)->content;
		b = (*stack)->next->content;
		c = (*stack)->next->next->content;
		ftt_fill(stack, a, b, c);
	}
}

void	sort_5(t_list **a, t_list **b)
{
	int	size;

	size = stack_size(*a);
	while (size-- > 3)
	{
		if ((*a)->index <= 1)
			push_b(a, b);
		else if (get_position(a, 0) <= get_position(a, 1))
		{
			while ((*a)->index != 0)
				rotate(a, "ra");
		}
		else
		{
			while ((*a)->index != 1)
				rotate(a, "ra");
		}
	}
	sort_3(a);
	if ((*b)->index < (*b)->next->index)
		swap(b, "sb");
	push_a(b, a);
	push_a(b, a);
}

void	sort_4(t_list **a, t_list **b)
{
	int	size;

	size = stack_size(*a);
	while (size-- > 3)
	{
		if ((*a)->index == 0)
			push_b(a, b);
		else if (get_position(a, 0) == 3)
		{
			reverse_rotate(a, "rra");
			push_b(a, b);
			sort_3(a);
			push_a(b, a);
		}
		else
		{
			while ((*a)->index != 0)
				rotate(a, "ra");
			push_b(a, b);
			sort_3(a);
			push_a(b, a);
		}
	}
}
