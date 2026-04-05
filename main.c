/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-had <abel-had@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:35:12 by abel-had          #+#    #+#             */
/*   Updated: 2025/01/18 14:13:08 by abel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initialize_stacks(t_list **stack_a, t_list **stack_b)
{
	*stack_a = NULL;
	*stack_b = NULL;
}

static void	process_stacks(t_list **stack_a, t_list **stack_b)
{
	if (stack_size(*stack_a) < 2)
		return ;
	if (stack_size(*stack_a) == 2 && !ft_is_ascending(stack_a))
		swap(stack_a, "sa");
	else if (stack_size(*stack_a) == 3 && !ft_is_ascending(stack_a))
		sort_3(stack_a);
	else if (stack_size(*stack_a) == 4 && !ft_is_ascending(stack_a))
		sort_4(stack_a, stack_b);
	else if (stack_size(*stack_a) == 5 && !ft_is_ascending(stack_a))
		sort_5(stack_a, stack_a);
	else if (stack_size(*stack_a) > 5 && !ft_is_ascending(stack_a))
		ft_push_swap(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**bib;
	size_t	i;

	if (ac < 2)
		return (0);
	initialize_stacks(&stack_a, &stack_b);
	bib = handling_arg(ac, av);
	i = 0;
	while (bib[i] != NULL)
		i++;
	check_input(i, bib);
	stack_a = ft_change_input(i, bib);
	ft_free(bib, i);
	indexing(&stack_a);
	process_stacks(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
