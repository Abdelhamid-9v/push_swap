/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-had <abel-had@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:27:55 by abel-had          #+#    #+#             */
/*   Updated: 2025/01/17 12:35:32 by abel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_move(t_list **a, t_list **b, char *move)
{
	if (ft_strncmp(move, "sa", 2) == 0 && ft_strlen(move) == 3)
		swap(a, "sa");
	else if (ft_strncmp(move, "sb", 2) == 0 && ft_strlen(move) == 3)
		swap(b, "sb");
	else if (ft_strncmp(move, "pa", 2) == 0 && ft_strlen(move) == 3)
		push_a(b, a);
	else if (ft_strncmp(move, "pb", 2) == 0 && ft_strlen(move) == 3)
		push_b(a, b);
	else if (ft_strncmp(move, "ra", 2) == 0 && ft_strlen(move) == 3)
		rotate (a, "ra");
	else if (ft_strncmp(move, "rb", 2) == 0 && ft_strlen(move) == 3)
		rotate (b, "rb");
	else if (ft_strncmp(move, "rra", 3) == 0 && ft_strlen(move) == 4)
		reverse_rotate(a, "rra");
	else if (ft_strncmp(move, "rrb", 3) == 0 && ft_strlen(move) == 4)
		reverse_rotate(b, "rrb");
	else if (ft_strncmp(move, "rrr", 3) == 0 && ft_strlen(move) == 4)
		ft_rrr(a, b, "rrr");
	else
		return (0);
	return (1);
}

static int	ft_checker(t_list **a, t_list **b)
{
	char	*move;
	int		valid;

	move = get_next_line (0);
	while (move != NULL)
	{
		valid = get_move(a, b, move);
		free(move);
		if (!valid)
			return (0);
		move = get_next_line (0);
	}
	free(move);
	return (1);
}

static int	ft_fill(t_list **a, t_list **b, int ac)
{
	if (!ft_checker(a, b))
	{
		write(2, "Error\n", 6);
		free_stack(a);
		free_stack(b);
		return (1);
	}
	if ((ft_is_ascending(a) && *b == NULL) || ac == 2)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**bib;
	size_t	i;

	stack_b = NULL;
	if (ac < 2)
		return (0);
	bib = handling_arg(ac, av);
	i = 0;
	while (bib[i] != NULL)
		i++;
	check_input(i, bib);
	stack_a = ft_change_input(i, bib);
	ft_free(bib, i);
	indexing(&stack_a);
	if (ft_fill(&stack_a, &stack_b, ac))
		return (1);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
