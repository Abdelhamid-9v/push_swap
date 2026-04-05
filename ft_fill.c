/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-had <abel-had@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:11:45 by abel-had          #+#    #+#             */
/*   Updated: 2025/01/17 18:37:55 by abel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_pivots(t_pivots *pivots, t_list **stack_a)
{
	int	stack_s;

	stack_s = stack_size(*stack_a);
	pivots->last_pivot = -1;
	if (stack_s <= 250)
	{
		pivots->pivot1 = stack_s / 3;
		pivots->pivot2 = stack_s / 6;
	}
	else
	{
		pivots->pivot1 = stack_s / 5;
		pivots->pivot2 = stack_s / 6;
	}
	if (pivots->pivot1 < 1)
		pivots->pivot1 = 1;
	if (pivots->pivot2 < 1)
		pivots->pivot2 = 1;
}

void	process_stack_a(t_list **stack_a, t_list **stack_b, t_pivots *pivots)
{
	while (stack_size(*stack_a) > 3)
	{
		if (((*stack_a)->index) < (pivots->pivot1))
			ft_min_fill(stack_a, stack_b, pivots->last_pivot, pivots->pivot2);
		else
			rotate(stack_a, "ra");
		if (stack_size(*stack_b) == pivots->pivot1)
		{
			pivots->last_pivot = pivots->pivot1;
			if (pivots->size_max <= 250)
				pivots->pivot1 += stack_size(*stack_a) / 3;
			else if (pivots->size_max > 250)
				pivots->pivot1 += stack_size(*stack_a) / 4;
			pivots->pivot2 = (stack_size(*stack_a) / 6) + pivots->last_pivot;
		}
	}
}
