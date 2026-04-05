/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-had <abel-had@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:16:57 by abel-had          #+#    #+#             */
/*   Updated: 2025/01/17 18:43:03 by abel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_list **stacka)
{
	t_list	*current;
	t_list	*temp;
	int		index;

	current = *stacka;
	while (current)
	{
		index = 0;
		current->index = 0;
		temp = *stacka;
		while (temp)
		{
			if (current->content > temp->content)
				index++;
			temp = temp->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	stack_size(t_list *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	ft_is_ascending(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp && temp->next)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	free_stack(t_list **stack)
{
	t_list	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
